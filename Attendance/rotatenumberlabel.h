#ifndef ROTATENUMBERLABEL_H
#define ROTATENUMBERLABEL_H

#include <QLabel>
#include <QPainter>
#include <QPaintEvent>
#include <QImage>
#include <QTimer>
#include <stdio.h>

class RotateNumberLabel : public QLabel
{
    Q_OBJECT
public:
    explicit RotateNumberLabel(QWidget *parent = 0);
    ~RotateNumberLabel();

    int number(void) const;
    int speed(void) const;

signals:

public slots:
    void setSpeed(int fps);
    void setNumber(int n);
    void motionToNumber(int n);

protected slots:
    void onTimer();

protected:
    virtual void paintEvent(QPaintEvent *ev);

protected:
    QImage bgPic;
    QImage underPic[2];
    QImage upperPic[2];
    QTimer *timer;
    int currentIndex;
    int currentNumber;
    int nextNumber;
    bool motion;

protected:
    QString getBgPicName(int idx) {
        char tmp[100];
        sprintf(tmp, ":/number/bg_%04d.png", idx);
        return tmp;
    }
    QString getUnderPicName(int id, int idx) {
        char tmp[100];
        sprintf(tmp, ":/number/under_%d_%04d.png", id, idx);
        return tmp;
    }
    QString getUpperPicName(int id, int idx) {
        char tmp[100];
        sprintf(tmp, ":/number/upper_%d_%04d.png", id, idx);
        return tmp;
    }
    void reloadPicture(void) {
        bgPic.load(getBgPicName(currentIndex));
        underPic[0].load(getUnderPicName(nextNumber / 10, currentIndex));
        underPic[1].load(getUnderPicName(nextNumber % 10, currentIndex));
        upperPic[0].load(getUpperPicName(currentNumber / 10, currentIndex));
        upperPic[1].load(getUpperPicName(currentNumber % 10, currentIndex));
    }
};

#endif // RotateNumberLabel_H
