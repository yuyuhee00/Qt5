#ifndef PERSON_H
#define PERSON_H

#include <QObject>

class Person : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name MEMBER m_name READ getName WRITE setName
               NOTIFY nameChanged)

public:
    explicit Person(QObject *parent = nullptr);

    QString getName() const
    {
        return m_name;
    }

    void setName(const QString &n)
    {
        m_name = n;
        emit nameChanged(n);
    }

private:
    QString m_name;

signals:
    void nameChanged(const QString &n);

public slots:
};

#endif // PERSON_H
