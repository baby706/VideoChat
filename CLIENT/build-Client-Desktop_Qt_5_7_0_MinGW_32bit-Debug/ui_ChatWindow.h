/********************************************************************************
** Form generated from reading UI file 'ChatWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWINDOW_H
#define UI_CHATWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWindow
{
public:
    QLabel *label;
    QPushButton *btn_startLive;
    QPushButton *btn_close;
    QLabel *label_2;
    QListWidget *list_room;

    void setupUi(QWidget *ChatWindow)
    {
        if (ChatWindow->objectName().isEmpty())
            ChatWindow->setObjectName(QStringLiteral("ChatWindow"));
        ChatWindow->resize(816, 431);
        label = new QLabel(ChatWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 821, 431));
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/\344\270\273\347\252\227\345\217\243\350\203\214\346\231\257.jpg")));
        label->setScaledContents(true);
        btn_startLive = new QPushButton(ChatWindow);
        btn_startLive->setObjectName(QStringLiteral("btn_startLive"));
        btn_startLive->setGeometry(QRect(594, 362, 91, 31));
        btn_startLive->setStyleSheet(QStringLiteral("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 255, 255, 255), stop:0.1 rgba(255, 255, 255, 255), stop:0.2 rgba(255, 176, 176, 167), stop:0.3 rgba(255, 151, 151, 92), stop:0.4 rgba(255, 125, 125, 51), stop:0.5 rgba(255, 76, 76, 205), stop:0.52 rgba(255, 76, 76, 205), stop:0.6 rgba(255, 180, 180, 84), stop:1 rgba(255, 255, 255, 0));"));
        btn_close = new QPushButton(ChatWindow);
        btn_close->setObjectName(QStringLiteral("btn_close"));
        btn_close->setGeometry(QRect(704, 362, 81, 31));
        btn_close->setStyleSheet(QStringLiteral("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 0), stop:0.52 rgba(0, 0, 0, 0), stop:0.565 rgba(82, 121, 76, 33), stop:0.65 rgba(159, 235, 148, 64), stop:0.721925 rgba(255, 238, 150, 129), stop:0.77 rgba(255, 128, 128, 204), stop:0.89 rgba(191, 128, 255, 64), stop:1 rgba(0, 0, 0, 0));"));
        label_2 = new QLabel(ChatWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(700, 20, 81, 111));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/image/\346\263\250\345\206\2141.jpg")));
        label_2->setScaledContents(true);
        list_room = new QListWidget(ChatWindow);
        list_room->setObjectName(QStringLiteral("list_room"));
        list_room->setEnabled(true);
        list_room->setGeometry(QRect(30, 60, 541, 321));
        QFont font;
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        list_room->setFont(font);
        list_room->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));

        retranslateUi(ChatWindow);

        QMetaObject::connectSlotsByName(ChatWindow);
    } // setupUi

    void retranslateUi(QWidget *ChatWindow)
    {
        ChatWindow->setWindowTitle(QApplication::translate("ChatWindow", "Form", 0));
        label->setText(QString());
        btn_startLive->setText(QApplication::translate("ChatWindow", "\345\274\200\345\220\257\347\233\264\346\222\255", 0));
        btn_close->setText(QApplication::translate("ChatWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", 0));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChatWindow: public Ui_ChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW_H
