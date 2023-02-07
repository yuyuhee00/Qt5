#pragma once

#include "gallery-core_global.h"
#include <QString>

class GALLERYCORE_EXPORT Album
{
public:
    explicit Album(const QString& name = "");
    ~Album();

    int id() const;
    void setId(int newId);

    QString name() const;
    void setName(const QString &newName);

private:
    // Database ID
    int m_id;
    QString m_name;
};
