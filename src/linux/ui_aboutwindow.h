/********************************************************************************
** Form generated from reading UI file 'aboutwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTWINDOW_H
#define UI_ABOUTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AboutWindow
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QDialog *AboutWindow)
    {
        if (AboutWindow->objectName().isEmpty())
            AboutWindow->setObjectName(QString::fromUtf8("AboutWindow"));
        AboutWindow->resize(400, 254);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/spice-1.svg"), QSize(), QIcon::Normal, QIcon::Off);
        AboutWindow->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(AboutWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 200, 341, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        label = new QLabel(AboutWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 10, 64, 64));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/spice-1.svg")));
        label->setScaledContents(true);
        label_2 = new QLabel(AboutWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 80, 161, 21));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(AboutWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 100, 281, 16));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(AboutWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(110, 120, 181, 16));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(AboutWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(120, 150, 161, 16));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(AboutWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(130, 170, 141, 16));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(AboutWindow);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 210, 101, 21));

        retranslateUi(AboutWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), AboutWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AboutWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(AboutWindow);
    } // setupUi

    void retranslateUi(QDialog *AboutWindow)
    {
        AboutWindow->setWindowTitle(QApplication::translate("AboutWindow", "About", nullptr));
        label->setText(QString());
        label_2->setText(QApplication::translate("AboutWindow", "SimpleSpice v1.0", nullptr));
        label_3->setText(QApplication::translate("AboutWindow", "MST4307 (2024 Spring) Course Project", nullptr));
        label_4->setText(QApplication::translate("AboutWindow", "\347\256\200\346\230\223\351\233\206\346\210\220\347\224\265\350\267\257\344\273\277\347\234\237\347\250\213\345\272\217", nullptr));
        label_5->setText(QApplication::translate("AboutWindow", "\344\275\234\350\200\205\357\274\232Teruteru", nullptr));
        label_6->setText(QApplication::translate("AboutWindow", "\346\214\207\345\257\274\350\200\201\345\270\210\357\274\232\346\226\275\345\233\275\345\213\207", nullptr));
        label_7->setText(QApplication::translate("AboutWindow", "<html><head/><body><p><a href=\"https://github.com/1357310795/SimpleSpice\"><span style=\" text-decoration: underline; color:#0000ff;\">Github\344\270\273\351\241\265</span></a></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutWindow: public Ui_AboutWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWINDOW_H
