#include "AlbumListWidget.h"
#include "ui_AlbumListWidget.h"
#include "AlbumModel.h"
#include <QInputDialog>

AlbumListWidget::AlbumListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlbumListWidget),
    m_albumModel(nullptr)
{
    ui->setupUi(this);

    QObject::connect(ui->createAlbumButton, &QPushButton::clicked, this, &AlbumListWidget::createAlbum);
}

AlbumListWidget::~AlbumListWidget()
{
    delete ui;
}

void AlbumListWidget::setModel(AlbumModel* model)
{
    m_albumModel = model;
    ui->albumList->setModel(model);
}

void AlbumListWidget::setSelectionModel(QItemSelectionModel* selectionModel)
{
    ui->albumList->setSelectionModel(selectionModel);
}

void AlbumListWidget::createAlbum()
{
    if(!m_albumModel) return;

    bool ok;
    QString albumName = QInputDialog::getText(this,
                                              "Create a new Album",
                                              "Choose an name",
                                              QLineEdit::Normal,
                                              "New album",
                                              &ok);
    if(ok && !albumName.isEmpty()) {
        Album album(albumName);
        QModelIndex createIndex = m_albumModel->addAlbum(album);
        ui->albumList->setCurrentIndex(createIndex);
    }
}
