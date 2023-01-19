#ifndef WIDGET_H
#define WIDGET_H

#include <QPushButton>
#include <QState>
#include <QSignalTransition>
#include <QStateMachine>
#include <QPropertyAnimation>
#include <QSignalTransition>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QStateMachine* m_stateMachine;
    QState* m_state1;
    QState* m_state2;

    QPushButton *m_button;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // WIDGET_H
