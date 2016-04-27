#ifndef MANAGEWIDGET_H
#define MANAGEWIDGET_H

#include <QWidget>
#include "DBControl.h"
#include "UserEditDialog.h"



namespace Ui {
    class ManageWidget;
}

class ManageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ManageWidget(QWidget *parent = 0);
    ~ManageWidget();

public slots:
    void onCardReaded(const QString &cardid);

private:
    Ui::ManageWidget *ui;
    UserEditDialog *usrEditDlg;

private slots:
    void on_refreshBtn_clicked();
    void on_modifyBtn_clicked();
    void on_delBtn_clicked();
    void on_addBtn_clicked();
    void updateUserTable();
    void updateLogTable();
    void on_refreshBtn_released();
};

#endif // MANAGEWIDGET_H
