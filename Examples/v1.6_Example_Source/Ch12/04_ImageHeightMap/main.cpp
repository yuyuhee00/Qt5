#include <QApplication>
#include <QtDataVisualization>

using namespace QtDataVisualization;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Q3DSurface *surface = new Q3DSurface;
    surface->setFlags(surface->flags() ^ Qt::FramelessWindowHint);
    surface->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetFront);

    QImage heightMapImage(":/mountain.png");
    QHeightMapSurfaceDataProxy *heightMapProxy
                 = new QHeightMapSurfaceDataProxy(heightMapImage);

    QSurface3DSeries *series = new QSurface3DSeries(heightMapProxy);

    series->setItemLabelFormat(QStringLiteral("(@xLabel, @zLabel): @yLabel"));
    heightMapProxy->setValueRanges(34.0f, 40.0f, 18.0f, 24.0f);

    surface->axisX()->setLabelFormat("0.1f N");
    surface->axisZ()->setLabelFormat("0.1f E");
    surface->axisX()->setRange(34.0f, 40.0f);
    surface->axisY()->setAutoAdjustRange(true);
    surface->axisZ()->setRange(18.0f,  24.0f);

    surface->axisX()->setTitle(QStringLiteral("Latitude"));
    surface->axisY()->setTitle(QStringLiteral("Height"));
    surface->axisZ()->setTitle(QStringLiteral("Longitude"));

    surface->addSeries(series);
    surface->setGeometry(50,50,600,400);
    surface->show();

    return a.exec();
}
