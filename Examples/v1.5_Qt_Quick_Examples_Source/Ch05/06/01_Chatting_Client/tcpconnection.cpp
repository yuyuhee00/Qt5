#include "tcpconnection.h"
#include <QHostAddress>

#include <QTcpServer>
#include <QTcpSocket>

TcpConnection::TcpConnection(QObject *parent)
    : QObject(parent), m_hostName("127.0.0.1")
{
}

void TcpConnection::sendData(const QString &data)
{
    m_tcpSocket->write( data.toUtf8() + "\n" );
}

int TcpConnection::port() const
{
    return m_port;
}

void TcpConnection::setPort(int port)
{
    if (m_port != port) {
        m_port = port;
        emit portChanged();
    }
}

QString TcpConnection::hostName() const
{
    return m_hostName;
}

void TcpConnection::setHostName(const QString &hostName)
{
    if (m_hostName != hostName) {
        m_hostName = hostName;
        emit hostNameChanged();
    }
}

TcpConnection::ConnectionType TcpConnection::connectionType() const
{
    return m_connectionType;
}

void TcpConnection::setConnectionType(ConnectionType connectionType)
{
    if (m_connectionType != connectionType) {
        m_connectionType = connectionType;
        emit connectionTypeChanged();
    }
}

void TcpConnection::initialize()
{
    if ( m_connectionType == Server ) {
        m_tcpServer = new QTcpServer;
        m_tcpServer->listen( QHostAddress(m_hostName), m_port );
        connect( m_tcpServer, SIGNAL( newConnection() ), this, SLOT( slotConnection() ) );
    }
    else {
        m_tcpSocket = new QTcpSocket(this);
        m_tcpSocket->connectToHost( m_hostName, m_port );
        connect( m_tcpSocket, SIGNAL(readyRead()), this, SLOT(receivedData()) );
    }
}

void TcpConnection::slotConnection()
{
    m_tcpSocket = m_tcpServer->nextPendingConnection();
    connect( m_tcpSocket, SIGNAL(readyRead()), this, SLOT(receivedData()) );
}

void TcpConnection::receivedData()
{
    const QString txt = QString::fromUtf8(m_tcpSocket->readAll());
    emit dataReceived( txt );
}


