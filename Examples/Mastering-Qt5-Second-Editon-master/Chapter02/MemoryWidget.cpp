#include "MemoryWidget.h"

#include <QtCharts/QAreaSeries>
#include <QPen>
#include <QLinearGradient>

#include "SysInfo.h"

//using namespace QtCharts;

constexpr int CHART_X_RANGE_COUNT = 50;
constexpr int CHART_X_RANGE_MAX = CHART_X_RANGE_COUNT - 1;
constexpr int COLOR_DARK_BLUE = 0x209fdf;
constexpr int COLOR_LIGHT_BLUE = 0xbfdfef;
constexpr int PEN_WIDTH = 3;

MemoryWidget::MemoryWidget(QWidget *parent) :
    SysInfoWidget(parent),
    mSeries(new QLineSeries(this)),
    mPointPositionX(0)
{
    QPen pen(COLOR_DARK_BLUE);
    pen.setWidth(PEN_WIDTH);

    QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
    gradient.setColorAt(1.0, COLOR_DARK_BLUE);
    gradient.setColorAt(0.0, COLOR_LIGHT_BLUE);
    gradient.setCoordinateMode(QGradient::ObjectBoundingMode);

    // QLineSeries* mSeries;
    QAreaSeries* areaSeries = new QAreaSeries(mSeries);
    areaSeries->setPen(pen);
    areaSeries->setBrush(gradient);

    QChart* chart = chartView().chart();
    chart->addSeries(areaSeries);
    chart->setTitle("Memory used");
    chart->createDefaultAxes();

    auto xAxis = chart->axes(Qt::Horizontal);
    xAxis.at(0)->setRange(0, CHART_X_RANGE_MAX);
    xAxis.at(0)->setVisible(false);

    auto yAxis = chart->axes(Qt::Vertical);
    yAxis.at(0)->setRange(0, 100);

//    chart->axisX()->setRange(0, CHART_X_RANGE_MAX);
//    chart->axisX()->setVisible(false);
//    chart->axisY()->setRange(0, 100);
}

void MemoryWidget::updateSeries()
{
    double memoryUsed = SysInfo::instance().memoryUsed();
    mSeries->append(mPointPositionX++, memoryUsed);
    if (mSeries->count() > CHART_X_RANGE_COUNT) {
        QChart* chart = chartView().chart();
        chart->scroll(chart->plotArea().width() / CHART_X_RANGE_MAX, 0);
        mSeries->remove(0);
    }
}
