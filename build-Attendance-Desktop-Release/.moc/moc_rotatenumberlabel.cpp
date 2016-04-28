/****************************************************************************
** Meta object code from reading C++ file 'rotatenumberlabel.h'
**
** Created: Thu Apr 28 22:53:51 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Attendance/rotatenumberlabel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rotatenumberlabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RotateNumberLabel[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   19,   18,   18, 0x0a,
      39,   37,   18,   18, 0x0a,
      54,   37,   18,   18, 0x0a,
      74,   18,   18,   18, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_RotateNumberLabel[] = {
    "RotateNumberLabel\0\0fps\0setSpeed(int)\0"
    "n\0setNumber(int)\0motionToNumber(int)\0"
    "onTimer()\0"
};

const QMetaObject RotateNumberLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_RotateNumberLabel,
      qt_meta_data_RotateNumberLabel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RotateNumberLabel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RotateNumberLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RotateNumberLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RotateNumberLabel))
        return static_cast<void*>(const_cast< RotateNumberLabel*>(this));
    return QLabel::qt_metacast(_clname);
}

int RotateNumberLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setSpeed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: setNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: motionToNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: onTimer(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
