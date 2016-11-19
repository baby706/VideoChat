#-------------------------------------------------
#
# Project created by QtCreator 2016-10-09T15:17:40
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += sql
QT      += multimedia
QT      += multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    Register.cpp \
    MyLineEdit.cpp \
    ChatWindow.cpp \
    LiveWindow.cpp \
    VideoSurface.cpp \
    codearea.cpp \
    Danmu.cpp

HEADERS  += MainWindow.h \
    package.h \
    Register.h \
    MyLineEdit.h \
    ChatWindow.h \
    LiveWindow.h \
    videopackage.h \
    VideoSurface.h \
    codearea.h \
    Danmu.h

FORMS    += MainWindow.ui \
    Register.ui \
    ChatWindow.ui \
    LiveWindow.ui

RESOURCES += \
    Images/picture.qrc
