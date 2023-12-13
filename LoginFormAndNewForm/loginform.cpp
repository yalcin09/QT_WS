#include "loginform.h"
#include "ui_loginform.h"

LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_pushButton_clicked()
{

}


void LoginForm::on_pushButtonLogin_clicked()
{
    close();
    mainForm = new MainForm();
    mainForm->show();
}


void LoginForm::on_pushButtonCancel_clicked()
{
    close();
}

