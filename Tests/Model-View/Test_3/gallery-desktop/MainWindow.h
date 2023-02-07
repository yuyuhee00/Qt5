#pragma once

#include <QMainWindow>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class GalleryWidget;
class PictureWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void displayGallery();
    void displayPicture(const QModelIndex& index);

private:
    Ui::MainWindow *ui;

    GalleryWidget* m_galleryWidget;
    PictureWidget* m_pictureWidget;
    QStackedWidget* m_stackedWidget;
};
