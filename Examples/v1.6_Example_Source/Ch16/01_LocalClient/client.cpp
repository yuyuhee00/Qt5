
#include <QtWidgets>
#include <QtNetwork>

#include "client.h"

Client::Client(QWidget *parent)
    : QDialog(parent)
{
    hostLabel = new QLabel(tr("Server name:"));
    hostLineEdit = new QLineEdit("MyServer");
    statusLabel = new QLabel(tr(""));
    reqButton = new QPushButton(tr("Request Msgs"));
    quitButton = new QPushButton(tr("Quit"));

    socket = new QLocalSocket(this);
    connect(reqButton, SIGNAL(clicked()),
            this, SLOT(requestNewMsg()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(socket, SIGNAL(error(QLocalSocket::LocalSocketError)),
            this, SLOT(sockError(QLocalSocket::LocalSocketError)));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(hostLabel, 0, 0);
    mainLayout->addWidget(hostLineEdit, 0, 1);
    mainLayout->addWidget(statusLabel, 2, 0, 1, 2);
    mainLayout->addWidget(reqButton, 3, 0, 1, 2);
    mainLayout->addWidget(quitButton, 4, 0, 1, 2);
    setLayout(mainLayout);

    setWindowTitle(tr("Client"));
    hostLineEdit->setFocus();
}

void Client::requestNewMsg()
{
    reqButton->setEnabled(false);
    //socket->abort();
    socket->connectToServer(hostLineEdit->text());
}

void Client::readData()
{
    statusLabel->setText(socket->readAll());
    reqButton->setEnabled(true);
}

void Client::sockError(QLocalSocket::LocalSocketError socketError)
{
    switch (socketError) {
    case QLocalSocket::ServerNotFoundError:
        qDebug() << "ServerNotFoundError";
        break;
    case QLocalSocket::ConnectionRefusedError:
        qDebug() << "ConnectionRefusedError";
        break;
    case QLocalSocket::PeerClosedError:
        qDebug() << "PeerClosedError";
        break;
    default:
        qDebug() << "Error : " << socket->errorString();
    }

    reqButton->setEnabled(true);
}

