#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonOk_clicked()
{
    int result = QMessageBox::information(this, "Info", qStr, QMessageBox::Ok, QMessageBox::Cancel);

    switch(result){
    case QMessageBox::Ok:
        QMessageBox::information(this, "Warning", "Install " + qStr, QMessageBox::Cancel);
        break;
    case QMessageBox::Cancel:
        QMessageBox::information(this, "Warning", "Please, Choose any option", QMessageBox::Cancel);
        break;
    }
}


void Widget::on_pushButtonClose_clicked()
{
    int result = QMessageBox::information(this, "Quit", "Sure!!!", QMessageBox::Ok, QMessageBox::Cancel);

    switch(result){
    case QMessageBox::Ok:
        close();
        break;
    case QMessageBox::Cancel:
        break;
    }
}


void Widget::on_commandLinkButton_clicked()
{
    selectionOption(sender());
}


void Widget::on_commandLinkButton_2_clicked()
{
    selectionOption(sender());
}


void Widget::on_commandLinkButton_3_clicked()
{
    selectionOption(sender());
}

void Widget::selectionOption(QObject *sender)
{
    QCommandLinkButton *cLinkButton = qobject_cast<QCommandLinkButton*>(sender);

    if(cLinkButton == nullptr)
         return;

    QMessageBox::information(this, "Info", cLinkButton->text() + "\n" + cLinkButton->description());
    qStr = "Install : " + cLinkButton->text();
}

