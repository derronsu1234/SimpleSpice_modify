/********************************************************************************
** Form generated from reading UI file 'mainwindow2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW2_H
#define UI_MAINWINDOW2_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow2
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionCut;
    QAction *actionDelete;
    QAction *actionFind_Replace;
    QAction *actionParse;
    QAction *actionDebug;
    QAction *actionAbout;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuAbout;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout_2;
    QPlainTextEdit *consoleText;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_2;
    QGridLayout *gridLayout_3;
    QTreeWidget *treeWidget;

    void setupUi(QMainWindow *MainWindow2)
    {
        if (MainWindow2->objectName().isEmpty())
            MainWindow2->setObjectName(QString::fromUtf8("MainWindow2"));
        MainWindow2->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/spice-1.svg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow2->setWindowIcon(icon);
        actionNew = new QAction(MainWindow2);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/newfile.svg"), QSize(), QIcon::Normal, QIcon::On);
        actionNew->setIcon(icon1);
        actionOpen = new QAction(MainWindow2);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/open.svg"), QSize(), QIcon::Normal, QIcon::On);
        actionOpen->setIcon(icon2);
        actionSave = new QAction(MainWindow2);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/save.svg"), QSize(), QIcon::Normal, QIcon::On);
        actionSave->setIcon(icon3);
        actionSave_As = new QAction(MainWindow2);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/saveas.svg"), QSize(), QIcon::Normal, QIcon::On);
        actionSave_As->setIcon(icon4);
        actionCopy = new QAction(MainWindow2);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionPaste = new QAction(MainWindow2);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionCut = new QAction(MainWindow2);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        actionDelete = new QAction(MainWindow2);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        actionFind_Replace = new QAction(MainWindow2);
        actionFind_Replace->setObjectName(QString::fromUtf8("actionFind_Replace"));
        actionParse = new QAction(MainWindow2);
        actionParse->setObjectName(QString::fromUtf8("actionParse"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/chip.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionParse->setIcon(icon5);
        actionDebug = new QAction(MainWindow2);
        actionDebug->setObjectName(QString::fromUtf8("actionDebug"));
        actionDebug->setEnabled(false);
        actionDebug->setVisible(false);
        actionAbout = new QAction(MainWindow2);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/about.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon6);
        centralwidget = new QWidget(MainWindow2);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QFont font;
        font.setPointSize(16);
        textEdit->setFont(font);

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);

        MainWindow2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow2);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        MainWindow2->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow2);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow2->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow2);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow2->addToolBar(Qt::TopToolBarArea, toolBar);
        dockWidget = new QDockWidget(MainWindow2);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setMinimumSize(QSize(100, 107));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        gridLayout_2 = new QGridLayout(dockWidgetContents);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        consoleText = new QPlainTextEdit(dockWidgetContents);
        consoleText->setObjectName(QString::fromUtf8("consoleText"));
        consoleText->setFont(font);

        gridLayout_2->addWidget(consoleText, 0, 0, 1, 1);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow2->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget);
        dockWidget_2 = new QDockWidget(MainWindow2);
        dockWidget_2->setObjectName(QString::fromUtf8("dockWidget_2"));
        dockWidget_2->setMinimumSize(QSize(88, 107));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        gridLayout_3 = new QGridLayout(dockWidgetContents_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        treeWidget = new QTreeWidget(dockWidgetContents_2);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("Components"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        gridLayout_3->addWidget(treeWidget, 0, 0, 1, 1);

        dockWidget_2->setWidget(dockWidgetContents_2);
        MainWindow2->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_2);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionDelete);
        menuEdit->addSeparator();
        menuEdit->addAction(actionFind_Replace);
        menuAbout->addAction(actionAbout);
        toolBar->addAction(actionNew);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave);
        toolBar->addAction(actionSave_As);
        toolBar->addSeparator();
        toolBar->addAction(actionParse);
        toolBar->addAction(actionDebug);
        toolBar->addAction(actionAbout);

        retranslateUi(MainWindow2);

        QMetaObject::connectSlotsByName(MainWindow2);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow2)
    {
        MainWindow2->setWindowTitle(QApplication::translate("MainWindow2", "SimpleSpice", nullptr));
        actionNew->setText(QApplication::translate("MainWindow2", "New", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow2", "Open", nullptr));
        actionSave->setText(QApplication::translate("MainWindow2", "Save", nullptr));
        actionSave_As->setText(QApplication::translate("MainWindow2", "Save As", nullptr));
        actionCopy->setText(QApplication::translate("MainWindow2", "Copy", nullptr));
        actionPaste->setText(QApplication::translate("MainWindow2", "Paste", nullptr));
        actionCut->setText(QApplication::translate("MainWindow2", "Cut", nullptr));
        actionDelete->setText(QApplication::translate("MainWindow2", "Delete", nullptr));
        actionFind_Replace->setText(QApplication::translate("MainWindow2", "Find/Replace", nullptr));
        actionParse->setText(QApplication::translate("MainWindow2", "Parse", nullptr));
        actionDebug->setText(QApplication::translate("MainWindow2", "Debug", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow2", "About", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow2", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow2", "Edit", nullptr));
        menuAbout->setTitle(QApplication::translate("MainWindow2", "About", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow2", "toolBar", nullptr));
        dockWidget->setWindowTitle(QApplication::translate("MainWindow2", "Console", nullptr));
        dockWidget_2->setWindowTitle(QApplication::translate("MainWindow2", "Circuit Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow2: public Ui_MainWindow2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW2_H
