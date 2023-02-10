#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);

    void download(QString url);

signals:

public slots:

private slots:
    void finished();

private:
    QNetworkAccessManager m_manager;

};

#endif // CLIENT_H
