#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <qevent.h>
#include <QLabel>
#include <QTimer>
#include <QMessageBox>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>

using namespace cv;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //QTimer aktif edildiğinde işletilecek slot.
    void processFrameAndUpdateGUI();

private:
    Ui::Widget *ui;

    //Qt
    QTimer* frameTimer;
    QImage  imageOrg, imageCanny;

    //OpenCV
    Mat matOrg;
    Mat matCanny;
    VideoCapture capVideo;

    //Metotlar
    void exitProgram();
    void closeEvent(QCloseEvent *event);
};
#endif // WIDGET_H
