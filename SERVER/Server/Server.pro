#-------------------------------------------------
#
# Project created by QtCreator 2016-10-09T10:20:31
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Server
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    SocketInfo.cpp \
    DllManager.cpp \
    User.cpp \
    UserHandle.cpp \
    SocketManager.cpp \
    LiveRoomList.cpp \
    OneLiveRoom.cpp

HEADERS  += MainWindow.h \
    SocketInfo.h \
    package.h \
    DllManager.h \
    User.h \
    UserHandle.h \
    SocketManager.h \
    LiveRoomList.h \
    OneLiveRoom.h

FORMS    += MainWindow.ui

RESOURCES += \
    Images/picture.qrc
