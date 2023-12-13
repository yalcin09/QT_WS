#ifndef AOBJECT_H
#define AOBJECT_H

#include <QObject>

class AObject : public QObject
{
    Q_OBJECT
public:
    explicit AObject(QObject *parent = nullptr);

signals:
    void signalFunciton(QString param);

};

#endif // AOBJECT_H
