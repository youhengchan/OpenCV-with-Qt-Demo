/****************************************************************************
** Meta object code from reading C++ file 'magnifierwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../OpenCVWithQtDemo/magnifierwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'magnifierwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_namespace_wslibs__namespace_wsbaswidgets__DrawWidget_t {
    QByteArrayData data[1];
    char stringdata0[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_namespace_wslibs__namespace_wsbaswidgets__DrawWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_namespace_wslibs__namespace_wsbaswidgets__DrawWidget_t qt_meta_stringdata_namespace_wslibs__namespace_wsbaswidgets__DrawWidget = {
    {
QT_MOC_LITERAL(0, 0, 52) // "namespace_wslibs::namespace_w..."

    },
    "namespace_wslibs::namespace_wsbaswidgets::DrawWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_namespace_wslibs__namespace_wsbaswidgets__DrawWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void namespace_wslibs::namespace_wsbaswidgets::DrawWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject namespace_wslibs::namespace_wsbaswidgets::DrawWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_namespace_wslibs__namespace_wsbaswidgets__DrawWidget.data,
    qt_meta_data_namespace_wslibs__namespace_wsbaswidgets__DrawWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *namespace_wslibs::namespace_wsbaswidgets::DrawWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *namespace_wslibs::namespace_wsbaswidgets::DrawWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_namespace_wslibs__namespace_wsbaswidgets__DrawWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int namespace_wslibs::namespace_wsbaswidgets::DrawWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_namespace_wslibs__namespace_wsbaswidgets__MagnifierWidget_t {
    QByteArrayData data[5];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_namespace_wslibs__namespace_wsbaswidgets__MagnifierWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_namespace_wslibs__namespace_wsbaswidgets__MagnifierWidget_t qt_meta_stringdata_namespace_wslibs__namespace_wsbaswidgets__MagnifierWidget = {
    {
QT_MOC_LITERAL(0, 0, 57), // "namespace_wslibs::namespace_w..."
QT_MOC_LITERAL(1, 58, 16), // "slotFocusChanged"
QT_MOC_LITERAL(2, 75, 0), // ""
QT_MOC_LITERAL(3, 76, 8), // "QWidget*"
QT_MOC_LITERAL(4, 85, 9) // "slotTimer"

    },
    "namespace_wslibs::namespace_wsbaswidgets::MagnifierWidget\0"
    "slotFocusChanged\0\0QWidget*\0slotTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_namespace_wslibs__namespace_wsbaswidgets__MagnifierWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x08 /* Private */,
       4,    0,   29,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    2,    2,
    QMetaType::Void,

       0        // eod
};

void namespace_wslibs::namespace_wsbaswidgets::MagnifierWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MagnifierWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotFocusChanged((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 1: _t->slotTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject namespace_wslibs::namespace_wsbaswidgets::MagnifierWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_namespace_wslibs__namespace_wsbaswidgets__MagnifierWidget.data,
    qt_meta_data_namespace_wslibs__namespace_wsbaswidgets__MagnifierWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *namespace_wslibs::namespace_wsbaswidgets::MagnifierWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *namespace_wslibs::namespace_wsbaswidgets::MagnifierWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_namespace_wslibs__namespace_wsbaswidgets__MagnifierWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int namespace_wslibs::namespace_wsbaswidgets::MagnifierWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
