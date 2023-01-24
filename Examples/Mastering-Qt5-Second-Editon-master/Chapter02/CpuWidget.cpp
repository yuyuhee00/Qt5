#include "CpuWidget.h"

#include "SysInfo.h"
#include <QBrush>

//using namespace QtCharts;

CpuWidget::CpuWidget(QWidget* parent) :
    SysInfoWidget(parent),
    mSeries(new QPieSeries(this))
{
    // QPieSeries* mSeries;
    mSeries->setHoleSize(0.35);
    mSeries->append("CPU Load", 0.0);
    mSeries->append("CPU Free", 0.0);

    QChart* chart = chartView().chart();
    chart->addSeries(mSeries);
    chart->setTitle("CPU average load");
}

void CpuWidget::updateSeries()
{
    double cpuLoadAverage = SysInfo::instance().cpuLoadAverage();
    mSeries->clear();

//    mSeries->append("Load", cpuLoadAverage);
//    mSeries->append("Free", 100.0 - cpuLoadAverage);
    QPieSlice* used = new QPieSlice(QString("CPU Load"), cpuLoadAverage);
    QPieSlice* free = new QPieSlice(QString("CPU Free"), 100.0 - cpuLoadAverage);

    used->setBrush(QBrush(QColor(255,0,0), Qt::SolidPattern));
    free->setBrush(QBrush(QColor(0,0,255), Qt::SolidPattern));
    mSeries->append(used);
    mSeries->append(free);
}
