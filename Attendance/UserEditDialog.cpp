#include "UserEditDialog.h"
#include "ui_UserEditDialog.h"
#include <QFileDialog>
UserEditDialog::UserEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserEditDialog)
{
    ui->setupUi(this);

}

UserEditDialog::~UserEditDialog()
{
    delete ui;
}

QString UserEditDialog::cardId() const //返回卡号
{
    return ui->cardIdEdit->text();
}

QString UserEditDialog::name() const //返回姓名
{
    return ui->nameEdit->text();
}

QString UserEditDialog::gender() const //返回性别
{
    return ui->genderEdit->text();
}

QString UserEditDialog::occupation() const //返回职业
{
    return ui->occupationEdit->text();
}

QString UserEditDialog::mailAddress() const //返回邮件地址
{
    return ui->mailAddressEdit->text();
}


void UserEditDialog::setCardId(const QString &id) //读卡时自动添加卡号
{
    ui->cardIdEdit->setText(id);
}

void UserEditDialog::setName(const QString &name) //读卡时自动添加名字
{
    ui->nameEdit->setText(name);
}


void UserEditDialog::on_pushButton_clicked()  //添加图片
{
    QString filename = QFileDialog::getOpenFileName(this,QObject::tr("图片文件对话框"),"C:",
                       QObject::tr("图片文件(*png *jpg)"));

    QPixmap pixmap;

    pixmap.load(filename);

    ui->label_5->setScaledContents(true);
    ui->label_5->setPixmap(pixmap);

}

