/****************************************************************************
** Meta object code from reading C++ file 'AddTransactionForm.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../BankSystem_TP/AddTransactionForm.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AddTransactionForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AddingTransaction_t {
    const uint offsetsAndSize[10];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_AddingTransaction_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_AddingTransaction_t qt_meta_stringdata_AddingTransaction = {
    {
QT_MOC_LITERAL(0, 17), // "AddingTransaction"
QT_MOC_LITERAL(18, 13), // "ClickedButton"
QT_MOC_LITERAL(32, 0), // ""
QT_MOC_LITERAL(33, 21), // "AccTypesMenuActivated"
QT_MOC_LITERAL(55, 23) // "TransTypesMenuActivated"

    },
    "AddingTransaction\0ClickedButton\0\0"
    "AccTypesMenuActivated\0TransTypesMenuActivated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddingTransaction[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x0a,    1 /* Public */,
       3,    1,   33,    2, 0x0a,    2 /* Public */,
       4,    1,   36,    2, 0x0a,    4 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void AddingTransaction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AddingTransaction *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ClickedButton(); break;
        case 1: _t->AccTypesMenuActivated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->TransTypesMenuActivated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject AddingTransaction::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_AddingTransaction.offsetsAndSize,
    qt_meta_data_AddingTransaction,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_AddingTransaction_t
, QtPrivate::TypeAndForceComplete<AddingTransaction, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *AddingTransaction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddingTransaction::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AddingTransaction.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AddingTransaction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
