#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>

class ChatServer : public QTcpServer
{
    Q_OBJECT

public:
    ChatServer(QObject *parent=0);

private slots:
    void readyRead();
    void disconnected();
    void sendUserList();

signals:
    void clients_signal(int users);
    void message_signal(QString msg);

protected:
    void incomingConnection(int socketfd);

private:
    QSet<QTcpSocket*> clients;
    QMap<QTcpSocket*,QString> users;
};

#endif // CHATSERVER_H
