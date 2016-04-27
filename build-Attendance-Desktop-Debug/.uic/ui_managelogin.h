/********************************************************************************
** Form generated from reading UI file 'managelogin.ui'
**
** Created: Wed Apr 27 11:14:58 2016
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGELOGIN_H
#define UI_MANAGELOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Managelogin
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *username;
    QLineEdit *password;
    QLabel *label_3;

    void setupUi(QDialog *Managelogin)
    {
        if (Managelogin->objectName().isEmpty())
            Managelogin->setObjectName(QString::fromUtf8("Managelogin"));
        Managelogin->resize(400, 300);
        pushButton = new QPushButton(Managelogin);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 170, 75, 23));
        pushButton_2 = new QPushButton(Managelogin);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 170, 75, 23));
        pushButton_3 = new QPushButton(Managelogin);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(80, 210, 75, 23));
        pushButton_4 = new QPushButton(Managelogin);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(200, 210, 75, 23));
        label = new QLabel(Managelogin);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 80, 54, 12));
        label_2 = new QLabel(Managelogin);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 120, 54, 12));
        username = new QLineEdit(Managelogin);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(190, 80, 113, 20));
        password = new QLineEdit(Managelogin);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(190, 120, 113, 20));
        label_3 = new QLabel(Managelogin);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 10, 201, 31));

        retranslateUi(Managelogin);

        QMetaObject::connectSlotsByName(Managelogin);
    } // setupUi

    void retranslateUi(QDialog *Managelogin)
    {
        Managelogin->setWindowTitle(QApplication::translate("Managelogin", "\347\231\273\351\231\206\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Managelogin", "\346\226\260\345\242\236", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Managelogin", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Managelogin", "\346\237\245\346\211\276", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Managelogin", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Managelogin", "\347\224\250\346\210\267\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Managelogin", "\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Managelogin", "        \347\224\250\346\210\267\347\256\241\347\220\206\347\225\214\351\235\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Managelogin: public Ui_Managelogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGELOGIN_H
