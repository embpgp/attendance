/********************************************************************************
** Form generated from reading UI file 'ManageWidget.ui'
**
** Created: Sun May 8 14:38:07 2016
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEWIDGET_H
#define UI_MANAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageWidget
{
public:
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addBtn;
    QPushButton *delBtn;
    QPushButton *modifyBtn;
    QTreeWidget *userTable;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *refreshBtn;
    QTreeWidget *logTable;

    void setupUi(QWidget *ManageWidget)
    {
        if (ManageWidget->objectName().isEmpty())
            ManageWidget->setObjectName(QString::fromUtf8("ManageWidget"));
        ManageWidget->resize(683, 384);
        horizontalLayout_3 = new QHBoxLayout(ManageWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox = new QGroupBox(ManageWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        addBtn = new QPushButton(groupBox);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));

        horizontalLayout_2->addWidget(addBtn);

        delBtn = new QPushButton(groupBox);
        delBtn->setObjectName(QString::fromUtf8("delBtn"));

        horizontalLayout_2->addWidget(delBtn);

        modifyBtn = new QPushButton(groupBox);
        modifyBtn->setObjectName(QString::fromUtf8("modifyBtn"));

        horizontalLayout_2->addWidget(modifyBtn);


        verticalLayout->addLayout(horizontalLayout_2);

        userTable = new QTreeWidget(groupBox);
        userTable->setObjectName(QString::fromUtf8("userTable"));

        verticalLayout->addWidget(userTable);


        horizontalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(ManageWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        refreshBtn = new QPushButton(groupBox_2);
        refreshBtn->setObjectName(QString::fromUtf8("refreshBtn"));

        horizontalLayout->addWidget(refreshBtn);


        verticalLayout_2->addLayout(horizontalLayout);

        logTable = new QTreeWidget(groupBox_2);
        logTable->setObjectName(QString::fromUtf8("logTable"));

        verticalLayout_2->addWidget(logTable);


        horizontalLayout_3->addWidget(groupBox_2);


        retranslateUi(ManageWidget);

        QMetaObject::connectSlotsByName(ManageWidget);
    } // setupUi

    void retranslateUi(QWidget *ManageWidget)
    {
        groupBox->setTitle(QApplication::translate("ManageWidget", "\345\255\246\347\224\237\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        addBtn->setText(QApplication::translate("ManageWidget", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        delBtn->setText(QApplication::translate("ManageWidget", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        modifyBtn->setText(QApplication::translate("ManageWidget", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = userTable->headerItem();
        ___qtreewidgetitem->setText(5, QApplication::translate("ManageWidget", "\351\202\256\347\256\261", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(4, QApplication::translate("ManageWidget", "\345\255\246\345\217\267", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(3, QApplication::translate("ManageWidget", "\346\200\247\345\210\253", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(2, QApplication::translate("ManageWidget", "\345\247\223\345\220\215", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("ManageWidget", "\345\215\241\345\217\267", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("ManageWidget", "\347\274\226\345\217\267", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("ManageWidget", "\347\255\276\345\210\260\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        refreshBtn->setText(QApplication::translate("ManageWidget", "\345\210\267\346\226\260", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem1 = logTable->headerItem();
        ___qtreewidgetitem1->setText(6, QApplication::translate("ManageWidget", "\346\227\251\351\200\200", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(5, QApplication::translate("ManageWidget", "\350\277\237\345\210\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(4, QApplication::translate("ManageWidget", "\345\255\246\345\217\267", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(3, QApplication::translate("ManageWidget", "\346\200\247\345\210\253", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(2, QApplication::translate("ManageWidget", "\345\215\241\345\217\267", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(1, QApplication::translate("ManageWidget", "\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(0, QApplication::translate("ManageWidget", "\347\274\226\345\217\267", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(ManageWidget);
    } // retranslateUi

};

namespace Ui {
    class ManageWidget: public Ui_ManageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEWIDGET_H
