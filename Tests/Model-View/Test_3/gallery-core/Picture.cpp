#include "Picture.h"

Picture::Picture(const QString& filePath) : Picture(QUrl::fromLocalFile(filePath))
{
}
Picture::Picture(const QUrl& fileUrl)
    : m_id(-1)
    , m_albumId(-1)
    , m_fileUrl(fileUrl)
{
}

Picture::~Picture()
{
}

int Picture::id() const
{
    return m_id;
}

void Picture::setId(int newId)
{
    m_id = newId;
}

int Picture::albumId() const
{
    return m_albumId;
}

void Picture::setAlbumId(int newAlbumId)
{
    m_albumId = newAlbumId;
}

QUrl Picture::fileUrl() const
{
    return m_fileUrl;
}

void Picture::setFileUrl(const QUrl &newFileUrl)
{
    m_fileUrl = newFileUrl;
}
