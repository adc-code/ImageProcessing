/****************************************************************************
** Meta object code from reading C++ file 'DIP_HistoTransDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "DIP_HistoTransDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DIP_HistoTransDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DIP_HistoTransDlg_t {
    QByteArrayData data[11];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DIP_HistoTransDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DIP_HistoTransDlg_t qt_meta_stringdata_DIP_HistoTransDlg = {
    {
QT_MOC_LITERAL(0, 0, 17), // "DIP_HistoTransDlg"
QT_MOC_LITERAL(1, 18, 15), // "OnSelectHistoEq"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 6), // "iState"
QT_MOC_LITERAL(4, 42, 18), // "OnSelectHistoShift"
QT_MOC_LITERAL(5, 61, 20), // "OnSelectHistoStretch"
QT_MOC_LITERAL(6, 82, 19), // "OnChangeShiftSlider"
QT_MOC_LITERAL(7, 102, 6), // "iValue"
QT_MOC_LITERAL(8, 109, 19), // "OnChangeLimitsCombo"
QT_MOC_LITERAL(9, 129, 20), // "OnChangeLimitsSlider"
QT_MOC_LITERAL(10, 150, 11) // "OnPreviewCB"

    },
    "DIP_HistoTransDlg\0OnSelectHistoEq\0\0"
    "iState\0OnSelectHistoShift\0"
    "OnSelectHistoStretch\0OnChangeShiftSlider\0"
    "iValue\0OnChangeLimitsCombo\0"
    "OnChangeLimitsSlider\0OnPreviewCB"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DIP_HistoTransDlg[] = {

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
       4,    1,   52,    2, 0x08 /* Private */,
       5,    1,   55,    2, 0x08 /* Private */,
       6,    1,   58,    2, 0x08 /* Private */,
       8,    1,   61,    2, 0x08 /* Private */,
       9,    1,   64,    2, 0x08 /* Private */,
      10,    1,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void DIP_HistoTransDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DIP_HistoTransDlg *_t = static_cast<DIP_HistoTransDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnSelectHistoEq((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->OnSelectHistoShift((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->OnSelectHistoStretch((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->OnChangeShiftSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->OnChangeLimitsCombo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->OnChangeLimitsSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->OnPreviewCB((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DIP_HistoTransDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DIP_HistoTransDlg.data,
      qt_meta_data_DIP_HistoTransDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DIP_HistoTransDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DIP_HistoTransDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DIP_HistoTransDlg.stringdata0))
        return static_cast<void*>(const_cast< DIP_HistoTransDlg*>(this));
    if (!strcmp(_clname, "Ui::HistoTransDlg"))
        return static_cast< Ui::HistoTransDlg*>(const_cast< DIP_HistoTransDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int DIP_HistoTransDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
