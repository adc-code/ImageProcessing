/****************************************************************************
** Meta object code from reading C++ file 'DIP_LogExpTransDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "DIP_LogExpTransDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DIP_LogExpTransDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DIP_LogExpTransDlg_t {
    QByteArrayData data[7];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DIP_LogExpTransDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DIP_LogExpTransDlg_t qt_meta_stringdata_DIP_LogExpTransDlg = {
    {
QT_MOC_LITERAL(0, 0, 18), // "DIP_LogExpTransDlg"
QT_MOC_LITERAL(1, 19, 13), // "OnUpdateLogRB"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 6), // "bState"
QT_MOC_LITERAL(4, 41, 13), // "OnUpdateExpRB"
QT_MOC_LITERAL(5, 55, 11), // "OnPreviewCB"
QT_MOC_LITERAL(6, 67, 6) // "iState"

    },
    "DIP_LogExpTransDlg\0OnUpdateLogRB\0\0"
    "bState\0OnUpdateExpRB\0OnPreviewCB\0"
    "iState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DIP_LogExpTransDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       4,    1,   32,    2, 0x08 /* Private */,
       5,    1,   35,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void DIP_LogExpTransDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DIP_LogExpTransDlg *_t = static_cast<DIP_LogExpTransDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnUpdateLogRB((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->OnUpdateExpRB((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->OnPreviewCB((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DIP_LogExpTransDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DIP_LogExpTransDlg.data,
      qt_meta_data_DIP_LogExpTransDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DIP_LogExpTransDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DIP_LogExpTransDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DIP_LogExpTransDlg.stringdata0))
        return static_cast<void*>(const_cast< DIP_LogExpTransDlg*>(this));
    if (!strcmp(_clname, "Ui::LogExpTransDialog"))
        return static_cast< Ui::LogExpTransDialog*>(const_cast< DIP_LogExpTransDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int DIP_LogExpTransDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
