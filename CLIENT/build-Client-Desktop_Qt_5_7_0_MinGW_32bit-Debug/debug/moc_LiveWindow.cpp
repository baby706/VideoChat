/****************************************************************************
** Meta object code from reading C++ file 'LiveWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Client/LiveWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LiveWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LiveWindow_t {
    QByteArrayData data[17];
    char stringdata0[264];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LiveWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LiveWindow_t qt_meta_stringdata_LiveWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "LiveWindow"
QT_MOC_LITERAL(1, 11, 14), // "sigSendMessage"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "QString&"
QT_MOC_LITERAL(4, 36, 14), // "sigVisitorQuit"
QT_MOC_LITERAL(5, 51, 11), // "sigHostQuit"
QT_MOC_LITERAL(6, 63, 19), // "on_btn_send_clicked"
QT_MOC_LITERAL(7, 83, 21), // "sigReceiveMessageSlot"
QT_MOC_LITERAL(8, 105, 6), // "pack_t"
QT_MOC_LITERAL(9, 112, 21), // "sigNoticeHostQuitSlot"
QT_MOC_LITERAL(10, 134, 16), // "videoChangedSlot"
QT_MOC_LITERAL(11, 151, 11), // "QVideoFrame"
QT_MOC_LITERAL(12, 163, 17), // "onReadyReadSocket"
QT_MOC_LITERAL(13, 181, 22), // "on_cbox_camera_clicked"
QT_MOC_LITERAL(14, 204, 21), // "on_chox_table_clicked"
QT_MOC_LITERAL(15, 226, 15), // "showDesktopSlot"
QT_MOC_LITERAL(16, 242, 21) // "on_chox_danmu_clicked"

    },
    "LiveWindow\0sigSendMessage\0\0QString&\0"
    "sigVisitorQuit\0sigHostQuit\0"
    "on_btn_send_clicked\0sigReceiveMessageSlot\0"
    "pack_t\0sigNoticeHostQuitSlot\0"
    "videoChangedSlot\0QVideoFrame\0"
    "onReadyReadSocket\0on_cbox_camera_clicked\0"
    "on_chox_table_clicked\0showDesktopSlot\0"
    "on_chox_danmu_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LiveWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,
       4,    1,   79,    2, 0x06 /* Public */,
       5,    0,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   83,    2, 0x08 /* Private */,
       7,    1,   84,    2, 0x08 /* Private */,
       9,    0,   87,    2, 0x08 /* Private */,
      10,    1,   88,    2, 0x08 /* Private */,
      12,    0,   91,    2, 0x08 /* Private */,
      13,    0,   92,    2, 0x08 /* Private */,
      14,    0,   93,    2, 0x08 /* Private */,
      15,    0,   94,    2, 0x08 /* Private */,
      16,    0,   95,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LiveWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LiveWindow *_t = static_cast<LiveWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigSendMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->sigVisitorQuit((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sigHostQuit(); break;
        case 3: _t->on_btn_send_clicked(); break;
        case 4: _t->sigReceiveMessageSlot((*reinterpret_cast< pack_t(*)>(_a[1]))); break;
        case 5: _t->sigNoticeHostQuitSlot(); break;
        case 6: _t->videoChangedSlot((*reinterpret_cast< QVideoFrame(*)>(_a[1]))); break;
        case 7: _t->onReadyReadSocket(); break;
        case 8: _t->on_cbox_camera_clicked(); break;
        case 9: _t->on_chox_table_clicked(); break;
        case 10: _t->showDesktopSlot(); break;
        case 11: _t->on_chox_danmu_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVideoFrame >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LiveWindow::*_t)(QString & , QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LiveWindow::sigSendMessage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (LiveWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LiveWindow::sigVisitorQuit)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (LiveWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LiveWindow::sigHostQuit)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject LiveWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LiveWindow.data,
      qt_meta_data_LiveWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LiveWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LiveWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LiveWindow.stringdata0))
        return static_cast<void*>(const_cast< LiveWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int LiveWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void LiveWindow::sigSendMessage(QString & _t1, QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LiveWindow::sigVisitorQuit(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LiveWindow::sigHostQuit()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
