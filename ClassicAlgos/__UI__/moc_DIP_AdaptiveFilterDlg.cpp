/****************************************************************************
** Meta object code from reading C++ file 'DIP_AdaptiveFilterDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "DIP_AdaptiveFilterDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DIP_AdaptiveFilterDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DIP_AdaptiveFilterDlg_t {
    QByteArrayData data[9];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DIP_AdaptiveFilterDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DIP_AdaptiveFilterDlg_t qt_meta_stringdata_DIP_AdaptiveFilterDlg = {
    {
QT_MOC_LITERAL(0, 0, 21), // "DIP_AdaptiveFilterDlg"
QT_MOC_LITERAL(1, 22, 13), // "OnUpdateWidth"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 6), // "iValue"
QT_MOC_LITERAL(4, 44, 14), // "OnUpdateHeight"
QT_MOC_LITERAL(5, 59, 16), // "OnUpdateBorderCB"
QT_MOC_LITERAL(6, 76, 14), // "OnUpdateSMaxCB"
QT_MOC_LITERAL(7, 91, 11), // "OnPreviewCB"
QT_MOC_LITERAL(8, 103, 6) // "iState"

    },
    "DIP_AdaptiveFilterDlg\0OnUpdateWidth\0"
    "\0iValue\0OnUpdateHeight\0OnUpdateBorderCB\0"
    "OnUpdateSMaxCB\0OnPreviewCB\0iState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DIP_AdaptiveFilterDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    1,   42,    2, 0x08 /* Private */,
       5,    1,   45,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       7,    1,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void DIP_AdaptiveFilterDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DIP_AdaptiveFilterDlg *_t = static_cast<DIP_AdaptiveFilterDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnUpdateWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->OnUpdateHeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->OnUpdateBorderCB((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->OnUpdateSMaxCB((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->OnPreviewCB((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DIP_AdaptiveFilterDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DIP_AdaptiveFilterDlg.data,
      qt_meta_data_DIP_AdaptiveFilterDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DIP_AdaptiveFilterDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DIP_AdaptiveFilterDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DIP_AdaptiveFilterDlg.stringdata0))
        return static_cast<void*>(const_cast< DIP_AdaptiveFilterDlg*>(this));
    if (!strcmp(_clname, "Ui::AdaptiveDialog"))
        return static_cast< Ui::AdaptiveDialog*>(const_cast< DIP_AdaptiveFilterDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int DIP_AdaptiveFilterDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
