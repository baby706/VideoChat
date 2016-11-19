/********************************************************************************
** Form generated from reading UI file 'LiveWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIVEWINDOW_H
#define UI_LIVEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LiveWindow
{
public:
    QLabel *la_head;
    QTextEdit *te_show;
    QLabel *la_roomName;
    QLabel *la_hostName;
    QLabel *label;
    QLabel *la_flag;
    QLineEdit *le_send;
    QPushButton *btn_send;
    QLabel *lab_cameraFlag;
    QLabel *lab_show_host;
    QCheckBox *cbox_camera;
    QLabel *lab_back;
    QCheckBox *chox_mic;
    QLabel *lab_micFlag;
    QLabel *lab_tabFlag;
    QCheckBox *chox_table;
    QCheckBox *chox_danmu;
    QLabel *lab_danmu;

    void setupUi(QWidget *LiveWindow)
    {
        if (LiveWindow->objectName().isEmpty())
            LiveWindow->setObjectName(QStringLiteral("LiveWindow"));
        LiveWindow->resize(1047, 567);
        la_head = new QLabel(LiveWindow);
        la_head->setObjectName(QStringLiteral("la_head"));
        la_head->setGeometry(QRect(940, 10, 81, 71));
        la_head->setPixmap(QPixmap(QString::fromUtf8("../\345\244\264\345\203\2171.jpg")));
        la_head->setScaledContents(true);
        te_show = new QTextEdit(LiveWindow);
        te_show->setObjectName(QStringLiteral("te_show"));
        te_show->setGeometry(QRect(710, 100, 321, 341));
        te_show->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);\n"
"font: 75 14pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        la_roomName = new QLabel(LiveWindow);
        la_roomName->setObjectName(QStringLiteral("la_roomName"));
        la_roomName->setGeometry(QRect(40, 10, 531, 41));
        la_roomName->setStyleSheet(QString::fromUtf8("color: rgb(85, 0, 0);\n"
"font: 75 20pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        la_hostName = new QLabel(LiveWindow);
        la_hostName->setObjectName(QStringLiteral("la_hostName"));
        la_hostName->setGeometry(QRect(100, 60, 191, 31));
        la_hostName->setStyleSheet(QLatin1String("color: rgb(255, 85, 0);\n"
"font: 75 12pt \"Times New Roman\";"));
        label = new QLabel(LiveWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 60, 31, 31));
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/\344\270\273\346\222\255\346\240\207\345\277\227.png")));
        label->setScaledContents(true);
        la_flag = new QLabel(LiveWindow);
        la_flag->setObjectName(QStringLiteral("la_flag"));
        la_flag->setGeometry(QRect(750, 30, 41, 41));
        la_flag->setPixmap(QPixmap(QString::fromUtf8(":/image/\346\240\207\345\277\227\344\275\215.png")));
        la_flag->setScaledContents(true);
        le_send = new QLineEdit(LiveWindow);
        le_send->setObjectName(QStringLiteral("le_send"));
        le_send->setGeometry(QRect(710, 490, 251, 51));
        le_send->setStyleSheet(QStringLiteral("border-color: rgb(255, 85, 0);"));
        btn_send = new QPushButton(LiveWindow);
        btn_send->setObjectName(QStringLiteral("btn_send"));
        btn_send->setGeometry(QRect(960, 490, 75, 51));
        btn_send->setStyleSheet(QLatin1String("background-color: rgb(255, 85, 0);\n"
"color: rgb(255, 255, 255);\n"
"font: 75 11pt \"Aharoni\";"));
        lab_cameraFlag = new QLabel(LiveWindow);
        lab_cameraFlag->setObjectName(QStringLiteral("lab_cameraFlag"));
        lab_cameraFlag->setGeometry(QRect(450, 60, 41, 41));
        lab_cameraFlag->setPixmap(QPixmap(QString::fromUtf8(":/image/\346\221\204\345\203\217\345\244\264.png")));
        lab_cameraFlag->setScaledContents(true);
        lab_show_host = new QLabel(LiveWindow);
        lab_show_host->setObjectName(QStringLiteral("lab_show_host"));
        lab_show_host->setGeometry(QRect(60, 110, 531, 411));
        cbox_camera = new QCheckBox(LiveWindow);
        cbox_camera->setObjectName(QStringLiteral("cbox_camera"));
        cbox_camera->setGeometry(QRect(500, 80, 81, 16));
        lab_back = new QLabel(LiveWindow);
        lab_back->setObjectName(QStringLiteral("lab_back"));
        lab_back->setGeometry(QRect(0, 0, 1051, 571));
        lab_back->setPixmap(QPixmap(QString::fromUtf8(":/image/\344\270\273\347\252\227\345\217\243\350\203\214\346\231\257.jpg")));
        lab_back->setScaledContents(true);
        chox_mic = new QCheckBox(LiveWindow);
        chox_mic->setObjectName(QStringLiteral("chox_mic"));
        chox_mic->setGeometry(QRect(640, 80, 81, 16));
        lab_micFlag = new QLabel(LiveWindow);
        lab_micFlag->setObjectName(QStringLiteral("lab_micFlag"));
        lab_micFlag->setGeometry(QRect(590, 60, 41, 41));
        lab_micFlag->setPixmap(QPixmap(QString::fromUtf8(":/image/\351\272\246\345\205\213\351\243\216.png")));
        lab_micFlag->setScaledContents(true);
        lab_tabFlag = new QLabel(LiveWindow);
        lab_tabFlag->setObjectName(QStringLiteral("lab_tabFlag"));
        lab_tabFlag->setGeometry(QRect(320, 60, 41, 41));
        lab_tabFlag->setPixmap(QPixmap(QString::fromUtf8(":/image/\346\241\214\351\235\242.JPG")));
        lab_tabFlag->setScaledContents(true);
        chox_table = new QCheckBox(LiveWindow);
        chox_table->setObjectName(QStringLiteral("chox_table"));
        chox_table->setGeometry(QRect(370, 80, 71, 16));
        chox_danmu = new QCheckBox(LiveWindow);
        chox_danmu->setObjectName(QStringLiteral("chox_danmu"));
        chox_danmu->setGeometry(QRect(580, 540, 61, 16));
        lab_danmu = new QLabel(LiveWindow);
        lab_danmu->setObjectName(QStringLiteral("lab_danmu"));
        lab_danmu->setGeometry(QRect(490, 530, 81, 31));
        lab_danmu->setPixmap(QPixmap(QString::fromUtf8(":/image/\345\274\200\345\205\263\345\205\263.png")));
        lab_danmu->setScaledContents(true);
        lab_back->raise();
        la_head->raise();
        te_show->raise();
        la_roomName->raise();
        la_hostName->raise();
        label->raise();
        la_flag->raise();
        le_send->raise();
        btn_send->raise();
        lab_cameraFlag->raise();
        lab_show_host->raise();
        cbox_camera->raise();
        chox_mic->raise();
        lab_micFlag->raise();
        lab_tabFlag->raise();
        chox_table->raise();
        chox_danmu->raise();
        lab_danmu->raise();

        retranslateUi(LiveWindow);

        QMetaObject::connectSlotsByName(LiveWindow);
    } // setupUi

    void retranslateUi(QWidget *LiveWindow)
    {
        LiveWindow->setWindowTitle(QApplication::translate("LiveWindow", "Form", 0));
        la_head->setText(QString());
        la_roomName->setText(QApplication::translate("LiveWindow", "RoomName", 0));
        la_hostName->setText(QString());
        label->setText(QString());
        la_flag->setText(QString());
        btn_send->setText(QApplication::translate("LiveWindow", "\345\217\221\351\200\201", 0));
        lab_cameraFlag->setText(QString());
        lab_show_host->setText(QString());
        cbox_camera->setText(QApplication::translate("LiveWindow", "\345\274\200\345\220\257\346\221\204\345\203\217\345\244\264", 0));
        lab_back->setText(QString());
        chox_mic->setText(QApplication::translate("LiveWindow", "\345\274\200\345\220\257\351\272\246\345\205\213\351\243\216", 0));
        lab_micFlag->setText(QString());
        lab_tabFlag->setText(QString());
        chox_table->setText(QApplication::translate("LiveWindow", "\347\233\264\346\222\255\346\241\214\351\235\242", 0));
        chox_danmu->setText(QApplication::translate("LiveWindow", "\345\274\271\345\271\225\345\274\200", 0));
        lab_danmu->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LiveWindow: public Ui_LiveWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIVEWINDOW_H
