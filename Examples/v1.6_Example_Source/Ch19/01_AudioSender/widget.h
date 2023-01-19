#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QAudioInput>
#include <QUdpSocket>
#include <QHostAddress>
#include <QElapsedTimer>

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

    QAudioFormat      mFormat;

    QAudioDeviceInfo  mDevInfo;
    QAudioInput      *mAudioInput;
    QIODevice        *mInput;
    QByteArray        mBuffer;

    QElapsedTimer     mElapsedTimer;
    int               mInputVolume;

    void audioInitialize();

    QUdpSocket        mUdpSocket;

private slots:
    void volSliderChanged(int val);
    void sendStartBtn();
    void sendStopBtn();

    void notified();
    void stateChanged(QAudio::State state);
    void readMore();
};

#endif // WIDGET_H
