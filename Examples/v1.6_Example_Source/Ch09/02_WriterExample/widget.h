#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFile>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget       *ui;
    QFile            *mWriteFile;
    QList<QString>   mOriData;

public slots:
    void writeButtonClicked();
};

#endif // WIDGET_H
