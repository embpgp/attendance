#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "DBControl.h"
#include "timesetdialog.h"
#include "managelogin.h"
namespace Ui {
    class MainWidget;
}

class QextSerialPort;
class MainWidget : public QWidget
{
    Q_OBJECT

public:

    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();






private:
    Ui::MainWidget *ui;
    QextSerialPort *serialPort;
    QByteArray lastRecvedPackage;
    Managelogin *m;
    timeSetDialog *timeDialog;

signals:
    void newCard(QByteArray id);

private slots:
    void start(const QString &port);
    void stop();
    void onSerialDataReady();
    void onNewCard(QByteArray id);
    void on_refreshSerialPortList_clicked();
    void on_openCloseSerialPort_clicked();



    void on_setTimeButton_clicked();
    void on_pushButton_clicked();

    void settime(QString,QString,QString,QString);
};

#endif // MAINWIDGET_H
