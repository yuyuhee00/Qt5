#ifndef CAT_H
#define CAT_H

#include <QObject>
#include <QDebug>
#include <QFile>
#include <QDataStream>


class Cat : public QObject
{
    Q_OBJECT
public:
    explicit Cat(QObject *parent = nullptr);

    int age() const;
    void setAge(int age);

    bool hungry() const;
    void setHungry(bool hungry);

    QString name() const;
    void setName(const QString &name);

    QString color() const;
    void setColor(const QString &color);

    bool toFile(QString path);
    bool fromFile(QString path);
    bool toStream(QDataStream &stream);
    bool fromStream(QDataStream &stream);
    void display();

signals:

private:
    int m_age;
    bool m_hungry;
    QString m_name;
    QString m_color;
};

#endif // CAT_H
