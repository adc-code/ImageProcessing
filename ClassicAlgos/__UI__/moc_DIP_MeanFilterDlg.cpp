/****************************************************************************
** Meta object code from reading C++ file 'DIP_MeanFilterDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "DIP_MeanFilterDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DIP_MeanFilterDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DIP_MeanFilterDlg_t {
    QByteArrayData data[14];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DIP_MeanFilterDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DIP_MeanFilterDlg_t qt_meta_stringdata_DIP_MeanFilterDlg = {
    {
QT_MOC_LITERAL(0, 0, 17), // "DIP_MeanFilterDlg"
QT_MOC_LITERAL(1, 18, 14), // "OnUpdateArthRB"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 6), // "bState"
QT_MOC_LITERAL(4, 41, 13), // "OnUpdateGeoRB"
QT_MOC_LITERAL(5, 55, 14), // "OnUpdateHarmRB"
QT_MOC_LITERAL(6, 70, 16), // "OnUpdateContraRB"
QT_MOC_LITERAL(7, 87, 14), // "OnUpdateQValue"
QT_MOC_LITERAL(8, 102, 6), // "iValue"
QT_MOC_LITERAL(9, 109, 13), // "OnUpdateWidth"
QT_MOC_LITERAL(10, 123, 14), // "OnUpdateHeight"
QT_MOC_LITERAL(11, 138, 16), // "OnUpdateBorderCB"
QT_MOC_LITERAL(12, 155, 11), // "OnPreviewCB"
QT_MOC_LITERAL(13, 167, 6) // "iState"

    },
    "DIP_MeanFilterDlg\0OnUpdateArthRB\0\0"
    "bState\0OnUpdateGeoRB\0OnUpdateHarmRB\0"
    "OnUpdateContraRB\0OnUpdateQValue\0iValue\0"
    "OnUpdateWidth\0OnUpdateHeight\0"
    "OnUpdateBorderCB\0OnPreviewCB\0iState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DIP_MeanFilterDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x08 /* Private */,
       4,    1,   62,    2, 0x08 /* Private */,
       5,    1,   65,    2, 0x08 /* Private */,
       6,    1,   68,    2, 0x08 /* Private */,
       7,    1,   71,    2, 0x08 /* Private */,
       9,    1,   74,    2, 0x08 /* Private */,
      10,    1,   77,    2, 0x08 /* Private */,
      11,    1,   80,    2, 0x08 /* Private */,
      12,    1,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void DIP_MeanFilterDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DIP_MeanFilterDlg *_t = static_cast<DIP_MeanFilterDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnUpdateArthRB((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->OnUpdateGeoRB((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->OnUpdateHarmRB((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->OnUpdateContraRB((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->OnUpdateQValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->OnUpdateWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->OnUpdateHeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->OnUpdateBorderCB((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->OnPreviewCB((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DIP_MeanFilterDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DIP_MeanFilterDlg.data,
      qt_meta_data_DIP_MeanFilterDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DIP_MeanFilterDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DIP_MeanFilterDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DIP_MeanFilterDlg.stringdata0))
        return static_cast<void*>(const_cast< DIP_MeanFilterDlg*>(this));
    if (!strcmp(_clname, "Ui::MeanFilterDialog"))
        return static_cast< Ui::MeanFilterDialog*>(const_cast< DIP_MeanFilterDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int DIP_MeanFilterDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
