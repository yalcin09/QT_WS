#ifndef SIGNALA_H
#define SIGNALA_H

#include <QObject>

class SignalA : public QObject
{
    Q_OBJECT
public:
    explicit SignalA(QObject *parent = nullptr);
    void makeOperationSignal();

signals:
    int onOperation(int a, int b);

public slots:
};

#endif // SIGNALA_H
