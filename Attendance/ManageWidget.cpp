#include "ManageWidget.h"
#include "ui_ManageWidget.h"
#include <QTreeWidgetItem>
#include <QMessageBox>
#include <QDebug>
ManageWidget::ManageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManageWidget),
    usrEditDlg(new UserEditDialog)
{
    ui->setupUi(this);

    //设置主窗体背景颜色
    this->setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(192,100,123));
    this->setPalette(palette);

    updateUserTable();


}

ManageWidget::~ManageWidget()
{
    delete ui;
}

void ManageWidget::onCardReaded(const QString &cardid)
{
    usrEditDlg->setCardId(cardid);
}

void ManageWidget::updateUserTable() //更新用户表
{
    ui->userTable->clear();
    DBCard c;
    if(c.first())
    {
        QTreeWidgetItem *item;
        do {
            item = new QTreeWidgetItem(ui->userTable);
            item->setText(0, QString::number(c.id()));
            item->setText(1, c.cardid());
            item->setText(2, c.name());
            item->setText(3, c.gender());      //++++++++++++++++++++++++++++
            item->setText(4, c.occupation());  //++++++++++++++++++++++++++++
            item->setText(5, c.mailAddress());
            qDebug()<<"Update UserTable Successful";
        } while(c.next());
    }
}


void ManageWidget::updateLogTable()  //更新登录表
{

    ui->logTable->clear();

    DBLog l;

    if(l.first())
    {
        QTreeWidgetItem *item;

        do {
            item = new QTreeWidgetItem(ui->logTable);
            item->setText(0, QString::number(l.id()));
            item->setText(1, l.date().toString("yyyy-MM-dd hh:mm:ss"));
            item->setText(2, l.cardid());
            item->setText(3, l.gender());      //++++++++++++++++++++++++++++
            item->setText(4, l.occupation());  //++++++++++++++++++++++++++++
            item->setText(5, l.arriveLate());
            item->setText(6, l.leaveEarly());        
        } while(l.next());
    }
}

void ManageWidget::on_addBtn_clicked()    // 添加卡片
{
    if(!usrEditDlg->isHidden())
        return;
    usrEditDlg->setCardId("");
    usrEditDlg->setName("");
    if(usrEditDlg->exec() == QDialog::Rejected) // !!!!!!!!!!!!!!!!!
        return;
    if(usrEditDlg->cardId().isEmpty())
    {
        QMessageBox::warning(this, tr("警告"), tr("卡号不能为空!"));
        return;
    }
    if(usrEditDlg->name().isEmpty())
    {
        QMessageBox::warning(this, tr("警告"), tr("用户名不能为空!"));
        return;
    }
    //  qDebug()<<usrEditDlg->cardId()<<usrEditDlg->name()<<usrEditDlg->gender()<<usrEditDlg->occupation();

    if(DBCard::addCard(usrEditDlg->cardId(), usrEditDlg->name(), usrEditDlg->gender(), usrEditDlg->occupation(), usrEditDlg->mailAddress()))
    {
        //在每一个员工录取进来后就进行次数数据库的记录增加,直接初始化为0，0，0
        DBAttendance::addlog(usrEditDlg->cardId(),usrEditDlg->name(),0,0,0);
        QMessageBox::warning(this, tr("提示"), tr("添加成功!"));
    }
    else
    {
        QMessageBox::warning(this, tr("提示"), tr("添加出错!"));
    }
        //+++++++++++++++++++++
    updateUserTable();
}

void ManageWidget::on_delBtn_clicked()    // 删除卡片
{
    QList<QTreeWidgetItem *> selItems = ui->userTable->selectedItems();
    while(selItems.count())
    {
        QTreeWidgetItem *item = selItems.first();
        DBCard::delCard(item->text(1));
        delete item;
        selItems.removeFirst();
    }
}

void ManageWidget::on_modifyBtn_clicked() // 修改卡片
{
    QList<QTreeWidgetItem *> selItems = ui->userTable->selectedItems();
    if(selItems.count())
    {
        QTreeWidgetItem *item = selItems.first();
        if(!usrEditDlg->isHidden())
            return;
        usrEditDlg->setCardId(item->text(1));
        usrEditDlg->setName(item->text(2));
        if(usrEditDlg->exec() == QDialog::Rejected)
            return;
        DBCard::updateName(usrEditDlg->cardId(), usrEditDlg->name(),usrEditDlg->gender(), usrEditDlg->occupation(), usrEditDlg->mailAddress());
        updateUserTable();
    }
}



void ManageWidget::on_refreshBtn_clicked() //刷新登录表
{
    updateLogTable();
}


void ManageWidget::on_refreshBtn_released()
{

}


