#include "Selectwidget.h"
#include "ui_Selectwidget.h"

SelectWidget::SelectWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectWidget)
{
    ui->setupUi(this);
}

SelectWidget::~SelectWidget()
{
    delete ui;
}
