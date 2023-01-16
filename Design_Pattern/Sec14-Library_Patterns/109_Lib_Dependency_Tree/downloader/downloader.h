#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include "downloader_global.h"
#include <QString>
#include <QDebug>
#include "client.h"

class DOWNLOADER_EXPORT Downloader
{
public:
    Downloader();
    void download(QString url);

private:
    Client m_client;
};

#endif // DOWNLOADER_H
