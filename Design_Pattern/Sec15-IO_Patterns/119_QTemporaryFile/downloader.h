#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QFile>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>
#include <QTemporaryFile>

class Downloader : public QObject
{
    Q_OBJECT

public:
    explicit Downloader(QObject *parent = nullptr);

    void download(QString url);

signals:

private slots:
    void readyRead();
    void finished();

private:
    // when this is destroyed the file is removed!
    QTemporaryFile m_file;
    QNetworkAccessManager m_manager;
};

#endif // DOWNLOADER_H
