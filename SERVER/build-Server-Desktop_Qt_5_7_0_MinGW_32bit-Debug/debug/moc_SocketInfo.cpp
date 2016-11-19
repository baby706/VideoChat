/****************************************************************************
** Meta object code from reading C++ file 'SocketInfo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Server/SocketInfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SocketInfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SocketInfo_t {
    QByteArrayData data[9];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SocketInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SocketInfo_t qt_meta_stringdata_SocketInfo = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SocketInfo"
QT_MOC_LITERAL(1, 11, 12), // "sigInfoWrite"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "QTcpSocket*"
QT_MOC_LITERAL(4, 37, 18), // "sigJoinRoomSuccess"
QT_MOC_LITERAL(5, 56, 15), // "sigClientLogout"
QT_MOC_LITERAL(6, 72, 8), // "QThread*"
QT_MOC_LITERAL(7, 81, 13), // "readyReadSlot"
QT_MOC_LITERAL(8, 95, 20) // "socketDisconnectSlot"

    },
    "SocketInfo\0sigInfoWrite\0\0QTcpSocket*\0"
    "sigJoinRoomSuccess\0sigClientLogout\0"
    "QThread*\0readyReadSlot\0socketDisconnectSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SocketInfo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   39,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    1,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   50,    2, 0x0a /* Public */,
       8,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QVariant, QMetaType::LongLong,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SocketInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SocketInfo *_t = static_cast<SocketInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigInfoWrite((*reinterpret_cast< QTcpSocket*(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3]))); break;
        case 1: _t->sigJoinRoomSuccess(); break;
        case 2: _t->sigClientLogout((*reinterpret_cast< QThread*(*)>(_a[1]))); break;
        case 3: _t->readyReadSlot(); break;
        case 4: _t->socketDisconnectSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QThread* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SocketInfo::*_t)(QTcpSocket * , QVariant , qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SocketInfo::sigInfoWrite)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SocketInfo::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SocketInfo::sigJoinRoomSuccess)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SocketInfo::*_t)(QThread * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SocketInfo::sigClientLogout)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject SocketInfo::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SocketInfo.data,
      qt_meta_data_SocketInfo,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SocketInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SocketInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SocketInfo.stringdata0))
        return static_cast<void*>(const_cast< SocketInfo*>(this));
    return QObject::qt_metacast(_clname);
}

int SocketInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SocketInfo::sigInfoWrite(QTcpSocket * _t1, QVariant _t2, qint64 _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SocketInfo::sigJoinRoomSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void SocketInfo::sigClientLogout(QThread * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
