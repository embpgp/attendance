#include "ClockInWidget.h"
#include "ui_ClockInWidget.h"
#include <QDebug>
#include <QDir>
#include <QMovie>
#include <QPixmap>
#include <QTime>
#include <QMessageBox>
#include "sendemailapi/smtpmime.h"


ClockInWidget::ClockInWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget),
    arriveLateTimes(0),
    leaveearlyTimes(0),
    absenceTimes(0)
{
    ui->setupUi(this);
    updateDateTime();

    timer = new QTimer(this);
    timer->setInterval(1000);
    timer->setSingleShot(false);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));

//    ui->label_6->setScaledContents(true);
//    QString picName = "1.jpg";
//    qDebug()<<picName;
//    setPicture(picName);

    startT = "08:00:00";
    spliteT= "12:00:00";
    endT   = "20:00:00";

    //设置默认的考勤时间（开始 结束 和 迟到截止时间）
    qDebug()<<"Default start Time : "<<startT;
    qDebug()<<"Default start Time : "<<spliteT;
    qDebug()<<"Default start Time : "<<endT;

    //设置主窗体背景颜色
    this->setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(100,253,123));
    this->setPalette(palette);


    timer->start();

}

ClockInWidget::~ClockInWidget()
{
    delete timer;
    delete ui;
}

void ClockInWidget::setPicture(const QString &name) //在主界面显示读卡人的头像
{


    QPixmap pixmap;
    QString picName;
    picName = "../Attendance/pic/";
    picName += name;
    pixmap.load(picName);
    //label=new QLabel;
    ui->label_6->setPixmap(pixmap);
    //+++  ui->label_3->show ();    //+++
    (pixmap).scaled(ui->label_6->x(),ui->label_6->y());
    ui->label_6->resize( (pixmap).width() ,(pixmap).height() );

}

void ClockInWidget::updateTime()  //更新登录界面年月日时分秒
{
    QDateTime d = QDateTime::currentDateTime();
    ui->secondNumber->display(d.time().second());
    if(d.time().second() == 0)
    {
        ui->minuteLabel->motionToNumber(d.time().minute());
        if(d.time().minute() == 0)
        {
            ui->hourLabel->motionToNumber(d.time().hour());
            if(d.time().hour() == 0)
            {
                ui->dayNumber->display(d.date().day());
                if(d.date().day() == 1)
                {
                    ui->monthNumber->display(d.date().month());
                    if(d.date().month() == 1)
                    {
                        ui->yearNumber->display(d.date().year());
                    }
                }
            }
        }
    }
}

void ClockInWidget::updateDateTime() //更新当前时间戳时间
{
    QDateTime d = QDateTime::currentDateTime();
    ui->yearNumber->display(d.date().year());
    ui->monthNumber->display(d.date().month());
    ui->dayNumber->display(d.date().day());
    ui->hourLabel->motionToNumber(d.time().hour());
    ui->minuteLabel->motionToNumber(d.time().minute());
    ui->secondNumber->display(d.time().second());
}

