#ifndef QMDIMAINWINDOW_H
#define QMDIMAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QMdiArea>

class MDIMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MDIMainWindow(QWidget *parent = nullptr);

private:
    QMdiArea* mdiAria;

public slots:
    void addSubWindow();
};

#endif // QMDIMAINWINDOW_H
