#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <QDebug>
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


void Widget::on_btnReview_clicked()
{
    QString texts;
    QObjectList buttonList =  this->children();

    foreach(QObject *obj, buttonList){
        if(obj->inherits("QCheckBox")){
            QCheckBox *cBox = qobject_cast<QCheckBox *>(obj);
            if(cBox && cBox->isChecked())
                texts += cBox->text() + "\r\n";
        }
    }

    QMessageBox::information(this, "Texts", "Tests to : \n" + texts);
}

