#ifndef TCPCONNECTIONELEMENT_H
#define TCPCONNECTIONELEMENT_H

#include <QObject>

class QTcpServer;
class QTcpSocket;

class TcpConnection : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int port READ port WRITE setPort NOTIFY portChanged)

    Q_PROPERTY(QString hostName
               READ hostName
               WRITE setHostName
               NOTIFY hostNameChanged)

    Q_PROPERTY(ConnectionType type
               READ connectionType
               WRITE setConnectionType
               NOTIFY connectionTypeChanged)

public:
    enum ConnectionType {
        Server,
        Client
    };
    Q_ENUMS(ConnectionType)

    TcpConnection(QObject *parent = nullptr);
    void setConnectionType(ConnectionType connectionType);
    ConnectionType connectionType() const;

    void setPort(int port);
    int port() const;

    void setHostName(const QString &hostName);
    QString hostName() const;

public slots:
    void initialize();
    void sendData(const QString &data);

signals:
    void dataReceived( const QString &data );
    void portChanged();
    void hostNameChanged();
    void connectionTypeChanged();

private slots:
    void receivedData();
    void slotConnection();

private:
    int m_port;
    QString m_hostName;
    ConnectionType m_connectionType;

    QTcpServer *m_tcpServer;
    QTcpSocket *m_tcpSocket;
};

#endif
