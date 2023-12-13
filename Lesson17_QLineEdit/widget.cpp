#include "widget.h"
#include "ui_widget.h"

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


void Widget::on_pushButton_clicked()
{
    QString firstName = ui->lineEditFirstName->text();
    QString lastName = ui->lineEditLastName->text();
    QString country = ui->lineEditCountry->text();
    QString birthday = ui->lineEditBirthday->text();
    QString password = ui->lineEditPassword->text();

    if(!firstName.isEmpty() && !lastName.isEmpty() && !country.isEmpty() && !birthday.isEmpty() && !password.isEmpty()){
        qDebug() << "First Name : " << firstName;
        qDebug() << "Last Name : " << lastName;
        qDebug() << "Country Name " << country;
        qDebug() << "Birthday : " << birthday;
        qDebug() << "Password : " << password;
    }else
        qDebug() << "Failed";
}

