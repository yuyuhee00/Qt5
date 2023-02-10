#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    audioInitialize();
    networkInitialize();

    connect(ui->comboDevList, SIGNAL(currentIndexChanged(int)),
            this,             SLOT(devListIndexChanged(int)));
    connect(ui->volSlider,    &QSlider::valueChanged,
            this,             &Widget::volSliderChanged);
}

void Widget::audioInitialize()
{
    devList = QAudioDeviceInfo::availableDevices(QAudio::AudioOutput);

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

    mAudioOutput = new QAudioOutput(mDevInfo, mFormat, this);

    mOutput = mAudioOutput->start();

    mOutputVolume = ui->volSlider->value();
    ui->volLabel->setText(QString("%1 %").arg(mOutputVolume));

    mAudioOutput->setVolume(mOutputVolume);
}

void Widget::networkInitialize()
{
    mUdpSocket = new QUdpSocket(this);
    mUdpSocket->bind(QHostAddress::LocalHost, 15000);

    connect(mUdpSocket, SIGNAL(readyRead()),
            this,       SLOT(readUdpData()));
}

void Widget::devListIndexChanged(int index)
{
    qDebug() << Q_FUNC_INFO << "index :" << index;
    mDevInfo = devList.at(index);

    if(mOutput != nullptr) {
        disconnect(mOutput, nullptr, this, nullptr);
        mOutput = nullptr;
    }

    mAudioOutput->stop();
    mAudioOutput->disconnect(this);
    delete mAudioOutput;

    mAudioOutput = new QAudioOutput(mDevInfo, mFormat, this);
    mOutput = mAudioOutput->start();
}

void Widget::volSliderChanged(int val)
{
    mOutputVolume = val;
    ui->volLabel->setText(QString("%1 %").arg(mOutputVolume));

    mAudioOutput->setVolume(mOutputVolume);
}

void Widget::readUdpData()
{
    while (mUdpSocket->hasPendingDatagrams())
    {
        QNetworkDatagram datagram;
        datagram = mUdpSocket->receiveDatagram();

        QByteArray audioData = datagram.data();
        audioOutputProcess(audioData);
    }
}

void Widget::audioOutputProcess(const QByteArray &ba)
{
    qint64 len = ba.size();
    if(len > 0) {
        mOutput->write(ba.data(), ba.size());
    }
}


Widget::~Widget()
{
    delete ui;
}

