/****************************************************************************
** Meta object code from reading C++ file 'ChatWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Client/ChatWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChatWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ChatWindow_t {
    QByteArrayData data[11];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChatWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChatWindow_t qt_meta_stringdata_ChatWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ChatWindow"
QT_MOC_LITERAL(1, 11, 12), // "sigStartLive"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "sigJoinRoom"
QT_MOC_LITERAL(4, 37, 24), // "on_btn_startLive_clicked"
QT_MOC_LITERAL(5, 62, 20), // "on_btn_close_clicked"
QT_MOC_LITERAL(6, 83, 18), // "sigRefreshListSlot"
QT_MOC_LITERAL(7, 102, 8), // "QString&"
QT_MOC_LITERAL(8, 111, 21), // "itemDoubleClickedSlot"
QT_MOC_LITERAL(9, 133, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(10, 150, 12) // "sigRoomClose"

    },
    "ChatWindow\0sigStartLive\0\0sigJoinRoom\0"
    "on_btn_startLive_clicked\0on_btn_close_clicked\0"
    "sigRefreshListSlot\0QString&\0"
    "itemDoubleClickedSlot\0QListWidgetItem*\0"
    "sigRoomClose"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    2,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   55,    2, 0x08 /* Private */,
       5,    0,   56,    2, 0x08 /* Private */,
       6,    1,   57,    2, 0x08 /* Private */,
       8,    1,   60,    2, 0x08 /* Private */,
      10,    1,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QColor,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, 0x80000000 | 7,    2,

       0        // eod
};

void ChatWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChatWindow *_t = static_cast<ChatWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigStartLive(); break;
        case 1: _t->sigJoinRoom((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 2: _t->on_btn_startLive_clicked(); break;
        case 3: _t->on_btn_close_clicked(); break;
        case 4: _t->sigRefreshListSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->itemDoubleClickedSlot((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 6: _t->sigRoomClose((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ChatWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChatWindow::sigStartLive)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ChatWindow::*_t)(QString , QColor );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChatWindow::sigJoinRoom)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ChatWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ChatWindow.data,
      qt_meta_data_ChatWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ChatWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ChatWindow.stringdata0))
        return static_cast<void*>(const_cast< ChatWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int ChatWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ChatWindow::sigStartLive()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ChatWindow::sigJoinRoom(QString _t1, QColor _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
