#ifndef BOBJECT_H
#define BOBJECT_H

#include <QObject>

class BObject : public QObject
{
    Q_OBJECT
public:
    explicit BObject(QObject *parent = nullptr);

signals:

public slots:
    void recieveBObject(QString param);
};

#endif // BOBJECT_H
