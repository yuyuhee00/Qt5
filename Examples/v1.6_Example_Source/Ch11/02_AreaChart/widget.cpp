#include "widget.h"
#include "ui_widget.h"

#include <QHBoxLayout>
#include <QtCharts>
#include <QGraphicsView>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    QLineSeries *series1 = new QLineSeries();
    QLineSeries *series2 = new QLineSeries();

    *series1 << QPointF(1, 5) << QPointF(3, 7) << QPointF(7, 6)
             << QPointF(9, 7) << QPointF(12, 6) << QPointF(16, 7)
             << QPointF(18, 5);
    *series2 << QPointF(1, 3) << QPointF(3, 4) << QPointF(7, 3)
             << QPointF(8, 2) << QPointF(12, 3) << QPointF(16, 4)
             << QPointF(18, 3);

    // QLineSeries 두 개로 QAreaSeries 생성
    QAreaSeries *series = new QAreaSeries(series1, series2);
    series->setName("Area Data"); //범례이름 설정
    QPen pen(Qt::blue);
    pen.setWidth(3);
    series->setPen(pen); // 테두리 색설정
    QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
    gradient.setColorAt(0.0, 0x3cc63c);
    gradient.setColorAt(1.0, 0x26f626);
    series->setBrush(gradient); // area 색설정

    QChart *chart = new QChart();
    chart->legend()->hide();  // 범례 숨김
    chart->addSeries(series); // series 추가
    chart->createDefaultAxes(); // 기본 축 생성
    chart->setTitle("Area chart 예제");

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
