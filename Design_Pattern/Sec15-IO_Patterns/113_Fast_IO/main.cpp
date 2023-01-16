#include <QCoreApplication>

/*
 What
 Fast IO!

 Description
 Disk IO is slow!

 Why
 Disk operations are slow, memory is always faster!

 Example
 Simplify coding with QFile and QBuffer

 Notes
 Avoid readAll
 Avoid making massive files in memory
 Keep it small and simple
 ReadWrite can be slower then Read or Write (Append is Write with a seek to the end)
 Do not write or read one byte at a time
 */

#include <QFile>
#include <QBuffer>
#include <QIODevice>
#include <QDebug>
#include <QTextStream> //Text
#include <QDataStream> //Raw data (non-text)


void writeDevice(QIODevice &device, QByteArray &data)
{
    if(!device.isWritable())
    {
        qWarning() << "Device not writable!";
        return;
    }

    QTextStream stream(&device);
    stream << data;
}

void readDevice(QIODevice &device)
{
    if(!device.isReadable())
    {
        qWarning() << "Device not readable!";
        return;
    }

    QTextStream stream(&device);
    while(!stream.atEnd()) {
        qInfo() << stream.readLine(1024);
    }
}

void testDevice(QIODevice &device)
{
    QByteArray data;
    data.append("Hello World\r\nHow are you");

    if(device.open(QIODevice::ReadWrite))
    {
        writeDevice(device, data);

        //device.close()
        //device.open(...)

        device.seek(0);
        readDevice(device);
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QBuffer buffer;
    QFile file("test.txt");

    testDevice(buffer);
    testDevice(file);

    return a.exec();
}
