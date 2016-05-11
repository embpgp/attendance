#ifndef CLOCKINWIDGET_H
#define CLOCKINWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QDateTime>
#include "DBControl.h"
#include "MainWidget.h"

namespace Ui {
    class widget;
}

class ClockInWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClockInWidget(QWidget *parent = 0);
    ~ClockInWidget();

    void setPicture(const QString &name);   //设置图片

    QString startT;
    QString endT;
    QString spliteT;
    QString countT;



    QString arriveLate;    //第一次到的时间
    QString leaveEarly;    //第二次走的时间
    int arriveLateTimes;   //迟到次数
    int leaveearlyTimes;    //早退次数
    int absenceTimes;       //缺勤次数


public slots:
    void onCardReaded(const QString &cardid); //读卡

private:
    Ui::widget *ui;
    QTimer *timer;

private slots:
    void updateDateTime(); //时间更新显示
    void updateTime();
};


#endif // CLOCKINWIDGET_H
