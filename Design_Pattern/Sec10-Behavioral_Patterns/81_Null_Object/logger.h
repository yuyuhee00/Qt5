#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDebug>

class Logger : public QObject
{
    Q_OBJECT

public:
    explicit Logger(QObject *parent = nullptr);

    void log(QString value);

    QFile *file() const;
    void setFile(QFile *file);

signals:

private:
    QFile *m_file;
};

#endif // LOGGER_H
