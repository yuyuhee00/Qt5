#include <QtWidgets>
#include <QtNetwork>

#include "server.h"
#include <qlocalserver.h>
#include <qlocalsocket.h>

Server::Server(QWidget *parent)
    : QWidget(parent)
{
    statusLabel = new QLabel;
    statusLabel->setWordWrap(true);
    quitButton = new QPushButton(tr("Quit"));
    quitButton->setAutoDefault(false);

    server = new QLocalServer(this);
    if (!server->listen("MyServer")) {
        qDebug() << "Server error : "
                 << server->errorString();
        close();
        return;
    }

    connect(quitButton, SIGNAL(clicked()),
            this, SLOT(close()));
    connect(server, SIGNAL(newConnection()),
            this, SLOT(clientConnection()));

    statusLabel->setText(tr("Server is running."));
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(statusLabel);
    mainLayout->addWidget(quitButton);
    setLayout(mainLayout);

    setWindowTitle(tr("My Server"));
}

void Server::clientConnection()
{
    QByteArray writeData;

    if(msgKind) {
        writeData.append("Welcome to my server.");
        msgKind = false;
    } else {
        writeData.append("Who are you");
        msgKind = true;
    }

    QLocalSocket *clientConnection =
                     server->nextPendingConnection();

    connect(clientConnection, SIGNAL(disconnected()),
            clientConnection, SLOT(deleteLater()));

    clientConnection->write(writeData, writeData.size());
    clientConnection->flush();
    clientConnection->disconnectFromServer();
}
