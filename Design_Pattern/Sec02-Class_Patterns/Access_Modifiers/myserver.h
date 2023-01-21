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
    // Private
    Q_OBJECT

    // Any class
public:
    explicit MyServer(QObject *parent = nullptr);

    // Public
signals:

    // Private - Only this class
private slots:
    void handleSocket(QTcpSocket *socket);

    // Protected - Only this class or its sub classes
protected slots:

     // Public - Any class
public slots:

    // QTcpServer interface
protected:
    void incomingConnection(qintptr handle) override;
};

#endif // MYSERVER_H
