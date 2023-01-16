#include "uploader.h"

Uploader::Uploader()
{
}

void Uploader::upload(QString filename)
{
    qInfo() << "Upload: " << filename;
}

QTcpSocket *Uploader::socket() const
{
    return m_socket;
}

void Uploader::setSocket(QTcpSocket *socket)
{
    m_socket = socket;
}
