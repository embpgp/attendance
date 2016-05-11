/********************************************************************************
** Form generated from reading UI file 'UserEditDialog.ui'
**
** Created: Sun May 8 13:41:21 2016
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USEREDITDIALOG_H
#define UI_USEREDITDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserEditDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *genderEdit;
    QLineEdit *cardIdEdit;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *occupationEdit;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *nameEdit;
    QLabel *label_6;
    QLineEdit *mailAddressEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *UserEditDialog)
    {
        if (UserEditDialog->objectName().isEmpty())
            UserEditDialog->setObjectName(QString::fromUtf8("UserEditDialog"));
        UserEditDialog->resize(246, 373);
        layoutWidget = new QWidget(UserEditDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 10, 221, 351));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        genderEdit = new QLineEdit(layoutWidget);
        genderEdit->setObjectName(QString::fromUtf8("genderEdit"));

        gridLayout->addWidget(genderEdit, 3, 1, 1, 1);

        cardIdEdit = new QLineEdit(layoutWidget);
        cardIdEdit->setObjectName(QString::fromUtf8("cardIdEdit"));

        gridLayout->addWidget(cardIdEdit, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        occupationEdit = new QLineEdit(layoutWidget);
        occupationEdit->setObjectName(QString::fromUtf8("occupationEdit"));

        gridLayout->addWidget(occupationEdit, 4, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        nameEdit = new QLineEdit(layoutWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        gridLayout->addWidget(nameEdit, 2, 1, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        mailAddressEdit = new QLineEdit(layoutWidget);
        mailAddressEdit->setObjectName(QString::fromUtf8("mailAddressEdit"));

        gridLayout->addWidget(mailAddressEdit, 5, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(68, 58, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalSpacer_3 = new QSpacerItem(20, 58, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_2->addItem(verticalSpacer_3);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(300, 300));

        horizontalLayout_2->addWidget(label_5);

        verticalSpacer_2 = new QSpacerItem(20, 58, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_2->addItem(verticalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(108, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_3->addItem(verticalSpacer);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(UserEditDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), UserEditDialog, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), UserEditDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(UserEditDialog);
    } // setupUi

    void retranslateUi(QDialog *UserEditDialog)
    {
        UserEditDialog->setWindowTitle(QApplication::translate("UserEditDialog", "User Edit Dialog", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("UserEditDialog", "\345\247\223\345\220\215", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("UserEditDialog", "\345\215\241\345\217\267", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("UserEditDialog", "\345\255\246\345\217\267", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("UserEditDialog", "\346\200\247\345\210\253", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("UserEditDialog", "\351\202\256\347\256\261", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("UserEditDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("UserEditDialog", "\346\267\273\345\212\240\347\205\247\347\211\207", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UserEditDialog: public Ui_UserEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USEREDITDIALOG_H
