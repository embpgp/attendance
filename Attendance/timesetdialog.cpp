#include "timesetdialog.h"
#include "ui_timesetdialog.h"
#include "MainWidget.h"
#include "DBControl.h"
timeSetDialog::timeSetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::timeSetDialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("时间设置"));

    //设置主窗体背景颜色
    this->setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(150,150,153));
    this->setPalette(palette);


}

QString timeSetDialog::startTime() const //返回卡号
{
    return ui->startTimeEdit->text();
}

QString timeSetDialog::spliteTime() const //返回卡号
{
    return ui->spliteTimeEdit->text();
}


QString timeSetDialog::endTime() const //返回卡号
{
    return ui->endTimeEdit->text();
}
QString timeSetDialog::countTime()const
{
    return ui->countTimeEdit->text();
}
timeSetDialog::~timeSetDialog()
{
    delete ui;
}

void timeSetDialog::on_pushButton_clicked()
{

    emit emittime(startTime(),spliteTime(),endTime(),countTime());
    this->close();

}
