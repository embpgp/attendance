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

private slots:
    void on_select_clicked();

    void on_pushButton_clicked();

private:
    Ui::SelectWidget *ui;
};

#endif // SELECTWIDGET_H
