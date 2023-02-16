/****************************************************************************
** Meta object code from reading C++ file 'captureimg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../code/captureimg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'captureimg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CaptureImg_t {
    QByteArrayData data[14];
    char stringdata0[280];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CaptureImg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CaptureImg_t qt_meta_stringdata_CaptureImg = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CaptureImg"
QT_MOC_LITERAL(1, 11, 13), // "update_window"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 26), // "on_pushButton_Prev_clicked"
QT_MOC_LITERAL(4, 53, 26), // "on_pushButton_Next_clicked"
QT_MOC_LITERAL(5, 80, 31), // "on_pushButton_capture_1_clicked"
QT_MOC_LITERAL(6, 112, 7), // "checked"
QT_MOC_LITERAL(7, 120, 31), // "on_pushButton_capture_2_clicked"
QT_MOC_LITERAL(8, 152, 37), // "on_pushButton_CalculationTilt..."
QT_MOC_LITERAL(9, 190, 10), // "closeEvent"
QT_MOC_LITERAL(10, 201, 12), // "QCloseEvent*"
QT_MOC_LITERAL(11, 214, 5), // "event"
QT_MOC_LITERAL(12, 220, 29), // "on_pushButton_clear_1_clicked"
QT_MOC_LITERAL(13, 250, 29) // "on_pushButton_clear_2_clicked"

    },
    "CaptureImg\0update_window\0\0"
    "on_pushButton_Prev_clicked\0"
    "on_pushButton_Next_clicked\0"
    "on_pushButton_capture_1_clicked\0checked\0"
    "on_pushButton_capture_2_clicked\0"
    "on_pushButton_CalculationTilt_clicked\0"
    "closeEvent\0QCloseEvent*\0event\0"
    "on_pushButton_clear_1_clicked\0"
    "on_pushButton_clear_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CaptureImg[] = {

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
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    1,   62,    2, 0x08 /* Private */,
       7,    1,   65,    2, 0x08 /* Private */,
       8,    0,   68,    2, 0x08 /* Private */,
       9,    1,   69,    2, 0x08 /* Private */,
      12,    0,   72,    2, 0x08 /* Private */,
      13,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CaptureImg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CaptureImg *_t = static_cast<CaptureImg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update_window(); break;
        case 1: _t->on_pushButton_Prev_clicked(); break;
        case 2: _t->on_pushButton_Next_clicked(); break;
        case 3: _t->on_pushButton_capture_1_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_capture_2_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_CalculationTilt_clicked(); break;
        case 6: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_clear_1_clicked(); break;
        case 8: _t->on_pushButton_clear_2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject CaptureImg::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CaptureImg.data,
      qt_meta_data_CaptureImg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CaptureImg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CaptureImg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CaptureImg.stringdata0))
        return static_cast<void*>(const_cast< CaptureImg*>(this));
    return QWidget::qt_metacast(_clname);
}

int CaptureImg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
