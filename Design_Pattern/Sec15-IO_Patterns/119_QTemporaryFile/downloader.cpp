#include "downloader.h"

Downloader::Downloader(QObject *parent) : QObject(parent)
{
   Q_UNUSED(parent);
}

void Downloader::download(QString url)
{
    // Unique file name generated
    if(!m_file.open())
    {
        qWarning() << m_file.errorString();
        return;
    }

    QNetworkRequest request;
    request.setUrl(QUrl(url));
    request.setRawHeader("User-Agent", "MyOwnBrowser 1.0");
    QNetworkReply *reply = m_manager.get(request);

    connect(reply, &QNetworkReply::finished, this, &Downloader::finished);
    connect(reply, &QNetworkReply::readyRead, this, &Downloader::readyRead);
}

void Downloader::readyRead()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if(!reply) return;
    m_file.write(reply->readAll());
}

void Downloader::finished()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if(!reply) return;
    reply->deleteLater();

    m_file.close();
    qInfo() << "Downloaded" << m_file.size() << "bytes";
    qInfo() << "File:" << m_file.fileName();
    qInfo() << "File will be removed when the class is destroyed!";

    m_file.remove();
}
