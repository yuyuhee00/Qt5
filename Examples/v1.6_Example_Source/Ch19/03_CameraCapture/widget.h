#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void initCamera();
    void cameraDevicesSearch();

private:
    Ui::Widget *ui;
    QCamera           *mCamera;
    QCameraViewfinder *mViewfinder;

    QCameraImageCapture *mCapture;
    QList<QByteArray> camDevNameLists;

private slots:
    void onStartBtn();
    void onStopBtn();
    void onCaptureBtn();
    void camError(QCamera::Error error);
    void imageCaptured(int pId, QImage pPreview);
};

#endif // WIDGET_H
