#include "widget.h"
#include "ui_widget.h"
#include <QIODevice>

#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->volSlider,    &QSlider::valueChanged,
            this,             &Widget::volSliderChanged);
    connect(ui->pbtSendStart, &QPushButton::clicked,
            this,             &Widget::sendStartBtn);
    connect(ui->pbtSendStop,  &QPushButton::clicked,
            this,             &Widget::sendStopBtn);

    ui->volSlider->setEnabled(false);
    ui->pbtSendStop->setEnabled(false);

    audioInitialize();
}

void Widget::audioInitialize()
{
    devList = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);

    for(int i = 0; i < devList.size(); ++i) {
        ui->comboDevList->addItem(devList.at(i).deviceName());
    }

    mDevInfo = devList.at(ui->comboDevList->currentIndex());

    mFormat.setSampleRate(8000);
    mFormat.setChannelCount(1);
    mFormat.setSampleSize(16);
    mFormat.setSampleType(QAudioFormat::SignedInt);
    mFormat.setByteOrder(QAudioFormat::LittleEndian);
    mFormat.setCodec("audio/pcm");

    mAudioInput = new QAudioInput(mDevInfo, mFormat, this);
    mInputVolume = ui->volSlider->value();

    ui->volLabel->setText(QString("%1 %").arg(mInputVolume));

    mBuffer = QByteArray(14096, 0);
    mElapsedTimer.start();
}

void Widget::volSliderChanged(int val)
{
    mInputVolume = val;
    ui->volLabel->setText(QString("%1 %").arg(mInputVolume));

    mAudioInput->setVolume(mInputVolume);
}

void Widget::sendStartBtn()
{
    mDevInfo = devList.at(ui->comboDevList->currentIndex());
    mAudioInput = new QAudioInput(mDevInfo, mFormat, this);

    connect(mAudioInput, SIGNAL(notify()),
                         SLOT(notified()));
    connect(mAudioInput, SIGNAL(stateChanged(QAudio::State)),
                         SLOT(stateChanged(QAudio::State)));

    mAudioInput->setVolume(qreal(mInputVolume) / 100);

    mInput = mAudioInput->start();
    connect(mInput, SIGNAL(readyRead()), this, SLOT(readMore()));
}

void Widget::sendStopBtn()
{
    if(mInput != nullptr) {
        disconnect(mInput, nullptr, this, nullptr);
        mInput = nullptr;
    }

    mAudioInput->stop();
    mAudioInput->disconnect(this);
    delete mAudioInput;
}

void Widget::notified()
{
    qDebug() << "elapsedUSecs   = " << mAudioInput->elapsedUSecs()
             << "processedUSecs = " << mAudioInput->processedUSecs();
}

void Widget::stateChanged(QAudio::State state)
{
    qDebug() << "state = " << state;

    if(state == QAudio::IdleState || state == QAudio::ActiveState)
    {
        ui->volSlider->setEnabled(true);
        ui->pbtSendStart->setEnabled(false);
        ui->pbtSendStop->setEnabled(true);
    }
    else if(state == QAudio::StoppedState)
    {
        ui->volSlider->setEnabled(false);
        ui->pbtSendStart->setEnabled(true);
        ui->pbtSendStop->setEnabled(false);
    }
}

void Widget::readMore()
{
    if(!mAudioInput)
        return;

    qint64 len = mAudioInput->bytesReady();
    if(len > 4096)
        len = 4096;

    qint64 readLen = mInput->read(mBuffer.data(), len);
    if(readLen > 0) {
        mUdpSocket.writeDatagram(mBuffer.data(),
                                 len,
                                 QHostAddress::LocalHost,
                                 15000);
    }
}

Widget::~Widget()
{
    delete ui;
}
