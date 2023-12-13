#include <QCoreApplication>
#include "AObject.h"
#include "BObject.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    auto a = new AObject;
    auto b = new BObject;

    {
    //QObject::connect(a, SIGNAL(signalFunciton(QString)), b, SLOT(recieveBObject(QString))); // String method
    //QObject::connect(a, &AObject::signalFunciton, b, &BObject::recieveBObject); // Function Address method
    //QObject::connect(a, &AObject::signalFunciton, [&](const QString & msg) {qDebug() << "msg for a Lambda : " << msg;}); // Lambda method

    //a->signalFunciton("Hiii");

    // QObject::disconnect(a,0,0,0);          // a nesnesine bağlı bütün yapıları iptal eder
    // a->disconnect();                       // a nesnesinin signalFunction fonksitonuna bağlı bütün yapıları iptal eder.
    // a->disconnect(SIGNAL(signalFuntion));  //
    // QObject::disconnect(a, 0, b, 0);       // a nesnesi ile b nesnesi arasındaki iletişimi iptal eder.
    // a->disconnect(b);
    }

    //QObject::connect(a, &AObject::signalFunciton, b, &BObject::recieveBObject, Qt::QueuedConnection);
    //a->signalFunciton("Hiii");

    return app.exec();
}
