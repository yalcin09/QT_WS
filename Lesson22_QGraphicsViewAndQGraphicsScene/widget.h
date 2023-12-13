#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QDebug>
#include <QTime>
#include <QElapsedTimer>

#include <QSerialPort>

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
    void serialReceived();

private:
    Ui::Widget *ui;

    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;

    QElapsedTimer timer;

    QSerialPort *serial;
    bool serialBeginState = false;
    double lastX, lastY;

};
#endif // WIDGET_H
