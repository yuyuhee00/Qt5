#ifndef UPLOADER_H
#define UPLOADER_H

#include "uploader_global.h"
#include <QDebug>
#include <QString>
#include <QTcpSocket>

class UPLOADER_EXPORT Uploader
{
public:
    Uploader();
    void upload(QString filename);

    QTcpSocket *socket() const;
    void setSocket(QTcpSocket *socket);

private:
    QTcpSocket *m_socket;
};

#endif // UPLOADER_H
