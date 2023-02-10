#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->initCamera();
    this->cameraDevicesSearch();

    connect(ui->pbtStart, SIGNAL(clicked()),
            this, SLOT(onStartBtn()));
    connect(ui->pbtStop,  SIGNAL(clicked()),
            this, SLOT(onStopBtn()));
    connect(ui->pbtCapture, SIGNAL(clicked()),
            this, SLOT(onCaptureBtn()));
}

Widget::~Widget()
{
    delete ui;
    delete mCapture;
    delete mCamera;
}

void Widget::initCamera()
{
    mCamera = new QCamera;
    mCapture = new QCameraImageCapture(mCamera);

    mViewfinder = new QCameraViewfinder();

    QVBoxLayout *vLay = new QVBoxLayout();

    vLay->addWidget(mViewfinder);
    ui->camWidget->setLayout(vLay);
}

void Widget::cameraDevicesSearch()
{
    camDevNameLists.clear();
    ui->comboBox->clear();

    camDevNameLists.clear();
    ui->comboBox->clear();

    foreach (const QByteArray &deviceName, QCamera::availableDevices())
    {
        QString description = mCamera->deviceDescription(deviceName);
        camDevNameLists.append(deviceName);
        ui->comboBox->addItem(description);
    }
}

void Widget::onStartBtn()
{
    delete mCapture;
    delete mCamera;

    if(camDevNameLists.count() < 1) {
        mCamera = new QCamera;
    }else{
        int curIndex = ui->comboBox->currentIndex();
        mCamera = new QCamera(camDevNameLists.at(curIndex));
    }

    connect(mCamera, SIGNAL(error(QCamera::Error)),
            this,    SLOT(camError(QCamera::Error)));

    mCamera->setViewfinder(mViewfinder);

    mCamera->setCaptureMode(QCamera::CaptureVideo);
    mCapture = new QCameraImageCapture(mCamera);

    //imageCapture->setCaptureDestination(
    //              QCameraImageCapture::CaptureToBuffer);
    mCapture->setCaptureDestination(
                QCameraImageCapture::CaptureToBuffer |
                QCameraImageCapture::CaptureToFile);

    mCapture->setBufferFormat(QVideoFrame::Format_RGB32);
    connect(mCapture, SIGNAL(imageCaptured(int,QImage)),
            this, SLOT(imageCaptured(int,QImage)));

    mCamera->start();
}

void Widget::onStopBtn()
{
    mCamera->stop();
}

void Widget::onCaptureBtn()
{
    mCapture->capture("c:/CaptuerImage.jpg");
}

void Widget::camError(QCamera::Error error)
{
    qDebug() << Q_FUNC_INFO << "Error : " << error;
}

void Widget::imageCaptured(int pId, QImage pPreview)
{
    Q_UNUSED(pId);

    qDebug() << "IMAGE CAPTUER SIZE (WIDTH X HEIGHT) : "
             << pPreview.byteCount();
}









