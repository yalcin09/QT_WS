#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QObject>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QButtonGroup>
#include <QComboBox>
#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void readyRead();

public slots:
    void serialReceived();

private:
    Ui::MainWindow *ui;

    QSerialPort *serial;
    QLineSeries *series;
    QChartView *m_ChartViewer;
    QChart *chart;

    double serialReadTime = 0.0;
    double serialReadAngle = 0.0;

    QValueAxis *axisX, *axisY;

};
#endif // MAINWINDOW_H
