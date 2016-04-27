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


    timeSetDialog timeDialog;



private:
    Ui::MainWidget *ui;
    QextSerialPort *serialPort;
    QByteArray lastRecvedPackage;
    Managelogin *m;


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
};

#endif // MAINWIDGET_H
