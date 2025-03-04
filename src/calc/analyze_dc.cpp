#include <vector>
#include <string>
//#include <format>
#include <iostream>
#include <sstream>
#include <Eigen/Dense>
#include "console/myconsole.h"
#include "circuit/circuit.h"
#include "circuit/circuit_node.h"
#include "calc/analyze_entry.h"
#include "calc/analyze_context.h"
#include "global/global.h"
#include "devices/base_device.h"
#include "devices/dynamic_device.h"
#include "devices/nonlinear_device.h"
#include "devices/source_device.h"
#include "calc/analyze_dc.h"
#include "chart/plot_manager.h"
#include "calc/iteration_context.hpp"
#include "chart/print_manager.h"

AnalyzeDC::AnalyzeDC(Circuit* circuit, std::vector<CircuitNode>& nodes, int nodeCount)
    : circuit(circuit), nodes(nodes), nodeCount(nodeCount) {}

void AnalyzeDC::BuildDCMNA(AnalyzeContext* context)
{
    // //console->log(std::format("[SpParser] Start Build DC MNA"));
    context->mat.resize(context->nodeCount, context->nodeCount);
    context->rhs.resize(context->nodeCount, Eigen::NoChange);
    context->mat.fill(0);
    context->rhs.fill(0);
    for (auto& device : circuit->devices) {
        device->appendStampDC(context);
    }
    // //console->log("[SpParser] MNA Matrix (including ground)");
    // oss<<mat<<std::endl;
    // //console->log(oss.str()); oss = std::ostringstream();
    // //console->log("[SpParser] RHS Vector");
    // oss<<rhs<<std::endl;
    // //console->log(oss.str()); oss = std::ostringstream();
}

Eigen::VectorXd& AnalyzeDC::SolveDCSingle(AnalyzeContext* context)
{
    if (!circuit->hasNonlinearDevice)
        return SolveDCOneTime(context);
    for (auto& device : circuit->devices) {
        NonlinearDevice* nd = dynamic_cast<NonlinearDevice*>(device);
        if (nd)
        {
            context->IterContexts[nd->Name] = new std::vector<BaseIterationContext*>();
            context->IterContexts[nd->Name]->push_back(nd->getDefaultIterationContext());
        }
    }
    int cnt = 0;
    while (1)
    {
        cnt++;
        auto& res = SolveDCOneTime(context);
        double eps = 0;
        for (auto& device : circuit->devices) {
            NonlinearDevice* nd = dynamic_cast<NonlinearDevice*>(device);
            if (nd)
            {
                auto lastContext = nd->getLastContext(context);
                context->IterContexts[nd->Name]->push_back(lastContext);
                ////console->log(std::format("[SpParser] IterCurrent: {}", value));
                ////console->log(std::format("[SpParser] IterVoltage: {}", value));

                eps = std::max(eps, nd->checkConvergence(context));
            }
        }
        ////console->log(std::format("[SpParser] Newton iteration counter: {}", cnt));
        for(int i = 0; i < context->nodeCount - 1; i++)
        {
            oss<<context->nodes[i].prefix<<'('<<context->nodes[i].nodeName<<')'<<'\t'<<'='<<'\t'<<res(i);
           // //console->log(oss.str()); oss = std::ostringstream();
        }
        if (cnt > 100)
        {
           // //console->log(std::format("[SpParser] Newton iteration failed to converge"));
            throw std::runtime_error("convergence error");
        }
        if (eps < 1e-6)
        {
            return res;
        }
    }
}

void AnalyzeDC::SolveDC()
{
    AnalyzeContext* context = new AnalyzeContext(nodes, nodeCount);
    std::vector<AnalyzeEntry*> results;
    AnalyzeEntry* entry = NULL;
    if (circuit->command_DC.sweepOptions.size() == 0)
    {
        auto& res = SolveDCSingle(context);
        entry = new AnalyzeEntry();
        entry->result = res;
        results.push_back(entry);
    }
    else
    {
        SweepOption& opt = circuit->command_DC.sweepOptions[0];
        SourceDevice* source = NULL;
        for (auto& device : circuit->devices) {
            if (device->Name == opt.deviceName)
            {
                source = dynamic_cast<SourceDevice*>(device);
            }
        }
        if (!source)
        {
           // //console->log("[SpParser] can not find" + opt.deviceName);
            return;
        }
        if (opt.start - opt.stop > 1e-5)
        {
          //  //console->log("[SpParser] sweep range error!");
            return;
        }
        for(double v = opt.start; v-opt.stop < 1e-5; v += opt.step)
        {
            source->DC_Value = v;
            auto& res = SolveDCSingle(context);
            entry = new AnalyzeEntry();
            entry->result = res;
            entry->sweepEntries.push_back(SweepOptionEntry(opt.deviceName, v));
            results.push_back(entry);
        }
    }

    //console->log("[SpParser] Result:");
    for(auto& entry: results)
    {
        if (entry->sweepEntries.size() > 0)
        {
          //  //console->log(std::format("For {} = {}:", entry->sweepEntries[0].deviceName, entry->sweepEntries[0].value));
        }
        for(int i = 0; i < nodeCount - 1; i++)
        {
            oss<<nodes[i+1].prefix<<'('<<nodes[i+1].nodeName<<')'<<'\t'<<'='<<'\t'<<entry->result(i);
          //  //console->log(oss.str()); oss = std::ostringstream();
        }
    }
    if (circuit->command_PRINTs.size() > 0)
    {
        PrintManager::Print(context->nodeCount - 1, context->nodes, results);
    }

    if (circuit->command_PLOTs.size() > 0)
    {
        PlotManager::Plot(context->nodeCount - 1, context->nodes, results);
    }
    delete context;
}

Eigen::VectorXd& AnalyzeDC::SolveDCOneTime(AnalyzeContext* context)
{
    context->nodes = nodes;
    context->nodeCount = nodeCount;
    BuildDCMNA(context);
    context->ground = context->nodes[0];
    Eigen::MatrixXd mat_ex = context->mat.block(1, 1, context->nodeCount - 1, context->nodeCount - 1);
    Eigen::VectorXd rhs_ex = context->rhs.tail(context->nodeCount - 1);
    context->nodes.erase(context->nodes.begin());

    //console->log("[SpParser] Start Solve DC");
    //console->log("[SpParser] MNA Matrix (excluding ground)");
    oss<<mat_ex<<std::endl;
    //console->log(oss.str()); oss = std::ostringstream();
    
    //console->log("[SpParser] RHS Vector");
    oss<<rhs_ex<<std::endl;
    //console->log(oss.str()); oss = std::ostringstream();

    Eigen::VectorXd* x = new Eigen::VectorXd();
    *x = mat_ex.fullPivLu().solve(rhs_ex);
    context->res = *x;
    return *x;
}