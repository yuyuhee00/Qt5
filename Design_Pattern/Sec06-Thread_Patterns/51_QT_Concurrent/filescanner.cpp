#include "filescanner.h"

FileScanner::FileScanner(QObject *parent) : QObject(parent)
{

}

void FileScanner::scan(QString path)
{
    qInfo() << "scan on" << QThread::currentThread();
    m_count = 0;

    // This could take a long time
    // QFuture<int> future = QtConcurrent::run(this, &FileScanner::performscan, path);
    QFuture<int> future = QtConcurrent::run(&FileScanner::performscan, this, path);

    // Main thread is not blocked, we can do other things
    qInfo() << "Main thread is free to do other things...";

    // Do something on Main Thread..........

    // Get the result from the Concurrent thread
    qInfo() << "Result:" << future.result();
}

int FileScanner::performscan(QString path)
{
    // Runs on the threadPool

    int value = 0;
    QDir dir(path);
    if(!dir.exists()) return -1;
    //qInfo() << "performing scan on" << QThread::currentThread();

    QFileInfoList list = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Dirs);
    value = list.length();

    // For GUI
    emit updated(value);

    foreach(QFileInfo item, list)
    {
        value = value + performscan(item.filePath());
    }

    return value;
}
