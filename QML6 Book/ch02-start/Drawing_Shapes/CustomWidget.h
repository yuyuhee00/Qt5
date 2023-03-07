#pragma once

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>

class CustomWidget : public QWidget
{
    Q_OBJECT

public:
    CustomWidget(QWidget *parent = nullptr);
    ~CustomWidget();

private:
    QGraphicsView* m_view;
    QGraphicsScene* m_scene;
};
