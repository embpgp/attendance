/********************************************************************************
** Form generated from reading UI file 'MainWidget.ui'
**
** Created: Sun May 8 14:38:07 2016
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <selectwidget.h>
#include "ClockInWidget.h"
#include "ManageWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *spacer;
    QPushButton *pushButton;
    QPushButton *setTimeButton;
    QLabel *label_2;
    QComboBox *serialPortList;
    QPushButton *refreshSerialPortList;
    QPushButton *openCloseSerialPort;
    QTabWidget *tabWidget;
    ClockInWidget *clockInPage;
    ManageWidget *manPage;
    SelectWidget *scanPage;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(712, 451);
        verticalLayout = new QVBoxLayout(MainWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(MainWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setPixmap(QPixmap(QString::fromUtf8(":/pic/title.png")));

        horizontalLayout->addWidget(label);

        spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacer);

        pushButton = new QPushButton(MainWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        setTimeButton = new QPushButton(MainWidget);
        setTimeButton->setObjectName(QString::fromUtf8("setTimeButton"));

        horizontalLayout->addWidget(setTimeButton);

        label_2 = new QLabel(MainWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        serialPortList = new QComboBox(MainWidget);
        serialPortList->setObjectName(QString::fromUtf8("serialPortList"));

        horizontalLayout->addWidget(serialPortList);

        refreshSerialPortList = new QPushButton(MainWidget);
        refreshSerialPortList->setObjectName(QString::fromUtf8("refreshSerialPortList"));

        horizontalLayout->addWidget(refreshSerialPortList);

        openCloseSerialPort = new QPushButton(MainWidget);
        openCloseSerialPort->setObjectName(QString::fromUtf8("openCloseSerialPort"));

        horizontalLayout->addWidget(openCloseSerialPort);


        verticalLayout->addLayout(horizontalLayout);

        tabWidget = new QTabWidget(MainWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        clockInPage = new ClockInWidget();
        clockInPage->setObjectName(QString::fromUtf8("clockInPage"));
        tabWidget->addTab(clockInPage, QString());
        manPage = new ManageWidget();
        manPage->setObjectName(QString::fromUtf8("manPage"));
        tabWidget->addTab(manPage, QString());
        scanPage = new SelectWidget();
        scanPage->setObjectName(QString::fromUtf8("scanPage"));
        tabWidget->addTab(scanPage, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(MainWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        pushButton->setText(QApplication::translate("MainWidget", "\347\231\273\351\231\206\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        setTimeButton->setText(QApplication::translate("MainWidget", "\350\256\276\347\275\256\347\255\276\345\210\260\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWidget", "CommList", 0, QApplication::UnicodeUTF8));
        refreshSerialPortList->setText(QApplication::translate("MainWidget", "\345\210\267\346\226\260", 0, QApplication::UnicodeUTF8));
        openCloseSerialPort->setText(QApplication::translate("MainWidget", "\346\211\223\345\274\200", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(clockInPage), QApplication::translate("MainWidget", "Clock in", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(manPage), QApplication::translate("MainWidget", "Manage", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(scanPage), QApplication::translate("MainWidget", "scan", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
