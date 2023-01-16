#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDebug>
#include <QChildEvent>
#include <QMetaObject>
#include <QMetaMethod>
#include "client.h"

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

signals:

public slots:
    void connected();
    void disconnected();
    void readyRead();
    void test(QString name);

private slots:
    void internal();
};

#endif // SERVER_H
