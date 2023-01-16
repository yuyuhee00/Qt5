#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QDebug>

#include "../mylib/mylib.h"

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);

    void start();
    void stop();

signals:
    void limit();

public slots:
    void started();
    void stopped();
    void triggered(QString value);

private:
    Mylib m_mylib;
    int m_count;
};

#endif // CLIENT_H
