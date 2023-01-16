#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{
   Q_UNUSED(parent);
}

void Client::download(QString url)
{
    qInfo() << "Download: " << url;

    QNetworkRequest request;
    request.setUrl(QUrl(url));
    request.setRawHeader("User-Agent", "MyOwnBrowser 1.0");

    QNetworkReply *reply = m_manager.get(request);
    connect(reply,&QNetworkReply::finished, this, &Client::finished);
}

void Client::finished()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if(!reply) return;

    qInfo() << reply->readAll();

    reply->close();
    reply->deleteLater();
}
