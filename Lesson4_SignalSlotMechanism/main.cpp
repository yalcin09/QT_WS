/*
 * Signal - Slot
 *
 * Temel Amaç:
 *      Nesneler arası iletişimi sağlamak için kullanılır.
 *      Qt yapısına özgü kavramlardır.
 *      Birer fonksiyonlardır.
 *
 *      Oluşturulacak sınıf "QObject" sınıfından türemiş ve makrosuna sahip olmalı.
 *
 */

#include <QObject>
#include "SignalA.h"
#include "SlotA.h"


int main()
{
    SignalA sigA;
    SlotA slotA;

    QObject::connect(&sigA, SIGNAL(onOperation(int, int)), &slotA, SLOT(add(int, int)));
    sigA.makeOperationSignal();

    // Bağlantıyı kesmek için
    //QObject::disconnect(&sigA, SIGNAL(onOperation(int, int)), &slotA, SLOT(add(int, int)));
    //sigA.makeOperationSignal();

    QObject::connect(&sigA, SIGNAL(onOperation(int, int)), &slotA, SLOT(div(int, int)));
    sigA.makeOperationSignal();

    QObject::connect(&sigA, SIGNAL(onOperation(int, int)), &slotA, SLOT(mul(int, int)));
    sigA.makeOperationSignal();

    QObject::disconnect(&sigA, SIGNAL(onOperation(int, int)), &slotA, SLOT(mul(int, int)));
    sigA.makeOperationSignal();


    return 0;
}
