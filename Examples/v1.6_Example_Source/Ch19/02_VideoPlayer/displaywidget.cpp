#include "displaywidget.h"

#include <QKeyEvent>
#include <QMouseEvent>

DisplayWidget::DisplayWidget(QWidget *parent)
    : QVideoWidget(parent)
{
    setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    QPalette p = palette();
    p.setColor(QPalette::Window, Qt::black);
    setPalette(p);

    setAttribute(Qt::WA_OpaquePaintEvent);
}

void DisplayWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape && isFullScreen()) {
        setFullScreen(false);
        event->accept();
    } else if (event->key() == Qt::Key_Enter && event->modifiers() & Qt::Key_Alt) {
        setFullScreen(!isFullScreen());
        event->accept();
    } else {
        QVideoWidget::keyPressEvent(event);
    }
}

void DisplayWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    setFullScreen(!isFullScreen());
    event->accept();
}

void DisplayWidget::mousePressEvent(QMouseEvent *event)
{
    QVideoWidget::mousePressEvent(event);
}
