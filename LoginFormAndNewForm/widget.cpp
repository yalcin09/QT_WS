#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    hide();
    lForm = new loginForm(this);
    lForm->show();
}

Widget::~Widget()
{
    delete ui;
}

