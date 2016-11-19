/********************************************************************************
** Form generated from reading UI file 'Register.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <MyLineEdit.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QPushButton *btn_register;
    MyLineEdit *le_coder;
    MyLineEdit *le_passwd2;
    MyLineEdit *le_passwd;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    MyLineEdit *le_accout;
    QLabel *label;
    QLabel *lab_back;
    QLabel *lab_acc;
    QLabel *lab_pwd;
    QLabel *lab_pwd2;
    QLabel *lab_coder;
    QPushButton *pushButton;
    QLabel *label_8;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *cLayout;
    QLabel *label_5;
    QCheckBox *ch_Box;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(764, 477);
        btn_register = new QPushButton(Register);
        btn_register->setObjectName(QStringLiteral("btn_register"));
        btn_register->setGeometry(QRect(200, 390, 161, 41));
        btn_register->setStyleSheet(QLatin1String("font: 75 italic 16pt \"JasmineUPC\";\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));\n"
"font: 75 12pt \"Aharoni\";"));
        le_coder = new MyLineEdit(Register);
        le_coder->setObjectName(QStringLiteral("le_coder"));
        le_coder->setGeometry(QRect(160, 240, 271, 31));
        le_coder->setStyleSheet(QStringLiteral("font: 75 11pt \"Terminal\";"));
        le_passwd2 = new MyLineEdit(Register);
        le_passwd2->setObjectName(QStringLiteral("le_passwd2"));
        le_passwd2->setGeometry(QRect(160, 189, 271, 31));
        le_passwd2->setStyleSheet(QStringLiteral("font: 75 11pt \"Terminal\";"));
        le_passwd = new MyLineEdit(Register);
        le_passwd->setObjectName(QStringLiteral("le_passwd"));
        le_passwd->setGeometry(QRect(160, 140, 271, 31));
        le_passwd->setStyleSheet(QStringLiteral("font: 75 11pt \"Terminal\";"));
        label_2 = new QLabel(Register);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 140, 71, 31));
        label_3 = new QLabel(Register);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 190, 99, 31));
        label_4 = new QLabel(Register);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 240, 51, 31));
        le_accout = new MyLineEdit(Register);
        le_accout->setObjectName(QStringLiteral("le_accout"));
        le_accout->setGeometry(QRect(160, 90, 271, 31));
        le_accout->setStyleSheet(QStringLiteral("font: 75 11pt \"Terminal\";"));
        label = new QLabel(Register);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 90, 61, 31));
        lab_back = new QLabel(Register);
        lab_back->setObjectName(QStringLiteral("lab_back"));
        lab_back->setGeometry(QRect(0, 0, 771, 481));
        lab_back->setPixmap(QPixmap(QString::fromUtf8(":/image/\346\263\250\345\206\214\347\225\214\351\235\242.jpg")));
        lab_back->setScaledContents(true);
        lab_acc = new QLabel(Register);
        lab_acc->setObjectName(QStringLiteral("lab_acc"));
        lab_acc->setGeometry(QRect(460, 90, 261, 31));
        lab_acc->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"font: 75 9pt \"Aharoni\";\n"
"font: 75 11pt \"Aharoni\";"));
        lab_pwd = new QLabel(Register);
        lab_pwd->setObjectName(QStringLiteral("lab_pwd"));
        lab_pwd->setGeometry(QRect(460, 140, 261, 31));
        lab_pwd->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"font: 75 9pt \"Aharoni\";\n"
"font: 75 11pt \"Aharoni\";"));
        lab_pwd2 = new QLabel(Register);
        lab_pwd2->setObjectName(QStringLiteral("lab_pwd2"));
        lab_pwd2->setGeometry(QRect(460, 190, 261, 31));
        lab_pwd2->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"font: 75 9pt \"Aharoni\";\n"
"font: 75 11pt \"Aharoni\";"));
        lab_coder = new QLabel(Register);
        lab_coder->setObjectName(QStringLiteral("lab_coder"));
        lab_coder->setGeometry(QRect(460, 240, 271, 31));
        lab_coder->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"font: 75 9pt \"Aharoni\";\n"
"font: 75 11pt \"Aharoni\";"));
        pushButton = new QPushButton(Register);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(400, 300, 71, 31));
        pushButton->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));"));
        label_8 = new QLabel(Register);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(0, 0, 211, 71));
        label_8->setStyleSheet(QLatin1String("color: rgb(0, 0, 255);\n"
"font: 75 9pt \"Aharoni\";\n"
"color: rgb(85, 0, 0);\n"
"font: 75 16pt \"Aharoni\";"));
        verticalLayoutWidget = new QWidget(Register);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(210, 300, 141, 41));
        cLayout = new QVBoxLayout(verticalLayoutWidget);
        cLayout->setObjectName(QStringLiteral("cLayout"));
        cLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(Register);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 270, 81, 16));
        ch_Box = new QCheckBox(Register);
        ch_Box->setObjectName(QStringLiteral("ch_Box"));
        ch_Box->setGeometry(QRect(350, 360, 71, 16));
        lab_back->raise();
        btn_register->raise();
        le_coder->raise();
        le_passwd2->raise();
        le_passwd->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        le_accout->raise();
        label->raise();
        lab_acc->raise();
        lab_pwd->raise();
        lab_pwd2->raise();
        lab_coder->raise();
        pushButton->raise();
        label_8->raise();
        verticalLayoutWidget->raise();
        label_5->raise();
        ch_Box->raise();

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Dialog", 0));
        btn_register->setText(QApplication::translate("Register", "\345\220\214\346\204\217\345\271\266\346\263\250\345\206\214\350\264\246\345\217\267", 0));
        label_2->setText(QApplication::translate("Register", "\345\257\206\347\240\201\357\274\232", 0));
        label_3->setText(QApplication::translate("Register", "\351\207\215\345\244\215\350\276\223\345\205\245\345\257\206\347\240\201\357\274\232", 0));
        label_4->setText(QApplication::translate("Register", "\351\252\214\350\257\201\347\240\201\357\274\232", 0));
        label->setText(QApplication::translate("Register", "\350\264\246\345\217\267\357\274\232", 0));
        lab_back->setText(QString());
        lab_acc->setText(QString());
        lab_pwd->setText(QString());
        lab_pwd2->setText(QString());
        lab_coder->setText(QString());
        pushButton->setText(QApplication::translate("Register", "\346\215\242\344\270\200\345\274\240", 0));
        label_8->setText(QApplication::translate("Register", "\345\244\251\350\235\216\347\233\264\346\222\255\345\271\263\345\217\260\350\264\246\345\217\267\346\263\250\345\206\214", 0));
        label_5->setText(QApplication::translate("Register", "\357\274\210\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231\357\274\211", 0));
        ch_Box->setText(QApplication::translate("Register", "\345\220\214\346\204\217\346\235\241\346\254\276", 0));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
