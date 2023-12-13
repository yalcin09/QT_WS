#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class LoginForm; }
QT_END_NAMESPACE

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

private:
    Ui::LoginForm *ui;

};
#endif // WIDGET_H
