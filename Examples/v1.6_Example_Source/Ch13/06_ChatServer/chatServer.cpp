#include <QtWidgets>
#include <QRegExp>
#include "chatserver.h"
#include <QDebug>

ChatServer::ChatServer(QObject *parent)
    : QTcpServer(parent)
{
}

void ChatServer::incomingConnection(int socketfd)
{
    qDebug() << Q_FUNC_INFO;

    QTcpSocket *client = new QTcpSocket(this);
    client->setSocketDescriptor(socketfd);
    clients.insert(client);

    emit clients_signal(clients.count());

    QString str;
    str = QString("새로운 접속자: %1")
            .arg(client->peerAddress().toString());

    emit message_signal(str);

    connect(client, SIGNAL(readyRead()), this,
                    SLOT(readyRead()));
    connect(client, SIGNAL(disconnected()), this,
                    SLOT(disconnected()));
}

void ChatServer::readyRead()
{
    QTcpSocket *client = (QTcpSocket*)sender();
    while(client->canReadLine())
    {
        QString line = QString::fromUtf8(client->readLine()).trimmed();

        QString str;
        str = QString("Read line: %1").arg(line);

        emit message_signal(str);

        QRegExp meRegex("^/me:(.*)$");

        if(meRegex.indexIn(line) != -1)
        {
            QString user = meRegex.cap(1);
            users[client] = user;
            foreach(QTcpSocket *client, clients)
            {
                client->write(QString("서버: %1 접속")
                              .arg(user).toUtf8());
            }

            sendUserList();
        }
        else if(users.contains(client))
        {
            QString message = line;
            QString user = users[client];

            QString str;
            str = QString("유저명: %1, 메시지: %2")
                    .arg(user).arg(message);
            emit message_signal(str);

            foreach(QTcpSocket *otherClient, clients)
                otherClient->write(QString(user+":"+message+"\n")
                                        .toUtf8());
        }
    }
}

void ChatServer::disconnected()
{
    QTcpSocket *client = (QTcpSocket*)sender();

    QString str;
    str = QString("접속자 연결 종료 :: %1")
            .arg(client->peerAddress().toString());

    emit message_signal(str);

    clients.remove(client);

    emit clients_signal(clients.count());

    QString user = users[client];
    users.remove(client);

    sendUserList();
    foreach(QTcpSocket *client, clients)
        client->write(QString("서버: %1 접속종료").arg(user).toUtf8());

}

void ChatServer::sendUserList()
{
    QStringList userList;
    foreach(QString user, users.values())
        userList << user;

    foreach(QTcpSocket *client, clients)
        client->write(QString("/유저:" + userList.join(",") + "\n")
                       .toUtf8());
}
