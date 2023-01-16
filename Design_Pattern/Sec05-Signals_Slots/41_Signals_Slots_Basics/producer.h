#ifndef PRODUCER_H
#define PRODUCER_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QSharedPointer>
#include "myclass.h"


class Producer : public QObject
{
    Q_OBJECT
public:
    explicit Producer(QObject *parent = nullptr);

public slots:
    void start();
    void stop();

private slots:
    void produced();

signals:
    void readyProduct(QSharedPointer<MyClass> ptr);

private:
    QTimer m_timer;
};

#endif // PRODUCER_H
