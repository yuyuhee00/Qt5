#include "widget.h"
#include "ui_widget.h"

#include <QHBoxLayout>
#include <QtCharts>
#include <QGraphicsView>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    QBarSet *set1 = new QBarSet("John");
    QBarSet *set2 = new QBarSet("Jane");
    QBarSet *set3 = new QBarSet("Eddy");

    *set1 << 1 << 2 << 3 << 4 << 5 << 6;
    *set2 << 5 << 7 << 2 << 4 << 0 << 7;
    *set3 << 8 << 4 << 7 << 3 << 7 << 1;

    QBarSeries *series = new QBarSeries();
    series->append(set1);
    series->append(set2);
    series->append(set3);

    QStringList categories;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
    QBarCategoryAxis *axis = new QBarCategoryAxis;
    axis->append(categories);

    QChart *chart = new QChart();
    chart->addSeries(series); // series 추가
    chart->setTitle("Bar chart 예제");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    chart->addAxis(axis, Qt::AlignBottom);
    series->attachAxis(axis);

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
