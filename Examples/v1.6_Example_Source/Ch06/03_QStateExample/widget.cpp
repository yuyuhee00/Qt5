#include "widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    resize(360, 290);

    m_button = new QPushButton("Button", this);
    m_button->setGeometry(10, 10, 100, 30);

    m_stateMachine = new QStateMachine;

    m_state1 = new QState(m_stateMachine); // state-1
    m_state1->assignProperty(m_button, "geometry", QRect(10, 10, 100, 30));
    m_stateMachine->setInitialState(m_state1);

    m_state2 = new QState(m_stateMachine); // state-2
    m_state2->assignProperty(m_button, "geometry", QRect(250, 250, 100, 30));

    QSignalTransition* transition1 = m_state1->addTransition(m_button, SIGNAL(clicked()), m_state2); // transition-1
    transition1->addAnimation(new QPropertyAnimation(m_button, "geometry"));

    QSignalTransition* transition2 = m_state2->addTransition(m_button, SIGNAL(clicked()), m_state1); // transition-2
    transition2->addAnimation(new QPropertyAnimation(m_button, "geometry"));

    m_stateMachine->start();
}

Widget::~Widget()
{

}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter;
    painter.begin(this);

    int w = this->window()->width();
    int h = this->window()->height();

    int xPos = w - 10 - 100;
    int yPos = h - 10 - 30;

    m_state2->assignProperty(m_button, "geometry", QRect(xPos, yPos, 100, 30));

    painter.end();
}
