#include "rotatenumberlabel.h"
#include <QDebug>

RotateNumberLabel::RotateNumberLabel(QWidget *parent)
    : QLabel(parent)
    , currentIndex(0)
    , currentNumber(0)
    , nextNumber(0)
    , motion(false)
{
    timer = new QTimer(this);
    timer->setInterval(50);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    reloadPicture();
}

RotateNumberLabel::~RotateNumberLabel()
{
    delete timer;
}

void RotateNumberLabel::onTimer()
{
    this->update();
    if(motion)
    {
        timer->start();
    }
}

void RotateNumberLabel::paintEvent(QPaintEvent *ev)
{
//    QLabel::paintEvent(ev);
    if(this->bgPic.isNull())
        return;
    int oy = (90 - 87) / 2;
    int ox1 = 8;
    int ox2 = 0;
    QPainter pt(this);
    pt.scale(qreal(this->width()) / 96, qreal(this->height()) / 90);
    pt.drawImage(0, 0, bgPic);
    pt.drawImage(ox1, oy, underPic[0]);
    pt.drawImage(ox1 + ox2 + underPic[0].width(), oy, underPic[1]);
    pt.drawImage(ox1, oy, upperPic[0]);
    pt.drawImage(ox1 + ox2 + upperPic[0].width(), oy, upperPic[1]);
    if(motion)
    {
        if(++currentIndex >= 10)
        {
            currentIndex = 0;
            currentNumber = nextNumber;
            motion = false;
        }
        reloadPicture();
    }
}

int RotateNumberLabel::speed() const
{
    return 1000 / timer->interval();
}

void RotateNumberLabel::setSpeed(int fps)
{
    timer->setInterval(1000 / fps);
}

int RotateNumberLabel::number() const
{
    return nextNumber;
}

void RotateNumberLabel::setNumber(int n)
{
    n = n % 100;
    currentIndex = 0;
    currentNumber = n;
    nextNumber = n;
    reloadPicture();
    motion = false;
    this->update();
}

void RotateNumberLabel::motionToNumber(int n)
{
    n = n % 100;
    currentIndex = 0;
    nextNumber = n;
    motion = true;
    reloadPicture();
    this->update();
    timer->start();
}
