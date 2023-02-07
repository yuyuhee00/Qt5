#include "Album.h"

Album::Album(const QString& name)
    : m_id(-1)
    , m_name(name)
{
}

Album::~Album()
{
}

int Album::id() const
{
    return m_id;
}

void Album::setId(int newId)
{
    m_id = newId;
}

QString Album::name() const
{
    return m_name;
}

void Album::setName(const QString &newName)
{
    m_name = newName;
}
