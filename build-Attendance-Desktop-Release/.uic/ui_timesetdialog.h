/********************************************************************************
** Form generated from reading UI file 'timesetdialog.ui'
**
** Created: Thu Apr 28 22:52:40 2016
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMESETDIALOG_H
#define UI_TIMESETDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_timeSetDialog
{
public:
    QTimeEdit *startTimeEdit;
    QTimeEdit *endTimeEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTimeEdit *spliteTimeEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *timeSetDialog)
    {
        if (timeSetDialog->objectName().isEmpty())
            timeSetDialog->setObjectName(QString::fromUtf8("timeSetDialog"));
        timeSetDialog->resize(376, 241);
        startTimeEdit = new QTimeEdit(timeSetDialog);
        startTimeEdit->setObjectName(QString::fromUtf8("startTimeEdit"));
        startTimeEdit->setGeometry(QRect(160, 50, 118, 22));
        endTimeEdit = new QTimeEdit(timeSetDialog);
        endTimeEdit->setObjectName(QString::fromUtf8("endTimeEdit"));
        endTimeEdit->setGeometry(QRect(160, 130, 118, 22));
        label = new QLabel(timeSetDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 60, 54, 12));
        label_2 = new QLabel(timeSetDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 140, 54, 12));
        label_3 = new QLabel(timeSetDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 100, 54, 12));
        spliteTimeEdit = new QTimeEdit(timeSetDialog);
        spliteTimeEdit->setObjectName(QString::fromUtf8("spliteTimeEdit"));
        spliteTimeEdit->setGeometry(QRect(160, 90, 118, 22));
        pushButton = new QPushButton(timeSetDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 180, 75, 23));

        retranslateUi(timeSetDialog);

        QMetaObject::connectSlotsByName(timeSetDialog);
    } // setupUi

    void retranslateUi(QDialog *timeSetDialog)
    {
        timeSetDialog->setWindowTitle(QApplication::translate("timeSetDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("timeSetDialog", "\350\265\267\345\247\213\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("timeSetDialog", "\347\273\223\346\235\237\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("timeSetDialog", "\350\277\237\345\210\260\346\210\252\346\255\242", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("timeSetDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class timeSetDialog: public Ui_timeSetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMESETDIALOG_H
