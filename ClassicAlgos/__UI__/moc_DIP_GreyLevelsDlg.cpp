/****************************************************************************
** Meta object code from reading C++ file 'DIP_GreyLevelsDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "DIP_GreyLevelsDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DIP_GreyLevelsDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DIP_GreyLevelsDlg_t {
    QByteArrayData data[9];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DIP_GreyLevelsDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DIP_GreyLevelsDlg_t qt_meta_stringdata_DIP_GreyLevelsDlg = {
    {
QT_MOC_LITERAL(0, 0, 17), // "DIP_GreyLevelsDlg"
QT_MOC_LITERAL(1, 18, 14), // "OnUpdateSlider"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 6), // "nValue"
QT_MOC_LITERAL(4, 41, 14), // "OnSimpleAlgoRB"
QT_MOC_LITERAL(5, 56, 6), // "bValue"
QT_MOC_LITERAL(6, 63, 16), // "OnAdvancedAlgoRB"
QT_MOC_LITERAL(7, 80, 11), // "OnPreviewCB"
QT_MOC_LITERAL(8, 92, 6) // "iValue"

    },
    "DIP_GreyLevelsDlg\0OnUpdateSlider\0\0"
    "nValue\0OnSimpleAlgoRB\0bValue\0"
    "OnAdvancedAlgoRB\0OnPreviewCB\0iValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DIP_GreyLevelsDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       4,    1,   37,    2, 0x08 /* Private */,
       6,    1,   40,    2, 0x08 /* Private */,
       7,    1,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void DIP_GreyLevelsDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DIP_GreyLevelsDlg *_t = static_cast<DIP_GreyLevelsDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnUpdateSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->OnSimpleAlgoRB((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->OnAdvancedAlgoRB((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->OnPreviewCB((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DIP_GreyLevelsDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DIP_GreyLevelsDlg.data,
      qt_meta_data_DIP_GreyLevelsDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DIP_GreyLevelsDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DIP_GreyLevelsDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DIP_GreyLevelsDlg.stringdata0))
        return static_cast<void*>(const_cast< DIP_GreyLevelsDlg*>(this));
    if (!strcmp(_clname, "Ui::GreyLevelsDialog"))
        return static_cast< Ui::GreyLevelsDialog*>(const_cast< DIP_GreyLevelsDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int DIP_GreyLevelsDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
