/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QLineEdit *le_passwd;
    QLabel *la_account;
    QLabel *la_passwd;
    QPushButton *btn_login;
    QPushButton *btn_register;
    QLabel *label;
    QComboBox *com_accout;
    QLabel *lab_warning;
    QLabel *label_2;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(312, 542);
        le_passwd = new QLineEdit(MainWindow);
        le_passwd->setObjectName(QStringLiteral("le_passwd"));
        le_passwd->setGeometry(QRect(70, 380, 191, 31));
        le_passwd->setStyleSheet(QStringLiteral("font: 75 11pt \"Terminal\";"));
        la_account = new QLabel(MainWindow);
        la_account->setObjectName(QStringLiteral("la_account"));
        la_account->setGeometry(QRect(26, 310, 31, 31));
        la_passwd = new QLabel(MainWindow);
        la_passwd->setObjectName(QStringLiteral("la_passwd"));
        la_passwd->setGeometry(QRect(26, 380, 31, 31));
        btn_login = new QPushButton(MainWindow);
        btn_login->setObjectName(QStringLiteral("btn_login"));
        btn_login->setGeometry(QRect(96, 450, 141, 31));
        btn_login->setStyleSheet(QLatin1String("background-color: rgb(0, 170, 255);\n"
"color: rgb(255, 85, 0);"));
        btn_register = new QPushButton(MainWindow);
        btn_register->setObjectName(QStringLiteral("btn_register"));
        btn_register->setGeometry(QRect(130, 500, 71, 23));
        btn_register->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        label = new QLabel(MainWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 341, 541));
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/\347\231\273\345\275\225\347\225\214\351\235\242.jpg")));
        label->setScaledContents(true);
        com_accout = new QComboBox(MainWindow);
        com_accout->setObjectName(QStringLiteral("com_accout"));
        com_accout->setGeometry(QRect(70, 310, 191, 31));
        com_accout->setStyleSheet(QStringLiteral("font: 75 11pt \"Terminal\";"));
        com_accout->setEditable(true);
        lab_warning = new QLabel(MainWindow);
        lab_warning->setObjectName(QStringLiteral("lab_warning"));
        lab_warning->setGeometry(QRect(90, 430, 171, 16));
        lab_warning->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        label_2 = new QLabel(MainWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 500, 21, 21));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/image/\344\270\273\346\222\255\346\240\207\345\277\227.png")));
        label_2->setScaledContents(true);
        label->raise();
        le_passwd->raise();
        la_account->raise();
        la_passwd->raise();
        btn_login->raise();
        btn_register->raise();
        com_accout->raise();
        lab_warning->raise();
        label_2->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        la_account->setText(QApplication::translate("MainWindow", "\350\264\246\345\217\267", 0));
        la_passwd->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201", 0));
        btn_login->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", 0));
        btn_register->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214\350\264\246\345\217\267", 0));
        label->setText(QString());
        lab_warning->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
