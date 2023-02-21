#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QProcess>
#include <QVariant>

class Task : public QProcess
{
    Q_OBJECT

public:
    explicit Task(QObject *parent = nullptr);

signals:

public slots:
     void start(const QString &program, const QVariantList &arguments);
    QString readAll();
    QString readyReadStandardOutput();
};

#endif // TASK_H
