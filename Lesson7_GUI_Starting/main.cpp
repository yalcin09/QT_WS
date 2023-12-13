#include "widget.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    // Pencerenin sol süt köşesinin posizyonunu alma
    qDebug() << "Pencere Pos : " << w.pos();
    qDebug() << "Pencere PosX : " << w.pos().x();
    qDebug() << "Pencere PosY : " << w.pos().y();
    qDebug() << "Pencere PosX : " << w.x();
    qDebug() << "Pencere PosY : " << w.y();

    qDebug() << "*************************************";

    // Pencere genişliği ve yüksekliği
    qDebug() << "width : " << w.width();
    qDebug() << "height : " << w.height();

    qDebug() << "*************************************";

    // Pencere konumunu ayarlamak
    w.move(200,300);

    // Pencere başlangıç konumunu ve bitiş konumunu almak
    qDebug() << "w rect : " << w.rect();

    qDebug() << "*************************************";

    // Pencere yükseklik ve genişliği alma
    qDebug() << "w size : " << w.size();

    qDebug() << "w geometry : " << w.geometry();

    qDebug() << "w frema geometry : " << w.frameGeometry();

    qDebug() << "w frema size : " << w.frameSize();


    qDebug() << "*************************************";

    // Pencere adını alma
    qDebug() << "window Title : " << w.windowTitle();

    // Bencerenin görünür olup olmadığı
    qDebug() << "isVisible : " << w.isVisible();

    // Pencere gizleme
    w.hide();
    qDebug() << "isVisible : " << w.isVisible();

    // Pencere aktif etme
    w.setVisible(true);
    //w.show();
    qDebug() << "isVisible : " << w.isVisible();

    qDebug() << "*************************************";

    // Pencere boyoutu ayarlama

    //qDebug() << "isMaximized : " << w.isMaximized(); // Tam ekran yapıldı mı?
    //w.showMaximized();                               // Tam ekran yap.
    //qDebug() << "isMaximized : " << w.isMaximized();

    //w.showMinimized();                               // Ekran küçült
    //qDebug() << "isMinized : " << w.isMaximized();   // Ekran küçültüldü mü?

    //w.showFullScreen();                              //
    //qDebug() << "isFullScreen : " << w.isFullScreen();

    //w.showNormal();

    qDebug() << "*************************************";

    //
    qDebug() << "isModal : " << w.isModal();

    qDebug() << "*************************************";

    // Pencere boyut sınırlaması
    w.setMaximumWidth(500);
    w.setMinimumWidth(200);
    w.setMaximumHeight(800);
    w.setMinimumHeight(600);

        // veya
        // w.setMaximumSize(500,800);
        // w.setMinimumSize(200,600);





    return a.exec();
}
