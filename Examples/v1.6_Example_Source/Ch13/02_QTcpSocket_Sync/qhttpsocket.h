#ifndef QHTTPSOCKET_H
#define QHTTPSOCKET_H

#include <QObject>
#include <QTcpSocket>

class QHttpSocket : public QObject
{
    Q_OBJECT
public:
    explicit QHttpSocket(QObject *parent = 0);
    ~QHttpSocket();
    void httpConnect();

signals:

public slots:
    void httpDisconnected();

private:
    QTcpSocket *socket;

};

#endif // QHTTPSOCKET_H
