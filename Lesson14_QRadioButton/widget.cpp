#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>
#include <QRadioButton>
#include <QList>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("Market");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushOk_clicked()
{
    QString provisions = getChose(ui->groupBoxProvision);
    QString fruits = getChose(ui->groupBoxFruits);
    QString kg = getChose(ui->groupBoxKg);
    QString secure = getChose(ui->groupBoxCoronoSecure);

    QString shopOrder;

    shopOrder += "Provision : " + provisions + "\n";
    shopOrder += "Fruit :" + fruits + "\r";
    shopOrder += "Kg : " + kg + "\n";
    shopOrder += "Corono Secure : " + secure + "\n";

    QMessageBox::information(this, "Order", "Shop List :\n" + shopOrder, QMessageBox::Ok);
}


void Widget::on_pushCancel_clicked()
{
    QMessageBox::critical(this, "Critical Message", "Don't you want to shop?");
    close();
}

QString Widget::getChose(QObject *obj)
{
    QString shop = "None";

    // Grup içerisindeki Radio Butonlar liste içerisine çekildi
    QList<QRadioButton*> shopList = obj->findChildren<QRadioButton*>(QString(), Qt::FindDirectChildrenOnly);

    foreach(QRadioButton *rObj, shopList){
        if(rObj->isChecked()){
            shop = rObj->text();
            break;
        }
    }

    return shop;
}

