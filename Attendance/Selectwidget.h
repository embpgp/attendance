#ifndef SELECTWIDGET_H
#define SELECTWIDGET_H

#include <QWidget>

namespace Ui {
class SelectWidget;
}

class SelectWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SelectWidget(QWidget *parent = 0);
    ~SelectWidget();

private:
    Ui::SelectWidget *ui;
};

#endif // SELECTWIDGET_H
