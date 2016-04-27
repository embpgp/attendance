#include "managelogin.h"
#include "ui_managelogin.h"

Managelogin::Managelogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Managelogin)
{
    ui->setupUi(this);
}

Managelogin::~Managelogin()
{
    delete ui;
}

//新增
void Managelogin::on_pushButton_clicked()
{
    if(ui->username->text() == "" || ui->password->text() == "")
    {
        QMessageBox::warning(this, tr("提示"), tr("您输入的要增加的用户名或者密码为空，请重新输入！"));
        return;
    }

    if(DBLogin::findPassword(ui->username->text()) != "")
    {
         QMessageBox::warning(this, tr("提示"), tr("您输入的用户名已经存在，请更换另一个！"));
         return;
    }
    DBLogin::addUsername(ui->username->text(), ui->password->text());
    QMessageBox::information(this,tr("提示"),tr("创建新的账户成功！"));
    this->close();
}

//删除
void Managelogin::on_pushButton_2_clicked()
{
    if(ui->username->text() == "")
    {
        QMessageBox::warning(this, tr("提示"), tr("您输入的要删除的用户名为空，请重新输入！"));
        return;
    }
    if(DBLogin::findPassword(ui->username->text()) == "")
    {
        QMessageBox::warning(this, tr("提示"), tr("您输入的要删除的用户名不存在，请重新输入！"));
        return;
    }
    DBLogin::delUsername(ui->username->text());
    QMessageBox::information(this,tr("提示"),tr("删除账户成功！"));
    this->close();

}

//查询密码
void Managelogin::on_pushButton_3_clicked()
{
    if(ui->username->text() == "")
    {
        QMessageBox::warning(this, tr("提示"), tr("您输入的要查找的用户名为空，请重新输入！"));
        return;
    }
    if(DBLogin::findPassword(ui->username->text()) == "")
    {
        QMessageBox::warning(this, tr("提示"), tr("您输入的要查找的用户名不存在，请重新输入！"));
        return;
    }
    QMessageBox::information(this,tr("提示"),tr("您查找的用户名：%1,密码为：%2").arg(ui->username->text()).arg(DBLogin::findPassword(ui->username->text())));
    this->close();

}

//修改
void Managelogin::on_pushButton_4_clicked()
{
    if(ui->username->text() == "")
    {
        QMessageBox::warning(this, tr("提示"), tr("您输入的要修改的用户名为空，请重新输入！"));
        return;
    }
    if(DBLogin::findPassword(ui->username->text()) == "")
    {
        QMessageBox::warning(this, tr("提示"), tr("您输入的要修改的用户名不存在，请重新输入！"));
        return;
    }
    DBLogin::updateUsername(ui->username->text(), ui->password->text());
    QMessageBox::information(this,tr("提示"),tr("您修改的的用户名：%1,新的密码为：%2").arg(ui->username->text()).arg(DBLogin::findPassword(ui->username->text())));
    this->close();
}
