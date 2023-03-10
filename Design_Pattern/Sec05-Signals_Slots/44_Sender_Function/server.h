#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    explicit Server(QObject *parent = nullptr);
    ~Server();

    void close();

private:
    QString readLine(QTcpSocket *socket);

signals:

    // QTcpServer interface
protected:
    void incomingConnection(qintptr handle) override;
    bool hasPendingConnections() const override;
    QTcpSocket *nextPendingConnection() override;

public slots:
    void connected();
    void readyRead();
    void disconnected();

private:
    QList<QTcpSocket*> m_clients;
    void sendAll(QString value);
    QString clientName(QTcpSocket *socket);
};

#endif // SERVER_H
