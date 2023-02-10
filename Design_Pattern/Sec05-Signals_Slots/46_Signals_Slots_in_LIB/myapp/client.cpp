#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{
    //Signals and slots work as expected
    connect(&m_mylib, &Mylib::started, this, &Client::started);
    connect(&m_mylib, &Mylib::stopped, this, &Client::stopped);
    connect(&m_mylib, &Mylib::triggered, this, &Client::triggered);
    connect(this, &Client::limit, &m_mylib, &Mylib::stop);
    m_count = 0;
}

void Client::start()
{
    m_count = 0;
    m_mylib.start();
}

void Client::stop()
{
    m_mylib.stop();
}

void Client::started()
{
    qInfo() << "Started";
}

void Client::stopped()
{
    qInfo() << "Stopped";
}

void Client::triggered(QString value)
{
    m_count++;
    if(m_count >= 5)
    {
        emit limit();
        return;
    }
    qInfo() << m_count << value;
}