void ClockInWidget::onCardReaded(const QString &cardid) //读卡
{

    qDebug()<<"using start ----- Time : "<<startT;
    qDebug()<<"using splite ----- Time : "<<spliteT;
    qDebug()<<"using end ----- Time : "<<endT;

    qDebug()<<"Card Reading !";
    QString name = DBCard::findName(cardid);
    QString gender = DBCard::findGender(cardid);
    QString occupation = DBCard::findOccupation(cardid);
    QString mailAddress = DBCard::findMailAddress(cardid);

    int n = DBCard::findId(cardid);   //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


    QTime t1 = QTime::fromString(startT);
    QTime tSplite = QTime::fromString(spliteT);
    QTime t2 = QTime::fromString(endT);
    QTime t = QTime::currentTime();

    qDebug()<<"now Time : "<<t;



    ui->cardIdEdit->setText(cardid);
    ui->nameEdit->setText(name.isEmpty() ? tr("此卡未登记!") : name);
    if( !( name.isEmpty() ) )         //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    {

        ui->label_6->setScaledContents(true);
        QString picName = QString("%1.jpg").arg(n);

        setPicture(picName);


    }


    if( t>=t1 && t<=t2) //迟到或早退
    {       

        if(!name.isEmpty()) //卡是否登记
        {

            if(DBLog::isFirstLog(cardid)) //是否第一次刷卡
            {
                if(t<=tSplite)
                {

                        qDebug()<<"First log :迟到的 ";      //迟到记录加入，并且刷新出勤表
                        arriveLate = tr("是");
                        leaveEarly = tr("否");

                        arriveLateTimes = 1;

                        DBLog::addLog(cardid,gender,occupation,arriveLate,leaveEarly);
                        DBAttendance::updatelogwitharrtimes(cardid, arriveLateTimes);
                        QMessageBox::warning(this, tr("警告"), tr("同学你迟到了！"));

                }
                else
                {
                    qDebug()<<"第一次First log : 早退的";
                    arriveLate = tr("否");
                    leaveEarly = tr("是");   //第一次，，，早退


                    leaveearlyTimes=1;

                    DBLog::addLog(cardid,gender,occupation,arriveLate,leaveEarly);
                    DBAttendance::updatelogwithleatimes(cardid, leaveearlyTimes);
                    QMessageBox::warning(this, tr("警告"), tr("同学你早退了！"));
                }

            }
            else//今天第二次刷卡
            {

                qDebug()<<"Not First Login : ";

                if(t>=t1 && t <= tSplite) //迟到还是早退
                {

                    qDebug()<<"Late Arrive :迟到的 ";
                    arriveLate = tr("是");
                    leaveEarly = tr("否");

                    arriveLateTimes = DBAttendance::findarrTimes(cardid);
                    arriveLateTimes++;


                    DBLog::addLog(cardid,gender,occupation,arriveLate,leaveEarly);
                    DBAttendance::updatelogwitharrtimes(cardid,arriveLateTimes);
                    if(arriveLateTimes >= 5)
                    {


                        //发送迟到5次提醒邮件
                        qDebug()<<tr("编写邮件提示代码");

                        SmtpClient smtp("smtp.qq.com",
                                        465,
                                        true?SmtpClient::SslConnection:SmtpClient::TcpConnection);
                        smtp.setUser("aaaaaaaaa@test.com");    //发件人邮箱用户名
                        smtp.setPassword("xxxxxxxxxx");//发件人邮箱用密码

                        //构建邮件主题,包含发件人收件人附件等.
                        MimeMessage message;
                        message.setSender(new EmailAddress("xxxxxxxx@test.com")); //填写发件人邮箱地址

                    //    //逐个添加收件人
                    //    QStringList receiver = ui->txtReceiverAddr->text().split(';');
                    //    for (int i = 0; i < receiver.size(); i++){
                            message.addRecipient(new EmailAddress(mailAddress));     //迟到者邮箱 <到时修改数据库换成相应用户邮箱就行>
                    //    }
                        //构建邮件标题
                        message.setSubject(tr("考勤温馨提示"));


                        //文件内容
                        MimeText text;
                        text.setText(tr("同学你迟到达到或超过5次了!"));

                        message.addPart(&text);



                        if (!smtp.connectToHost()){
                            QMessageBox::critical(this,tr("错误"),tr("服务器连接失败!"));
                            return;
                        }
                        if (!smtp.login()){
                            QMessageBox::critical(this,tr("错误"),tr("用户登录失败!"));
                            return;
                        }
                        if (!smtp.sendMail(message)){
                            QMessageBox::critical(this,tr("错误"),tr("邮件发送失败!"));
                            return;
                        }else{
                            QMessageBox::information(this,tr("提示"),tr("邮件发送成功!"));
                        }

                        smtp.quit();


                    }
                    QMessageBox::warning(this, tr("警告"), tr("同学你迟到了！"));
                }
                if(t>tSplite && t<t2)
                {
                    qDebug()<<"第二次Leave Early :早退的 ";
                    arriveLate = tr("否");
                    leaveEarly = tr("是");

                    leaveearlyTimes = DBAttendance::findleaTimes(cardid);
                    leaveearlyTimes++;



                    DBLog::addLog(cardid,gender,occupation,arriveLate,leaveEarly);
                    DBAttendance::updatelogwithleatimes(cardid,leaveearlyTimes);
                    QMessageBox::warning(this, tr("警告"), tr("同学你早退了！"));
                }

            }

        }

        return;
    }
    else
    {
        qDebug()<<tr("没有迟到或早退: ");
        if(!name.isEmpty()) //卡是否登记
        {

            arriveLate = tr("否");
            leaveEarly = tr("否");

            DBLog::addLog(cardid,gender,occupation,arriveLate,leaveEarly);
            QMessageBox::warning(this, tr("Warning"), t<t1? tr("登陆!"):tr("离开"));

        }

    }

}
