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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QTextEdit *te_show;
    QPushButton *btn_start;
    QLabel *la_back;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(587, 368);
        te_show = new QTextEdit(MainWindow);
        te_show->setObjectName(QStringLiteral("te_show"));
        te_show->setGeometry(QRect(10, 10, 191, 241));
        btn_start = new QPushButton(MainWindow);
        btn_start->setObjectName(QStringLiteral("btn_start"));
        btn_start->setGeometry(QRect(40, 290, 111, 41));
        la_back = new QLabel(MainWindow);
        la_back->setObjectName(QStringLiteral("la_back"));
        la_back->setGeometry(QRect(-7, -9, 601, 381));
        la_back->setPixmap(QPixmap(QString::fromUtf8(":/image/1.jpg")));
        la_back->setScaledContents(true);
        la_back->raise();
        te_show->raise();
        btn_start->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btn_start->setText(QApplication::translate("MainWindow", "Start", 0));
        la_back->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
