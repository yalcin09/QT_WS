#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>

#include "mainform.h"

namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButtonLogin_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::LoginForm *ui;
    MainForm *mainForm;
};

#endif // LOGINFORM_H
