#include "downloader.h"

Downloader::Downloader()
{
}

void Downloader::download(QString url)
{
    m_client.download(url);
}
