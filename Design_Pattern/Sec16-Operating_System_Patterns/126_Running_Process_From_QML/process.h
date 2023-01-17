#ifndef PROCESS_H
#define PROCESS_H

#include <QObject>
#include <QProcess>
#include <QVariant>

class Process : public QProcess
{
    Q_OBJECT
public:
    explicit Process(QObject *parent = nullptr);

signals:

public slots:
    void start(const QString &program, const QVariantList &arguments);
    QByteArray readAll();
};

#endif // PROCESS_H
