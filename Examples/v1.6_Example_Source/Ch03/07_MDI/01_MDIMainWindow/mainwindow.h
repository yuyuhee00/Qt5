#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MDIMainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    MDIMainWindow* mdiWindow;

signals:
    void addSubWindow();

private slots:
    void newFile();
    void open();
};

#endif // MAINWINDOW_H
