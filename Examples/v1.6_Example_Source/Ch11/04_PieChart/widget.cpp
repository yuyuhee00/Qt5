#include "widget.h"
#include "ui_widget.h"

#include <QHBoxLayout>
#include <QtCharts>
#include <QGraphicsView>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPieSeries *series = new QPieSeries();
    series->append("Jane", 1); // 이름과 비율을 함께 삽입
    series->append("Joe", 2);
    series->append("Andy", 3);
    series->append("Barbara", 4);
    series->append("Axel", 2);

    QPieSlice *slice = series->slices().at(1); // 두 번째 아이템 선택
    slice->setExploded(); // 아이템 분리
    slice->setLabelVisible(); // 아이템 네임 visible
    slice->setPen(QPen(Qt::darkGreen, 2));
    slice->setBrush(Qt::green);

    QChart *chart = new QChart();
    chart->legend()->hide();  // 범례 숨김
    chart->addSeries(series); // series 추가
    chart->createDefaultAxes(); // 기본 축 생성
    chart->setTitle("Pie chart 예제");

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
