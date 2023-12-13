#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QRadioButton>
#include <QPushButton>

class QRadioButton;
class QPushButton;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void pushButtonHandler();

private:
    Ui::Widget *ui;

    QRadioButton *rButton1;
    QRadioButton *rButton2;
    QRadioButton *rButton3;
    QRadioButton *rButton4;
    QRadioButton *rButton5;

    QPushButton *pButton1;


};
#endif // WIDGET_H
