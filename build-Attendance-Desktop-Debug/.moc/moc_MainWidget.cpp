/****************************************************************************
** Meta object code from reading C++ file 'MainWidget.h'
**
** Created: Thu Apr 28 22:50:45 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Attendance/MainWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      40,   35,   11,   11, 0x08,
      55,   11,   11,   11, 0x08,
      62,   11,   11,   11, 0x08,
      82,   12,   11,   11, 0x08,
     104,   11,   11,   11, 0x08,
     139,   11,   11,   11, 0x08,
     172,   11,   11,   11, 0x08,
     199,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWidget[] = {
    "MainWidget\0\0id\0newCard(QByteArray)\0"
    "port\0start(QString)\0stop()\0"
    "onSerialDataReady()\0onNewCard(QByteArray)\0"
    "on_refreshSerialPortList_clicked()\0"
    "on_openCloseSerialPort_clicked()\0"
    "on_setTimeButton_clicked()\0"
    "on_pushButton_clicked()\0"
};

const QMetaObject MainWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainWidget,
      qt_meta_data_MainWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWidget))
        return static_cast<void*>(const_cast< MainWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newCard((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: start((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: stop(); break;
        case 3: onSerialDataReady(); break;
        case 4: onNewCard((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: on_refreshSerialPortList_clicked(); break;
        case 6: on_openCloseSerialPort_clicked(); break;
        case 7: on_setTimeButton_clicked(); break;
        case 8: on_pushButton_clicked(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MainWidget::newCard(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
