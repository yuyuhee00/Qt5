#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QDebug>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr, QString name = "");

    void testing();

signals:
    void connected();
    void disconnected();
    void readyRead();
    void test(QString name);
};

#endif // CLIENT_H
