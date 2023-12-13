#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget){
    ui->setupUi(this);

    // Webcam'deb görüntü almak
    // Birden fazla kamera varsa 0 yerine 1,2,...kullanılabilinir.
    capVideo.open(0);

    // Capture boyutlarını ayarlama
    // Frame'leri daha hızlı process edtmek için boyut küçültmemiz gerekebilir.
    // Bu küçültme işlemini genellikle raspberry tarzı sistemler için yapılır.
     capVideo.set(CAP_PROP_FRAME_WIDTH, 640);
     capVideo.set(CAP_PROP_FRAME_HEIGHT, 480);

    // Bir Qt timer'ı ayarlıyoruz. Bu timer heer 30ms'de bir processFrameUpdateGUI metodunu çağılacak.
    // Böylece görüntü tazeleme ve process etme işi bu kısımda yapılacak.
    // Bu iş için thread'de kullanabilirdik. Fakat QTimer sınıfı işlemimizi basitletecek.
    frameTimer = new QTimer(this);
    connect(frameTimer, SIGNAL(timeout()), this, SLOT(processFrameUpdateGUI()));
    frameTimer->start(30);
}

Widget::~Widget(){
    delete ui;
}

void Widget::processFrameAndUpdateGUI(){

    // Kameradan sıradaki frame okuma
    capVideo.read(matOrg);

    // Okunan frame'i BGR renk uzayından RGB uzayına dönüştürme
    // OpenCV webcam'den aldığı frame her zaman BGR uzayndadır.
    cvtColor(matOrg, matOrg, COLOR_BGR2RGB);

    // Görüntüyü Canny metodunu kullanarak işleme
    Canny(matOrg, matCanny, 50, 100);

    // Bu kısımda OpenCV matrislerini QImage türüne dönüştürüyoruz
    // RGB image için QImage::Format_RGB888 parametresini
    // Gray image için QImage::Format_Indexed8 parametrelerini kullanırız
    imageOrg = QImage((uchar*)matOrg.data, matOrg.cols, matOrg.rows, matOrg.step, QImage::Format_RGB888);
    imageCanny = QImage((uchar*)matCanny.data, matCanny.cols, matCanny.rows, matCanny.step, QImage::Format_Indexed8);

    // Image'leri UI üzerinde tanımlanmış Label'lere aktarma
    ui->labelCapture->setPixmap(QPixmap::fromImage(imageOrg));
    ui->labelCanny->setPixmap(QPixmap::fromImage(imageCanny));

}

void Widget::exitProgram(){

    // Çıkış için webcam kapatılır
    if(capVideo.isOpened()){
        capVideo.release();
    }

    // QTimer sonlandırma
    if(frameTimer->isActive()){
        frameTimer->stop();
    }

    // Çıkış
    QApplication::quit();
}

void Widget::closeEvent(QCloseEvent *event){
    // Programdan çıkmak için çarpıya basıldığında bir uyarı penceresi açılacak ve
    // uygulamadan çıkıp çıpmayacağımızı soracak
    QMessageBox::StandardButton resBtn = QMessageBox::question(this, "OpenCV", "Çıkmak istiyor musunuz?",
                                                               QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    if(resBtn != QMessageBox::Yes){
        exitProgram();
        event->accept();
    }else
        event->ignore();

}

