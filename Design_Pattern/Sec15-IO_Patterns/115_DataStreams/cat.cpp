#include "cat.h"

Cat::Cat(QObject *parent) : QObject(parent)
{
    m_name = "";
    m_color = "";
    m_hungry = false;
    m_age = 0;
}

int Cat::age() const
{
    return m_age;
}

void Cat::setAge(int age)
{
    m_age = age;
}

bool Cat::hungry() const
{
    return m_hungry;
}

void Cat::setHungry(bool hungry)
{
    m_hungry = hungry;
}

QString Cat::name() const
{
    return m_name;
}

void Cat::setName(const QString &name)
{
    m_name = name;
}

QString Cat::color() const
{
    return m_color;
}

void Cat::setColor(const QString &color)
{
    m_color = color;
}

bool Cat::toFile(QString path)
{
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly))
    {
        qWarning() << file.errorString();
        return false;
    }

    QDataStream stream(&file);

    //setting a version lets Qt know what to do!
    stream.setVersion(QDataStream::Qt_5_12);

    bool ok = toStream(stream);
    file.close();

    return ok;
}

bool Cat::fromFile(QString path)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        qWarning() << file.errorString();
        return false;
    }

    QDataStream stream(&file);

    //setting a version lets Qt know what to do!
    stream.setVersion(QDataStream::Qt_5_12);

    bool ok = fromStream(stream);
    file.close();

    return ok;
}

bool Cat::toStream(QDataStream &stream)
{
    //do some type of error handling here
    //SAME ORDER
    stream << m_name;
    stream << m_color;
    stream << m_hungry;
    stream << m_age;
    return  true;
}

bool Cat::fromStream(QDataStream &stream)
{
    //do some type of error handling here
    //SAME ORDER
    stream >> m_name;
    stream >> m_color;
    stream >> m_hungry;
    stream >> m_age;
    return  true;
}

void Cat::display()
{
    qInfo() << "Name:" << m_name;
    qInfo() << "Color:" << m_color;
    qInfo() << "Hungry:" << m_hungry;
    qInfo() << "Age:" << m_age;
}
