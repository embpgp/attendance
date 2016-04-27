#-------------------------------------------------
#
# Project created by QtCreator 2012-07-02T19:49:48
#
#-------------------------------------------------

QT       += core gui sql network

TARGET = Attendance
TEMPLATE = app

OBJECTS_DIR = .obj
MOC_DIR = .moc
UI_DIR = .uic

INCLUDEPATH += .\
	../Attendance/include  \

!win32 {
LIBS +=  -L../Attendance/lib  \
         -lqextserialport
} else {
LIBS +=  -L../Attendance/lib  \
         -lqextserialportd1
}


SOURCES += main.cpp\
        MainWidget.cpp \
    ioportmanager.cpp \
    DBControl.cpp \
    ClockInWidget.cpp \
    ManageWidget.cpp \
    rotatenumberlabel.cpp \
    UserEditDialog.cpp \
    sendemailapi/emailaddress.cpp \
    sendemailapi/mimeattachment.cpp \
    sendemailapi/mimecontentformatter.cpp \
    sendemailapi/mimefile.cpp \
    sendemailapi/mimehtml.cpp \
    sendemailapi/mimeinlinefile.cpp \
    sendemailapi/mimemessage.cpp \
    sendemailapi/mimemultipart.cpp \
    sendemailapi/mimepart.cpp \
    sendemailapi/mimetext.cpp \
    sendemailapi/quotedprintable.cpp \
    sendemailapi/smtpclient.cpp \
    timesetdialog.cpp \
    login.cpp \
    managelogin.cpp

HEADERS  += \
    ioportManager.h \
    DBControl.h \
    ClockInWidget.h \
    ManageWidget.h \
    rotatenumberlabel.h \
    UserEditDialog.h \
    MainWidget.h \
    sendemailapi/emailaddress.h \
    sendemailapi/mimeattachment.h \
    sendemailapi/mimecontentformatter.h \
    sendemailapi/mimefile.h \
    sendemailapi/mimehtml.h \
    sendemailapi/mimeinlinefile.h \
    sendemailapi/mimemessage.h \
    sendemailapi/mimemultipart.h \
    sendemailapi/mimepart.h \
    sendemailapi/mimetext.h \
    sendemailapi/quotedprintable.h \
    sendemailapi/smtpclient.h \
    sendemailapi/smtpmime.h \
    timesetdialog.h \
    login.h \
    managelogin.h

FORMS    += MainWidget.ui \
    ClockInWidget.ui \
    ManageWidget.ui \
    UserEditDialog.ui \
    timesetdialog.ui \
    login.ui \
    managelogin.ui

RESOURCES += \
    res.qrc

linux-* {
    target.path = /root
    INSTALLS += target
}
