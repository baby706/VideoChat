/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Client/MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[329];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "sigRegisterCnki"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 8), // "QString&"
QT_MOC_LITERAL(4, 37, 14), // "sigRefreshList"
QT_MOC_LITERAL(5, 52, 17), // "sigReceiveMessage"
QT_MOC_LITERAL(6, 70, 6), // "pack_t"
QT_MOC_LITERAL(7, 77, 17), // "sigNoticeHostQuit"
QT_MOC_LITERAL(8, 95, 12), // "sigRoomClose"
QT_MOC_LITERAL(9, 108, 20), // "on_btn_login_clicked"
QT_MOC_LITERAL(10, 129, 23), // "on_btn_register_clicked"
QT_MOC_LITERAL(11, 153, 13), // "readyReadSlot"
QT_MOC_LITERAL(12, 167, 5), // "onErr"
QT_MOC_LITERAL(13, 173, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(14, 202, 11), // "socketError"
QT_MOC_LITERAL(15, 214, 15), // "sigRegisterSlot"
QT_MOC_LITERAL(16, 230, 11), // "sigCnkiSlot"
QT_MOC_LITERAL(17, 242, 16), // "sigStartLiveSlot"
QT_MOC_LITERAL(18, 259, 15), // "sigJoinRoomSlot"
QT_MOC_LITERAL(19, 275, 18), // "sigSendMessageSlot"
QT_MOC_LITERAL(20, 294, 18), // "sigVisitorQuitSlot"
QT_MOC_LITERAL(21, 313, 15) // "sigHostQuitSlot"

    },
    "MainWindow\0sigRegisterCnki\0\0QString&\0"
    "sigRefreshList\0sigReceiveMessage\0"
    "pack_t\0sigNoticeHostQuit\0sigRoomClose\0"
    "on_btn_login_clicked\0on_btn_register_clicked\0"
    "readyReadSlot\0onErr\0QAbstractSocket::SocketError\0"
    "socketError\0sigRegisterSlot\0sigCnkiSlot\0"
    "sigStartLiveSlot\0sigJoinRoomSlot\0"
    "sigSendMessageSlot\0sigVisitorQuitSlot\0"
    "sigHostQuitSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       4,    1,   97,    2, 0x06 /* Public */,
       5,    1,  100,    2, 0x06 /* Public */,
       7,    0,  103,    2, 0x06 /* Public */,
       8,    1,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  107,    2, 0x08 /* Private */,
      10,    0,  108,    2, 0x08 /* Private */,
      11,    0,  109,    2, 0x08 /* Private */,
      12,    1,  110,    2, 0x08 /* Private */,
      15,    2,  113,    2, 0x08 /* Private */,
      16,    1,  118,    2, 0x08 /* Private */,
      17,    0,  121,    2, 0x08 /* Private */,
      18,    2,  122,    2, 0x08 /* Private */,
      19,    2,  127,    2, 0x08 /* Private */,
      20,    1,  132,    2, 0x08 /* Private */,
      21,    0,  135,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    2,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QColor,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigRegisterCnki((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sigRefreshList((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sigReceiveMessage((*reinterpret_cast< pack_t(*)>(_a[1]))); break;
        case 3: _t->sigNoticeHostQuit(); break;
        case 4: _t->sigRoomClose((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->on_btn_login_clicked(); break;
        case 6: _t->on_btn_register_clicked(); break;
        case 7: _t->readyReadSlot(); break;
        case 8: _t->onErr((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 9: _t->sigRegisterSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 10: _t->sigCnkiSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->sigStartLiveSlot(); break;
        case 12: _t->sigJoinRoomSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 13: _t->sigSendMessageSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 14: _t->sigVisitorQuitSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->sigHostQuitSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sigRegisterCnki)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sigRefreshList)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(pack_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sigReceiveMessage)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sigNoticeHostQuit)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sigRoomClose)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sigRegisterCnki(QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::sigRefreshList(QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::sigReceiveMessage(pack_t _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::sigNoticeHostQuit()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MainWindow::sigRoomClose(QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
