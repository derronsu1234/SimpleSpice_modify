#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <Eigen/Dense>
#include <unordered_map>
#include "circuit/circuit_node.h"
#include "cmds/ac_dc.hpp"
#include "calc/iteration_context.hpp"

class AnalyzeContext {
public:
    Eigen::MatrixXd mat;
    Eigen::VectorXd rhs;
    Eigen::VectorXd res;
    std::vector<CircuitNode> nodes;

    Eigen::MatrixXcd matc;
    Eigen::VectorXcd rhsc;
    Eigen::VectorXcd resc;

    std::unordered_map<std::string, std::vector<double>*> lastVoltages;
    std::unordered_map<std::string, std::vector<double>*> lastCurrents;

    std::unordered_map<std::string, std::vector<BaseIterationContext*>*> IterContexts;

    CircuitNode ground;
    int nodeCount;

    double ts;
    double interval;

    double freq;

    AnalyzeContext();
    AnalyzeContext(std::vector<CircuitNode> &nodes, int& nodeCount);
    ~AnalyzeContext();
};
