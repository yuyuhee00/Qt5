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
    Ui::Widget *ui;
    QFile *mFile;

private slots:
    void slotPbtOpenPress();  // [File Open] 버튼과 여결된 Slot 함수
    void slotPbtWritePress(); // [File Write] 버튼과 여결된 Slot 함수
    void slotPbtClosePress(); // [File Close] 버튼과 여결된 Slot 함수
    void slotAboutToClose();
};

#endif // WIDGET_H
