#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){

    ui->setupUi(this);
    //-----------------------------------------------------
    // Window Set
    setFixedSize(740,285);
    setWindowTitle("Gerçek Zamanlı Serial Port ve Plot");

    //-----------------------------------------------------
    // Serial Port Set
    serial = new QSerialPort(this);
    serial->setPortName("COM7");
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);
    connect(serial, SIGNAL(readyRead()), this, SLOT(serialReceived()));

    //-----------------------------------------------------
    // Plot Set
    series = new QLineSeries(); // series->append(x,y) || series << QPointF(x,y) || series->removePoints(startPoint,endPoint) || series->count()

    // Chart Viewer
    m_ChartViewer = new QChartView(this);
    m_ChartViewer->setGeometry(132, 8, 600, 270);
    m_ChartViewer->setRenderHint(QPainter::Antialiasing);

    // ValueAxis
    axisX = new QValueAxis();
    axisY = new QValueAxis();
    axisX->setRange(0.0,500.0);
    axisY->setRange(-190,190);

    // Chart
    chart = m_ChartViewer->chart();
    //chart->addAxis(axisX, Qt::AlignBottom);
    //chart->addAxis(axisY, Qt::YAxis);
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setAnimationOptions(QChart::AllAnimations);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::serialReceived(){
    QString receviedData = serial->readAll();
    QStringList receviedDataList = receviedData.split('+');
    qDebug() << receviedDataList[0]; // << "\t" << receviedDataList[1];
    /*if(receviedDataList[0] == "" || receviedDataList[1] == "") return;
    serialReadAngle = receviedDataList[0].toDouble();
    serialReadTime = receviedDataList[1].toDouble();

    qDebug() << receviedDataList;

    series->append(serialReadTime, serialReadAngle);
    if(series->count() == 100)
        series->removePoints(0,1);

    chart->removeSeries(series);
    chart->addSeries(series);*/
}

