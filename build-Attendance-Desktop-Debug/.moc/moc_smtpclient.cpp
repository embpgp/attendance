/****************************************************************************
** Meta object code from reading C++ file 'smtpclient.h'
**
** Created: Tue Apr 26 22:43:50 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Attendance/sendemailapi/smtpclient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'smtpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SmtpClient[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      41,   35,   11,   11, 0x09,
      96,   90,   11,   11, 0x09,
     138,   11,   11,   11, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_SmtpClient[] = {
    "SmtpClient\0\0e\0smtpError(SmtpError)\0"
    "state\0socketStateChanged(QAbstractSocket::SocketState)\0"
    "error\0socketError(QAbstractSocket::SocketError)\0"
    "socketReadyRead()\0"
};

const QMetaObject SmtpClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SmtpClient,
      qt_meta_data_SmtpClient, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SmtpClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SmtpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SmtpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SmtpClient))
        return static_cast<void*>(const_cast< SmtpClient*>(this));
    return QObject::qt_metacast(_clname);
}

int SmtpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: smtpError((*reinterpret_cast< SmtpError(*)>(_a[1]))); break;
        case 1: socketStateChanged((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        case 2: socketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 3: socketReadyRead(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void SmtpClient::smtpError(SmtpError _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE