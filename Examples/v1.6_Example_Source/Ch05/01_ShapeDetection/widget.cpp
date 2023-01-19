#include "widget.h"
#include "ui_widget.h"
#include <math.h>

#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_scene = new QGraphicsScene();
    m_scene->setSceneRect(-100, -100, 400, 400);
    m_scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    for (int i = 0; i < 5; ++i) {
        m_shape[i] = new Shape;
        m_shape[i]->setPos(::sin((i * 6.28) / 5) * 100,
                      ::cos((i * 6.28) / 5) * 100);
        m_scene->addItem(m_shape[i]);
    }

    ui->graphicsView->setScene(m_scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);

    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    ui->graphicsView->resize(500, 500);
    ui->graphicsView->show();


    QObject::connect(&m_timer, SIGNAL(timeout()), m_scene, SLOT(advance()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerStart()
{
    m_timer.start(30);
}


