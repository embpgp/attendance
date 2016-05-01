/****************************************************************************
** Meta object code from reading C++ file 'ClockInWidget.h'
**
** Created: Sat Apr 30 16:18:15 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Attendance/ClockInWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClockInWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ClockInWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   15,   14,   14, 0x0a,
      44,   14,   14,   14, 0x08,
      61,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ClockInWidget[] = {
    "ClockInWidget\0\0cardid\0onCardReaded(QString)\0"
    "updateDateTime()\0updateTime()\0"
};

const QMetaObject ClockInWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ClockInWidget,
      qt_meta_data_ClockInWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ClockInWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ClockInWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ClockInWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClockInWidget))
        return static_cast<void*>(const_cast< ClockInWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ClockInWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onCardReaded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: updateDateTime(); break;
        case 2: updateTime(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
