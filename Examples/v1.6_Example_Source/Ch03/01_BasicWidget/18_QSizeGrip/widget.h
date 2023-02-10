#ifndef WIDGET_H
#define WIDGET_H

#include <QSizeGrip>
#include <QBoxLayout>
#include <QTextEdit>
#include <QSplitter>

// SubWindow 클래스 위젯
class SubWindow : public QWidget
{
    Q_OBJECT
public:
    SubWindow(QWidget *parent = nullptr) : QWidget(parent, Qt::SubWindow)
    {
        QSizeGrip *sizegrip = new QSizeGrip(this);
        //sizegrip->setFixedSize(sizegrip->sizeHint());

        this->setLayout(new QVBoxLayout);
        this->layout()->setMargin(0);

        layout()->addWidget(new QTextEdit);

        sizegrip->setWindowFlags(Qt::WindowStaysOnTopHint);
        sizegrip->raise();
     }

    QSize sizeHint() const
    {
        return QSize(200, 100);
    }
};

// Widget 클래스 위젯, SubWindow의 부모 클래스 위젯
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};

#endif // WIDGET_H
