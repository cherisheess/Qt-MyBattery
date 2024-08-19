#include "widget.h"
#include "ui_widget.h"

widget::widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::widget)
{
    ui->setupUi(this);
    //ui->widget_2->show();
}

widget::~widget()
{
    delete ui;
}
