#ifndef TIMESETDIALOG_H
#define TIMESETDIALOG_H

#include <QDialog>

namespace Ui {
class timeSetDialog;
}

class timeSetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit timeSetDialog(QWidget *parent = 0);
    ~timeSetDialog();

    QString startTime() const;
    QString spliteTime() const;
    QString endTime() const;


private slots:
    void on_pushButton_clicked();

signals:
    void emittime(QString,QString,QString);
private:
    Ui::timeSetDialog *ui;
};

#endif // TIMESETDIALOG_H
