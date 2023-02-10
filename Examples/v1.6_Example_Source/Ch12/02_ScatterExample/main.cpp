#include <QApplication>
#include <QtDataVisualization>

using namespace QtDataVisualization;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QScatter3DSeries *series = new QScatter3DSeries;
    QScatterDataArray data;
    data << QVector3D(0.5f, 0.5f, 0.5f)
         << QVector3D(-0.3f, -0.5f, -0.4f)
         << QVector3D(0.0f, -0.3f, 0.2f);

    Q3DScatter *scatter = new Q3DScatter;
    scatter->setFlags(scatter->flags() ^ Qt::FramelessWindowHint);
    scatter->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetFront);
    series->dataProxy()->addItems(data);
    scatter->addSeries(series);
    scatter->setGeometry(50,50,600,400);
    scatter->show();

    return a.exec();
}
