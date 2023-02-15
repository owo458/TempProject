/****************************************************************************
** Meta object code from reading C++ file 'intrinsic_param.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "intrinsic_param.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'intrinsic_param.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_intrinsic_param_t {
    QByteArrayData data[14];
    char stringdata0[344];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_intrinsic_param_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_intrinsic_param_t qt_meta_stringdata_intrinsic_param = {
    {
QT_MOC_LITERAL(0, 0, 15), // "intrinsic_param"
QT_MOC_LITERAL(1, 16, 31), // "on_pushButton_VideoLoad_clicked"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 30), // "on_pushButton_SavePath_clicked"
QT_MOC_LITERAL(4, 80, 36), // "on_textBrowser_VideoPath_text..."
QT_MOC_LITERAL(5, 117, 35), // "on_textBrowser_SavePath_textC..."
QT_MOC_LITERAL(6, 153, 39), // "on_textEdit_ChessHorizontal_t..."
QT_MOC_LITERAL(7, 193, 37), // "on_textEdit_ChessVertical_tex..."
QT_MOC_LITERAL(8, 231, 27), // "on_pushButton_Start_clicked"
QT_MOC_LITERAL(9, 259, 26), // "on_pushButton_exit_clicked"
QT_MOC_LITERAL(10, 286, 10), // "closeEvent"
QT_MOC_LITERAL(11, 297, 12), // "QCloseEvent*"
QT_MOC_LITERAL(12, 310, 5), // "event"
QT_MOC_LITERAL(13, 316, 27) // "on_textEdit_FPS_textChanged"

    },
    "intrinsic_param\0on_pushButton_VideoLoad_clicked\0"
    "\0on_pushButton_SavePath_clicked\0"
    "on_textBrowser_VideoPath_textChanged\0"
    "on_textBrowser_SavePath_textChanged\0"
    "on_textEdit_ChessHorizontal_textChanged\0"
    "on_textEdit_ChessVertical_textChanged\0"
    "on_pushButton_Start_clicked\0"
    "on_pushButton_exit_clicked\0closeEvent\0"
    "QCloseEvent*\0event\0on_textEdit_FPS_textChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_intrinsic_param[] = {

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
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    1,   72,    2, 0x08 /* Private */,
      13,    0,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,

       0        // eod
};

void intrinsic_param::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        intrinsic_param *_t = static_cast<intrinsic_param *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_VideoLoad_clicked(); break;
        case 1: _t->on_pushButton_SavePath_clicked(); break;
        case 2: _t->on_textBrowser_VideoPath_textChanged(); break;
        case 3: _t->on_textBrowser_SavePath_textChanged(); break;
        case 4: _t->on_textEdit_ChessHorizontal_textChanged(); break;
        case 5: _t->on_textEdit_ChessVertical_textChanged(); break;
        case 6: _t->on_pushButton_Start_clicked(); break;
        case 7: _t->on_pushButton_exit_clicked(); break;
        case 8: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 9: _t->on_textEdit_FPS_textChanged(); break;
        default: ;
        }
    }
}

const QMetaObject intrinsic_param::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_intrinsic_param.data,
      qt_meta_data_intrinsic_param,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *intrinsic_param::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *intrinsic_param::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_intrinsic_param.stringdata0))
        return static_cast<void*>(const_cast< intrinsic_param*>(this));
    return QDialog::qt_metacast(_clname);
}

int intrinsic_param::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
