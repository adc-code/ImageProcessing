/****************************************************************************
** Meta object code from reading C++ file 'DIP_PiecewiseDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "DIP_PiecewiseDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DIP_PiecewiseDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DIP_PiecewiseDlg_t {
    QByteArrayData data[14];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DIP_PiecewiseDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DIP_PiecewiseDlg_t qt_meta_stringdata_DIP_PiecewiseDlg = {
    {
QT_MOC_LITERAL(0, 0, 16), // "DIP_PiecewiseDlg"
QT_MOC_LITERAL(1, 17, 19), // "OnUpdatePresetCombo"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 9), // "iSelected"
QT_MOC_LITERAL(4, 48, 13), // "OnCellClicked"
QT_MOC_LITERAL(5, 62, 4), // "iRow"
QT_MOC_LITERAL(6, 67, 7), // "iColumn"
QT_MOC_LITERAL(7, 75, 11), // "OnAddButton"
QT_MOC_LITERAL(8, 87, 14), // "OnRemoveButton"
QT_MOC_LITERAL(9, 102, 14), // "OnUpdateXValue"
QT_MOC_LITERAL(10, 117, 6), // "iValue"
QT_MOC_LITERAL(11, 124, 14), // "OnUpdateYValue"
QT_MOC_LITERAL(12, 139, 11), // "OnPreviewCB"
QT_MOC_LITERAL(13, 151, 6) // "iState"

    },
    "DIP_PiecewiseDlg\0OnUpdatePresetCombo\0"
    "\0iSelected\0OnCellClicked\0iRow\0iColumn\0"
    "OnAddButton\0OnRemoveButton\0OnUpdateXValue\0"
    "iValue\0OnUpdateYValue\0OnPreviewCB\0"
    "iState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DIP_PiecewiseDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       4,    2,   52,    2, 0x08 /* Private */,
       7,    0,   57,    2, 0x08 /* Private */,
       8,    0,   58,    2, 0x08 /* Private */,
       9,    1,   59,    2, 0x08 /* Private */,
      11,    1,   62,    2, 0x08 /* Private */,
      12,    1,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void DIP_PiecewiseDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DIP_PiecewiseDlg *_t = static_cast<DIP_PiecewiseDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnUpdatePresetCombo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->OnCellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->OnAddButton(); break;
        case 3: _t->OnRemoveButton(); break;
        case 4: _t->OnUpdateXValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->OnUpdateYValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->OnPreviewCB((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DIP_PiecewiseDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DIP_PiecewiseDlg.data,
      qt_meta_data_DIP_PiecewiseDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DIP_PiecewiseDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DIP_PiecewiseDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DIP_PiecewiseDlg.stringdata0))
        return static_cast<void*>(const_cast< DIP_PiecewiseDlg*>(this));
    if (!strcmp(_clname, "Ui::PiecewiseDialog"))
        return static_cast< Ui::PiecewiseDialog*>(const_cast< DIP_PiecewiseDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int DIP_PiecewiseDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
