#pragma once

#include <QMainWindow>

class ImageModel;
class QAction;
class QTableView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void openImage(const QString &fileName);

public slots:
    void chooseImage();
    void showAboutBox();
    void updateView();

private:
    ImageModel *model;
    QString currentPath;
    QTableView *view;
};
