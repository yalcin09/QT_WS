#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Pencere başlığı koymak
    setWindowTitle("GUI Start1");


}

Widget::~Widget()
{
    delete ui;
}

