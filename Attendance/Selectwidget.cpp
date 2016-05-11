#include "Selectwidget.h"
#include "ui_Selectwidget.h"
#include "DBControl.h"
#include <QMessageBox>
#include <QDebug>
SelectWidget::SelectWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectWidget)
{
    ui->setupUi(this);
}

SelectWidget::~SelectWidget()
{
    delete ui;
}

void SelectWidget::on_select_clicked()
{
    ui->showtable->clear();
    QString cardid = DBCard::findCard(ui->name->text());
    if(cardid == "")
    {
        QMessageBox::warning(this,tr("提示"),tr("您输入的名字有误，请重新输入~"));
        return ;
    }


        QTreeWidgetItem *item;

        do {
            item = new QTreeWidgetItem(ui->showtable);
            item->setText(0, ui->name->text());
            item->setText(1, DBCard::findGender(cardid));
            item->setText(2, DBCard::findOccupation(cardid));
            item->setText(3, QString::number(DBAttendance::findarrTimes(cardid)));      //++++++++++++++++++++++++++++
            item->setText(4, QString::number(DBAttendance::findleaTimes(cardid)));  //++++++++++++++++++++++++++++
            item->setText(5, QString::number(DBAttendance::findabsTimes(cardid)));
        } while(0);

}

void SelectWidget::on_pushButton_clicked()
{
      ui->showtable->clear();

      DBAttendance att;

      if(att.first())
      {
        QTreeWidgetItem *item;


        do {

            item = new QTreeWidgetItem(ui->showtable);
            item->setText(0, DBCard::findName(att.cardid()));
            item->setText(1, DBCard::findGender(att.cardid()));
            item->setText(2, DBCard::findOccupation(att.cardid()));
            item->setText(3, QString::number(DBAttendance::findarrTimes(att.cardid())));      //++++++++++++++++++++++++++++
            item->setText(4, QString::number(DBAttendance::findleaTimes(att.cardid())));  //++++++++++++++++++++++++++++
            item->setText(5, QString::number(DBAttendance::findabsTimes(att.cardid())));
        } while(att.next());

      }
}
