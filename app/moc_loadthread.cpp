/****************************************************************************
** Meta object code from reading C++ file 'loadthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "loadthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loadthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LoadThread_t {
    QByteArrayData data[15];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LoadThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LoadThread_t qt_meta_stringdata_LoadThread = {
    {
QT_MOC_LITERAL(0, 0, 10), // "LoadThread"
QT_MOC_LITERAL(1, 11, 7), // "endLoad"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 5), // "title"
QT_MOC_LITERAL(4, 26, 6), // "avaUrl"
QT_MOC_LITERAL(5, 33, 4), // "text"
QT_MOC_LITERAL(6, 38, 6), // "images"
QT_MOC_LITERAL(7, 45, 12), // "showThisPost"
QT_MOC_LITERAL(8, 58, 9), // "startLoad"
QT_MOC_LITERAL(9, 68, 6), // "object"
QT_MOC_LITERAL(10, 75, 11), // "dataChanged"
QT_MOC_LITERAL(11, 87, 4), // "load"
QT_MOC_LITERAL(12, 92, 8), // "loadData"
QT_MOC_LITERAL(13, 101, 4), // "stop"
QT_MOC_LITERAL(14, 106, 4) // "data"

    },
    "LoadThread\0endLoad\0\0title\0avaUrl\0text\0"
    "images\0showThisPost\0startLoad\0object\0"
    "dataChanged\0load\0loadData\0stop\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoadThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       1,   74, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   44,    2, 0x06 /* Public */,
       8,    1,   55,    2, 0x06 /* Public */,
      10,    0,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   59,    2, 0x08 /* Private */,
      12,    5,   62,    2, 0x08 /* Private */,
      13,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QVariantList, QMetaType::Bool,    3,    4,    5,    6,    7,
    QMetaType::Void, QMetaType::QJsonValue,    9,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QJsonValue,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QVariantList, QMetaType::Bool,    3,    4,    5,    6,    7,
    QMetaType::Void,

 // properties: name, type, flags
      14, QMetaType::QByteArray, 0x00495103,

 // properties: notify_signal_id
       2,

       0        // eod
};

void LoadThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LoadThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->endLoad((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QList<QVariant>(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 1: _t->startLoad((*reinterpret_cast< QJsonValue(*)>(_a[1]))); break;
        case 2: _t->dataChanged(); break;
        case 3: _t->load((*reinterpret_cast< QJsonValue(*)>(_a[1]))); break;
        case 4: _t->loadData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QList<QVariant>(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 5: _t->stop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LoadThread::*)(QString , QString , QString , QList<QVariant> , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoadThread::endLoad)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LoadThread::*)(QJsonValue );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoadThread::startLoad)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LoadThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoadThread::dataChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<LoadThread *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QByteArray*>(_v) = _t->getData(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<LoadThread *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setData(*reinterpret_cast< QByteArray*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject LoadThread::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_LoadThread.data,
    qt_meta_data_LoadThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LoadThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoadThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LoadThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int LoadThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void LoadThread::endLoad(QString _t1, QString _t2, QString _t3, QList<QVariant> _t4, bool _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LoadThread::startLoad(QJsonValue _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LoadThread::dataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
