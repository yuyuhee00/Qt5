#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtMultimedia>
#include <QtNetwork>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    QList<QAudioDeviceInfo> devList;

    QAudioDeviceInfo    mDevInfo;
    int                 mOutputVolume;
    QAudioFormat        mFormat;
    QAudioOutput       *mAudioOutput;
    QIODevice          *mOutput;

    void audioInitialize();
    void audioOutputProcess(const QByteArray &ba);

    QUdpSocket *mUdpSocket;
    void networkInitialize();

private slots:
    void devListIndexChanged(int index);
    void volSliderChanged(int val);
    void readUdpData();
};

#endif // WIDGET_H
