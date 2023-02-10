#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <QQmlProperty>
#include <QDebug>
#include <QTimer>

class Message : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString  author
               READ     author
               WRITE    setAuthor
               NOTIFY   authorChanged)
public:
    void setAuthor(const QString &a)
    {
        m_author = QString("%1 world.").arg(a);
        emit authorChanged();
    }

    QString author() const
    {
        return m_author;
    }

signals:
    void authorChanged();


private:
    QString m_author;

};

#endif // MESSAGE_H

