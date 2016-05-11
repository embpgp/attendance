#include "MainWidget.h"
#include "ui_MainWidget.h"
#include "ioportManager.h"
#include <qextserialport.h>
#include <qextserialenumerator.h>
#include <QDateTime>
#include <QDebug>
#include <QDir>


MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget),
    serialPort(NULL),
    m(NULL),
    timeDialog(NULL)
{

    ui->setupUi(this);
    connect(this, SIGNAL(newCard(QByteArray)), this, SLOT(onNewCard(QByteArray)));
    
    IOPortManager::setMode(Mode125K); // 125K的设备

    setWindowTitle(tr("毕业设计-签到管理系统"));
    ui->label->setText(tr("签到管理系统"));

    //设置主窗体背景颜色
    this->setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(192,253,123));
    this->setPalette(palette);


}

MainWidget::~MainWidget()
{
    stop();
    DBControl::Destroy();
    delete ui;
    delete m;
    delete timeDialog;
}

void MainWidget::start(const QString &port)
{
    qDebug()<<"open port"<<port;
    if(serialPort == NULL)
        serialPort = new QextSerialPort(port, QextSerialPort::EventDriven);
    serialPort->setBaudRate(BAUD19200);
    serialPort->setFlowControl(FLOW_OFF);
    serialPort->setParity(PAR_NONE);
    serialPort->setDataBits(DATA_8);
    serialPort->setStopBits(STOP_1);

    if (serialPort->open(QIODevice::ReadWrite) == true) {
        connect(serialPort, SIGNAL(readyRead()), this, SLOT(onSerialDataReady()));
        ui->serialPortList->setEnabled(false);
        ui->refreshSerialPortList->setEnabled(false);
        ui->openCloseSerialPort->setText(tr("关闭"));
    }
    else {
        ui->serialPortList->setEnabled(true);
        ui->refreshSerialPortList->setEnabled(true);
        ui->openCloseSerialPort->setText(tr("打开"));
        qDebug() << "device failed to open:" << serialPort->errorString();
        delete serialPort;
        serialPort = NULL;
    }
}

void MainWidget::stop()
{
    if(serialPort == NULL)
        return;
    serialPort->close();
    delete serialPort;
    serialPort = NULL;
    ui->serialPortList->setEnabled(true);
    ui->refreshSerialPortList->setEnabled(true);
    ui->openCloseSerialPort->setText(tr("打开"));
}

void MainWidget::onSerialDataReady()
{
    static QDateTime lastRecvedTime;
    if(abs(lastRecvedTime.msecsTo(QDateTime::currentDateTime())) > 200)
        lastRecvedPackage.clear();
    QByteArray data;
    int len = serialPort->bytesAvailable();
    data.resize(len);
    char *p = data.data();
    serialPort->read(p, len);
    while(len-- > 0)
    {
        lastRecvedPackage.append(*p++);
        if(lastRecvedPackage.length() >= 5)
        {
            emit newCard(lastRecvedPackage.left(4));
            lastRecvedPackage.clear();
        }
    }
    lastRecvedTime = QDateTime::currentDateTime();
}

void MainWidget::onNewCard(QByteArray id)
{
    static const QByteArray nullCardId(4, char(0));
    static QByteArray lastCardId = nullCardId;
    static QDateTime lastCardTime;
    do {
        if(id == nullCardId)
            break;
        if((id == lastCardId) && (abs(lastCardTime.msecsTo(QDateTime::currentDateTime())) < 800))
            break;
        switch(ui->tabWidget->currentIndex())
        {
        case 0:
            // ClockInWidget
            ui->clockInPage->onCardReaded(id.toHex());
            break;
        case 1:
            // ManageWidget
            ui->manPage->onCardReaded(id.toHex());
            break;
        }
    } while(0);
    lastCardId = id;
    lastCardTime = QDateTime::currentDateTime();
}

void MainWidget::on_refreshSerialPortList_clicked() //刷新串口
{
    if(serialPort != NULL)
    {
        ui->refreshSerialPortList->setEnabled(false);
        return;
    }
    QList<QextPortInfo> ports = QextSerialEnumerator::getPorts();
    ui->serialPortList->clear();
#ifndef _WIN32
    ui->serialPortList->addItem("serial0", "/dev/s3c2410_serial0");
    ui->serialPortList->addItem("serial1", "/dev/s3c2410_serial1");
    ui->serialPortList->addItem("serial2", "/dev/s3c2410_serial2");
    ui->serialPortList->addItem("serial3", "/dev/s3c2410_serial3");
#endif
    for(int i = 0; i < ports.count(); i++)
    {
        const QextPortInfo &info = ports.at(i);
        qDebug()<<info.portName<<info.physName<<info.friendName<<info.enumName;
        if(info.portName.contains("LPT"))
            continue;
#ifdef _WIN32
        ui->serialPortList->addItem(info.portName, info.portName);
#else
        ui->serialPortList->addItem(info.portName, info.physName);
#endif
    }
}

void MainWidget::on_openCloseSerialPort_clicked() //打开串口
{
    if(serialPort == NULL)
        start(ui->serialPortList->itemData(ui->serialPortList->currentIndex()).toString());
    else
        stop();
}



void MainWidget::on_setTimeButton_clicked()
{


    timeDialog = new timeSetDialog();
    connect(timeDialog,SIGNAL(emittime(QString,QString,QString,QString)),this,SLOT(settime(QString,QString,QString,QString)));

    timeDialog->show();


}


void MainWidget::on_pushButton_clicked()
{
    m = new Managelogin(this);
    m->show();
}

void MainWidget::settime(QString starttime, QString splitetime, QString endtime, QString counttime)
{


        ui->clockInPage->startT = starttime;
        ui->clockInPage->spliteT = splitetime;
        ui->clockInPage->endT   = endtime;
        ui->clockInPage->countT = counttime;

    //直接更新到数据库
    DBSettime::updatatime(starttime,splitetime,endtime);


    //从对话框设置考勤时间

    qDebug()<<"You Set start Time : "<<ui->clockInPage->startT;
    qDebug()<<"You Set splite Time : "<<ui->clockInPage->spliteT;
    qDebug()<<"You Set end Time : "<<ui->clockInPage->endT;
    qDebug()<<"You Set countTime:"<<ui->clockInPage->countT;
}
