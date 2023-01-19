#include "widget.h"
#include "ui_widget.h"

#include <QHBoxLayout>
#include <QtCharts>
#include <QGraphicsView>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    QLineSeries* series = new QLineSeries();
    series->append(0, 6); // 데이터 삽입
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3)
            << QPointF(17, 6) << QPointF(18, 3)<< QPointF(20, 2);

    QSplineSeries* series1 = new QSplineSeries();
    series1->append(0, 5); // 데이터 삽입
    series1->append(2, 3);
    series1->append(3, 7);
    series1->append(7, 3);
    series1->append(10, 4);
    *series1 << QPointF(11, 2) << QPointF(13, 4)
             << QPointF(17, 7) << QPointF(18, 4)<< QPointF(20, 3);

    QScatterSeries* series2 = new QScatterSeries();
    *series2 << QPointF(1,5) << QPointF(6,6)
             << QPointF(12,3) << QPointF(17,5);

    QChart *chart = new QChart();
    chart->legend()->hide();  // 범례 숨김
    chart->addSeries(series); // series 추가
    chart->addSeries(series1);
    chart->addSeries(series2);
    chart->createDefaultAxes(); // 기본 축 생성
    chart->setTitle("Line chart 예제");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QHBoxLayout *hLay = new QHBoxLayout();
    hLay->addWidget(chartView);
    setLayout(hLay);
}

Widget::~Widget()
{
    delete ui;
}
