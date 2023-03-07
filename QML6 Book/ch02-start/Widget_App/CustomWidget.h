#pragma once

#include <QWidget>

class CustomWidget : public QWidget
{
    Q_OBJECT

public:
    CustomWidget(QWidget *parent = nullptr);
    ~CustomWidget();

    // QWidget interface
public:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    QPoint m_lastPos;
};
