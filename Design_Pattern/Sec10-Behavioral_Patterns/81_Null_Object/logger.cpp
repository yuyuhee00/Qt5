#include "logger.h"

Logger::Logger(QObject *parent) : QObject(parent)
{
    m_file = nullptr;
}

void Logger::log(QString value)
{
    qInfo() << value;

    if(!m_file)
    {
        qWarning() << "No file set!";
        return;
    }
    if(!m_file->isWritable())
    {
        qWarning() << "File not writable!";
        return;
    }

    // try to open a file here
    QTextStream stream(m_file);
    stream << value;
}

QFile *Logger::file() const
{
    return m_file;
}

void Logger::setFile(QFile *file)
{
    m_file = file;
}
