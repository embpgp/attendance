/********************************************************************************
** Form generated from reading UI file 'Selectwidget.ui'
**
** Created: Sat Apr 30 16:17:43 2016
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTWIDGET_H
#define UI_SELECTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectWidget
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *name;
    QPushButton *select;
    QTreeWidget *showtable;

    void setupUi(QWidget *SelectWidget)
    {
        if (SelectWidget->objectName().isEmpty())
            SelectWidget->setObjectName(QString::fromUtf8("SelectWidget"));
        SelectWidget->resize(639, 371);
        groupBox = new QGroupBox(SelectWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 591, 351));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 16, 36, 20));
        name = new QLineEdit(groupBox);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(100, 10, 291, 31));
        select = new QPushButton(groupBox);
        select->setObjectName(QString::fromUtf8("select"));
        select->setGeometry(QRect(440, 10, 75, 31));
        showtable = new QTreeWidget(groupBox);
        showtable->setObjectName(QString::fromUtf8("showtable"));
        showtable->setGeometry(QRect(0, 60, 591, 261));

        retranslateUi(SelectWidget);

        QMetaObject::connectSlotsByName(SelectWidget);
    } // setupUi

    void retranslateUi(QWidget *SelectWidget)
    {
        SelectWidget->setWindowTitle(QApplication::translate("SelectWidget", "scan", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("SelectWidget", "\346\237\245\350\257\242\346\241\206", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SelectWidget", "\345\220\215\345\255\227\357\274\232", 0, QApplication::UnicodeUTF8));
        select->setText(QApplication::translate("SelectWidget", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = showtable->headerItem();
        ___qtreewidgetitem->setText(5, QApplication::translate("SelectWidget", "\347\274\272\345\213\244\346\254\241\346\225\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(4, QApplication::translate("SelectWidget", "\346\227\251\351\200\200\346\254\241\346\225\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(3, QApplication::translate("SelectWidget", "\350\277\237\345\210\260\346\254\241\346\225\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(2, QApplication::translate("SelectWidget", "\350\201\214\344\270\232", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("SelectWidget", "\346\200\247\345\210\253", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("SelectWidget", "\345\247\223\345\220\215", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SelectWidget: public Ui_SelectWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTWIDGET_H
