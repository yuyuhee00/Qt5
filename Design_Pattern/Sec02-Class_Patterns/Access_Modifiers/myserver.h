#ifndef MYSERVER_H
#define MYSERVER_H

/*

https://doc.qt.io/qt-5/qtcpserver.html

Private - Only this class
Public - Any class
Protected - Only this class or its sub classes

*/

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class MyServer : public QTcpServer
{
    //Private
    Q_OBJECT
public: //Any class
    explicit MyServer(QObject *parent = nullptr);

    //Public
signals:

private slots: //Private - Only this class
    void handleSocket(QTcpSocket *socket);

protected slots: //Public - Any class
    //void handleSocket(QTcpSocket *socket);

public slots: //Protected - Only this class or its sub classes



    // QTcpServer interface
protected:
    void incomingConnection(qintptr handle) override;
};

#endif // MYSERVER_H
