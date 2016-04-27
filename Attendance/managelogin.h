#ifndef MANAGELOGIN_H
#define MANAGELOGIN_H
#include "DBControl.h"
#include <QDialog>
#include <QMessageBox>
namespace Ui {
class Managelogin;
}

class Managelogin : public QDialog
{
    Q_OBJECT

public:
    explicit Managelogin(QWidget *parent = 0);
    ~Managelogin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Managelogin *ui;
};

#endif // MANAGELOGIN_H
