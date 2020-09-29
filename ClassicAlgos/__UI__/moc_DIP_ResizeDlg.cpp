/****************************************************************************
** Meta object code from reading C++ file 'DIP_ResizeDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "DIP_ResizeDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DIP_ResizeDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DIP_ResizeDlg_t {
    QByteArrayData data[16];
    char stringdata0[231];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DIP_ResizeDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DIP_ResizeDlg_t qt_meta_stringdata_DIP_ResizeDlg = {
    {
QT_MOC_LITERAL(0, 0, 13), // "DIP_ResizeDlg"
QT_MOC_LITERAL(1, 14, 20), // "OnUpdateWidthSpinner"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 6), // "iValue"
QT_MOC_LITERAL(4, 43, 21), // "OnUpdateHeightSpinner"
QT_MOC_LITERAL(5, 65, 20), // "OnUpdatePredefinedRB"
QT_MOC_LITERAL(6, 86, 6), // "bState"
QT_MOC_LITERAL(7, 93, 21), // "OnUpdateUserDefinedRB"
QT_MOC_LITERAL(8, 115, 14), // "OnUpdateZoomRB"
QT_MOC_LITERAL(9, 130, 16), // "OnUpdateShrinkRB"
QT_MOC_LITERAL(10, 147, 20), // "OnUpdatePercentageCB"
QT_MOC_LITERAL(11, 168, 6), // "nValue"
QT_MOC_LITERAL(12, 175, 17), // "OnUpdateNearestRB"
QT_MOC_LITERAL(13, 193, 18), // "OnUpdateBilinearRB"
QT_MOC_LITERAL(14, 212, 11), // "OnPreviewCB"
QT_MOC_LITERAL(15, 224, 6) // "iState"

    },
    "DIP_ResizeDlg\0OnUpdateWidthSpinner\0\0"
    "iValue\0OnUpdateHeightSpinner\0"
    "OnUpdatePredefinedRB\0bState\0"
    "OnUpdateUserDefinedRB\0OnUpdateZoomRB\0"
    "OnUpdateShrinkRB\0OnUpdatePercentageCB\0"
    "nValue\0OnUpdateNearestRB\0OnUpdateBilinearRB\0"
    "OnPreviewCB\0iState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DIP_ResizeDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x08 /* Private */,
       4,    1,   67,    2, 0x08 /* Private */,
       5,    1,   70,    2, 0x08 /* Private */,
       7,    1,   73,    2, 0x08 /* Private */,
       8,    1,   76,    2, 0x08 /* Private */,
       9,    1,   79,    2, 0x08 /* Private */,
      10,    1,   82,    2, 0x08 /* Private */,
      12,    1,   85,    2, 0x08 /* Private */,
      13,    1,   88,    2, 0x08 /* Private */,
      14,    1,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Int,   15,

       0        // eod
};

void DIP_ResizeDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DIP_ResizeDlg *_t = static_cast<DIP_ResizeDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnUpdateWidthSpinner((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->OnUpdateHeightSpinner((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->OnUpdatePredefinedRB((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->OnUpdateUserDefinedRB((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->OnUpdateZoomRB((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->OnUpdateShrinkRB((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->OnUpdatePercentageCB((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->OnUpdateNearestRB((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->OnUpdateBilinearRB((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->OnPreviewCB((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DIP_ResizeDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DIP_ResizeDlg.data,
      qt_meta_data_DIP_ResizeDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DIP_ResizeDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DIP_ResizeDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DIP_ResizeDlg.stringdata0))
        return static_cast<void*>(const_cast< DIP_ResizeDlg*>(this));
    if (!strcmp(_clname, "Ui::ResizeDialog"))
        return static_cast< Ui::ResizeDialog*>(const_cast< DIP_ResizeDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int DIP_ResizeDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
