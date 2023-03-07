#include "CustomWidget.h"
#include <QVBoxLayout>
#include <QGraphicsItem>

CustomWidget::CustomWidget(QWidget *parent)
    : QWidget(parent)
{
    m_view = new QGraphicsView(this);
    m_scene = new QGraphicsScene(this);
    m_view->setScene(m_scene);

    QVBoxLayout* layout = new QVBoxLayout(this);
//    layout->setMargin(0);
    layout->addWidget(m_view);
    this->setLayout(layout);

    QGraphicsItem*  rect = m_scene->addRect(0, 0, 40, 40, QPen(QColor(51, 229, 181)), Qt::NoBrush);
    rect->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsSelectable);
}

CustomWidget::~CustomWidget()
{
}

