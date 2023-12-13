#include <QCoreApplication>
#include "MyObject.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    auto a = new MyObject;
    auto b = new MyObject;

    //QObject::connect(a, &MyObject::mySignal, b, &MyObject::mySlot);
    /*
    QObject::connect(a,
                     static_cast<void(MyObject::*)(int)>(&MyObject::mySignal),
                     b,
                     static_cast<void(MyObject::*)(int)>(&MyObject::mySlot));

    a->mySignal(10);
    */

    QObject::connect(a,
                     QOverload<int>::of(&MyObject::mySignal),
                     b,
                     QOverload<int>::of(&MyObject::mySlot));

    a->mySignal(10);

    return app.exec();
}
