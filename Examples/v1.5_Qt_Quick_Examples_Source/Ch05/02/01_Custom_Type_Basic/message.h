#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <QQmlProperty>
#include <QDebug>
#include <QTimer>

class Message : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString author
               READ author WRITE setAuthor
               NOTIFY authorChanged)

public:
    Message() {
        qDebug() << "Message() Construction";
        QTimer::singleShot(3000, this, SLOT(timerTimeout()));
    }

    Q_INVOKABLE bool postMessage(const QString &msg) {
        qDebug() << "[C++ Layer] call postMessage method : "
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
    void newMessagePosted(const QString &subject);

private:
    QString m_author;

public slots:
    void refresh() {
        qDebug() << "Called the C++ slot";
    }

    void timerTimeout() {
        emit newMessagePosted("I am a boy");
    }
};

#endif // MESSAGE_H
