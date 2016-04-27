#include "login.h"
#include "ui_login.h"
#include <QDebug>
#include <QMessageBox>
#include "MainWidget.h"
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    DBControl::Create();
    ui->setupUi(this);
    ui->password->setEchoMode(QLineEdit::Password);
    w = NULL;
}
int login::errorcount = 0;

login::~login()
{
    delete ui;
    delete w;
}

void login::on_pushButton_clicked()
{
    if(ui->username->text() == "" || ui->password->text() == "")
    {
        QMessageBox::warning(this, tr("提示"), tr("您输入的用户名或者密码为空，请重新输入！"));
        return;
    }

    if(DBLogin::findPassword(ui->username->text()) == ui->password->text())
    {
        QMessageBox::information(this, tr("提示框"), tr("欢迎您，%1").arg(ui->username->text()));
        w = new MainWidget();
        w->show();
        this->hide();
    }
    else
    {
        login::errorcount++;
        if(login::errorcount >= 3)
        {
            QMessageBox::warning(this, tr("温馨提示"), tr("您输入的用户名或者密码错误，超过3次，结束本次登陆"));
            this->close();
        }
        else
        {
            QMessageBox::warning(this, tr("温馨提示"), tr("您输入的用户名或者密码错误%1次").arg(login::errorcount));
        }
    }
}

void login::on_pushButton_2_clicked()
{
    this->close();
}
