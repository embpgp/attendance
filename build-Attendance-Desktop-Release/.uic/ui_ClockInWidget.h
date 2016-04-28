/********************************************************************************
** Form generated from reading UI file 'ClockInWidget.ui'
**
** Created: Thu Apr 28 22:52:40 2016
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOCKINWIDGET_H
#define UI_CLOCKINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "rotatenumberlabel.h"

QT_BEGIN_NAMESPACE

class Ui_widget
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *yearNumber;
    QLabel *label_2;
    QLCDNumber *monthNumber;
    QLabel *label_3;
    QLCDNumber *dayNumber;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_3;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    RotateNumberLabel *hourLabel;
    RotateNumberLabel *minuteLabel;
    QLCDNumber *secondNumber;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *verticalSpacer_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *cardIdEdit;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    QLabel *label_6;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *widget)
    {
        if (widget->objectName().isEmpty())
            widget->setObjectName(QString::fromUtf8("widget"));
        widget->resize(621, 331);
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 30, 503, 27));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout_5->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        yearNumber = new QLCDNumber(layoutWidget);
        yearNumber->setObjectName(QString::fromUtf8("yearNumber"));
        yearNumber->setDigitCount(4);

        horizontalLayout->addWidget(yearNumber);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        monthNumber = new QLCDNumber(layoutWidget);
        monthNumber->setObjectName(QString::fromUtf8("monthNumber"));
        monthNumber->setDigitCount(2);

        horizontalLayout->addWidget(monthNumber);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        dayNumber = new QLCDNumber(layoutWidget);
        dayNumber->setObjectName(QString::fromUtf8("dayNumber"));
        dayNumber->setDigitCount(2);

        horizontalLayout->addWidget(dayNumber);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout->addWidget(label_7);


        horizontalLayout_5->addLayout(horizontalLayout);

        horizontalSpacer_3 = new QSpacerItem(268, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        layoutWidget1 = new QWidget(widget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(21, 71, 551, 181));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalSpacer_3 = new QSpacerItem(20, 48, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_8->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        hourLabel = new RotateNumberLabel(layoutWidget1);
        hourLabel->setObjectName(QString::fromUtf8("hourLabel"));
        hourLabel->setMinimumSize(QSize(48, 45));

        horizontalLayout_2->addWidget(hourLabel);

        minuteLabel = new RotateNumberLabel(layoutWidget1);
        minuteLabel->setObjectName(QString::fromUtf8("minuteLabel"));
        minuteLabel->setMinimumSize(QSize(48, 45));

        horizontalLayout_2->addWidget(minuteLabel);

        secondNumber = new QLCDNumber(layoutWidget1);
        secondNumber->setObjectName(QString::fromUtf8("secondNumber"));
        secondNumber->setMaximumSize(QSize(16777215, 24));
        secondNumber->setDigitCount(2);

        horizontalLayout_2->addWidget(secondNumber);


        horizontalLayout_8->addLayout(horizontalLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 48, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_8->addItem(verticalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalSpacer = new QSpacerItem(198, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalSpacer_5 = new QSpacerItem(18, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_7->addItem(verticalSpacer_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        nameEdit = new QLineEdit(layoutWidget1);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        horizontalLayout_4->addWidget(nameEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        cardIdEdit = new QLineEdit(layoutWidget1);
        cardIdEdit->setObjectName(QString::fromUtf8("cardIdEdit"));

        horizontalLayout_3->addWidget(cardIdEdit);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_7->addLayout(verticalLayout);

        verticalSpacer_6 = new QSpacerItem(18, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_7->addItem(verticalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_7);


        horizontalLayout_6->addLayout(verticalLayout_2);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_6->addItem(verticalSpacer_7);

        horizontalSpacer_5 = new QSpacerItem(148, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        verticalSpacer = new QSpacerItem(20, 158, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_6->addItem(verticalSpacer);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        verticalSpacer_2 = new QSpacerItem(20, 148, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_6->addItem(verticalSpacer_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        retranslateUi(widget);

        QMetaObject::connectSlotsByName(widget);
    } // setupUi

    void retranslateUi(QWidget *widget)
    {
        label->setText(QApplication::translate("widget", "\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("widget", "\345\271\264", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("widget", "\346\234\210", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("widget", "\346\227\245", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("widget", "\345\247\223\345\220\215", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("widget", "\345\215\241\345\217\267", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("widget", "\347\205\247\347\211\207\345\214\272\345\237\237", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(widget);
    } // retranslateUi

};

namespace Ui {
    class widget: public Ui_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOCKINWIDGET_H
