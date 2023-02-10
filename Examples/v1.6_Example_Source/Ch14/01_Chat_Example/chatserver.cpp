
#include "chatserver.h"
#include "QtWebSockets/QWebSocketServer"
#include "QtWebSockets/QWebSocket"
#include <QtCore/QDebug>

QT_USE_NAMESPACE

ChatServer::ChatServer(quint16 port, QObject *parent) :
    QObject(parent), m_pWebSocketServer(Q_NULLPTR), m_clients()
{
    m_pWebSocketServer = new QWebSocketServer(
                                QStringLiteral("Chat Server"),
                                QWebSocketServer::NonSecureMode,
                                this);

    if (m_pWebSocketServer->listen(QHostAddress::Any, port))
    {
        qDebug() << "Chat Server listening on port" << port;
        connect(m_pWebSocketServer, &QWebSocketServer::newConnection,
                this, &ChatServer::onNewConnection);
    }
}

void ChatServer::onNewConnection()
{
    qDebug() << "New Connection ";

    QWebSocket *pSocket = m_pWebSocketServer->nextPendingConnection();

    connect(pSocket, &QWebSocket::textMessageReceived,
            this, &ChatServer::processMessage);
    connect(pSocket, &QWebSocket::disconnected,
            this, &ChatServer::socketDisconnected);

    m_clients << pSocket;
}

void ChatServer::processMessage(QString message)
{
    QWebSocket *pSender = qobject_cast<QWebSocket *>(sender());
    Q_FOREACH (QWebSocket *pClient, m_clients)
    {
        if (pClient != pSender)
        {
            pClient->sendTextMessage(message);
        }
    }

    qDebug() << "Send Message : " << message;
}

void ChatServer::socketDisconnected()
{
    qDebug() << "Client disconnect";

    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (pClient)
    {
        m_clients.removeAll(pClient);
        pClient->deleteLater();
    }
}

ChatServer::~ChatServer()
{
    m_pWebSocketServer->close();
    qDeleteAll(m_clients.begin(), m_clients.end());
}

