#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("QRadioButtonReview");
    resize(80,150);

    rButton1 = new QRadioButton("One", this);
    rButton2 = new QRadioButton("Two", this);
    rButton3 = new QRadioButton("Three", this);
    rButton4 = new QRadioButton("Four", this);
    rButton5 = new QRadioButton("Five", this);

    rButton1->move(10,10);
    rButton2->move(10,30);
    rButton3->move(10,50);
    rButton4->move(10,70);
    rButton5->move(10,90);

    pButton1 = new QPushButton("Review", this);
    pButton1->move(10,110);

    connect(pButton1, &QPushButton::clicked, this, &Widget::pushButtonHandler);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::pushButtonHandler()
{
    QString text = "None";
    /*
    if(rButton1->isChecked())
        text = rButton1->text();
    else if(rButton2->isChecked())
        text = rButton2->text();
    else if(rButton3->isChecked())
        text = rButton3->text();
    else if(rButton4->isChecked())
        text = rButton4->text();
    else if(rButton5->isChecked())
        text = rButton5->text();

    qDebug() << "Text : " << text;
    */

    // Bütün object'ler objButton değişkenine atandı.
    QObjectList objButton = this->children();

    foreach(QObject *obj, objButton){
        if(obj->inherits("QRadioButton")){  // türünü kontrol et
            QRadioButton *rBtn = qobject_cast<QRadioButton*>(obj);
            if(rBtn && rBtn->isChecked()){
                text = rBtn->text();
                break;
            }
        }
    }
    QMessageBox::information(this, "Message", "Sellected : " + text, QMessageBox::Ok);
}

