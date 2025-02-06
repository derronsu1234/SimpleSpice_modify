/********************************************************************************
** Form generated from reading UI file 'mychart.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCHART_H
#define UI_MYCHART_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "qchartview.h"

QT_BEGIN_NAMESPACE

class Ui_ChartViewWindow
{
public:
    QGridLayout *gridLayout;
    QChartView *chartView;

    void setupUi(QWidget *ChartViewWindow)
    {
        if (ChartViewWindow->objectName().isEmpty())
            ChartViewWindow->setObjectName(QString::fromUtf8("ChartViewWindow"));
        ChartViewWindow->resize(600, 400);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/spice-1.svg"), QSize(), QIcon::Normal, QIcon::Off);
        ChartViewWindow->setWindowIcon(icon);
        gridLayout = new QGridLayout(ChartViewWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        chartView = new QChartView(ChartViewWindow);
        chartView->setObjectName(QString::fromUtf8("chartView"));

        gridLayout->addWidget(chartView, 0, 0, 1, 1);


        retranslateUi(ChartViewWindow);

        QMetaObject::connectSlotsByName(ChartViewWindow);
    } // setupUi

    void retranslateUi(QWidget *ChartViewWindow)
    {
        ChartViewWindow->setWindowTitle(QApplication::translate("ChartViewWindow", "Chart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChartViewWindow: public Ui_ChartViewWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCHART_H
