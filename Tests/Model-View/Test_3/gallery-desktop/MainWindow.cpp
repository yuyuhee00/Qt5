#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "GalleryWidget.h"
#include "PictureWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_galleryWidget(new GalleryWidget(this))
    , m_pictureWidget(new PictureWidget(this))
    , m_stackedWidget(new QStackedWidget(this))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayGallery()
{

}

void MainWindow::displayPicture(const QModelIndex& index)
{

}
