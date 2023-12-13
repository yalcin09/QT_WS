#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget){

    ui->setupUi(this);

    serial = new QSerialPort(this);
    serial->setPortName("COM7");
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);
    //serial->write("Merhaba");
    //serial->close();
    connect(serial, SIGNAL(readyRead()), this, SLOT(serialReceived()));


    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

}

Widget::~Widget(){
    delete ui;
}

void Widget::serialReceived(){
    QString receviedData = serial->readAll();
    QStringList receviedDataList = receviedData.split('+');

    //QBrush redBrush(Qt::red);
    //QBrush blueBrush(Qt::blue);
    QPen blackPen(Qt::black);
    //QPen redPen(Qt::red);
    //QPen bluePen(Qt::blue);
    //QPen yellowPen(Qt::yellow);

    blackPen.setWidth(1);
    //redPen.setWidth(1);
    //bluePen.setWidth(1);
    //yellowPen.setWidth(1);

    if(!serialBeginState){
        scene->addLine(0, 0, receviedDataList[1].toDouble(), receviedDataList[0].toDouble(), blackPen);
        serialBeginState = true;
        lastX = receviedDataList[1].toDouble();
        lastY = receviedDataList[0].toDouble();
    }else{
        scene->addLine(lastX, lastY, receviedDataList[1].toDouble(), receviedDataList[0].toDouble(), blackPen);
        lastX = receviedDataList[1].toDouble();
        lastY = receviedDataList[0].toDouble();
    }

}

