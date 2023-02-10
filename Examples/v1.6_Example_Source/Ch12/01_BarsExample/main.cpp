#include <QApplication>
#include <QtDataVisualization>

using namespace QtDataVisualization;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QBarDataRow *data1 = new QBarDataRow;
    *data1 << 1.0f << 3.0f << 7.5f << 5.0f << 2.2f;
    QBarDataRow *data2 = new QBarDataRow;
    *data2 << 5.0f << 2.0f << 9.5f << 1.0f << 7.2f;

    QBar3DSeries *series = new QBar3DSeries;
    series->dataProxy()->addRow(data1);
    series->dataProxy()->addRow(data2);

    Q3DBars *bars = new Q3DBars;
    bars->setFlags(bars->flags() ^ Qt::FramelessWindowHint);
    bars->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetFront);
    bars->rowAxis()->setRange(0,4);
    bars->columnAxis()->setRange(0,4);
    bars->addSeries(series);
    bars->setFloorLevel(0);
    bars->setGeometry(50,50,600,400);
    bars->show();

    return a.exec();
}
