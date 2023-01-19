#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <QQmlProperty>
#include <QDebug>

class Message : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString author
               READ author WRITE setAuthor
               NOTIFY authorChanged)

public:
    Message() {
        qDebug() << "Message() Construction";
    }

    Q_INVOKABLE bool postMessage(const QString &msg) {
        qDebug() << "[C++] call postMessage method : "
                 << msg;

        return true;
    }

    void setAuthor(const QString &a) {
        m_author = QString("%1 world.").arg(a);
        emit authorChanged();
    }

    QString author() const {
        return m_author;
    }

signals:
    void authorChanged();

private:
    QString m_author;

public slots:
    void refresh() {
        qDebug() << "Called the C++ slot";
    }
};

#endif // MESSAGE_H
