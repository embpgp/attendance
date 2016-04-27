#ifndef LOGIN_H
#define LOGIN_H
#include "MainWidget.h"
#include <QDialog>
#include "DBControl.h"
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();
    MainWidget *w;
    static int errorcount;    //三次密码错误结束认证
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
