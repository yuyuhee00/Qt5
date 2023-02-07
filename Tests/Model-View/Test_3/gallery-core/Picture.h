#pragma once

#include "gallery-core_global.h"
#include <QString>
#include <QUrl>

class GALLERYCORE_EXPORT Picture
{   
public:
    Picture(const QString& filePath = "");
    Picture(const QUrl& fileUrl);
    ~Picture();


    int id() const;
    void setId(int newId);

    int albumId() const;
    void setAlbumId(int newAlbumId);

    QUrl fileUrl() const;
    void setFileUrl(const QUrl &newFileUrl);

private:
    // belongs to m_albumId
    int m_id;
    int m_albumId;
    QUrl m_fileUrl;
};
