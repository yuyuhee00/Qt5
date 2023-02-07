#include "AlbumWidget.h"
#include "ui_AlbumWidget.h"
#include <QInputDialog>
#include <QFileDialog>
#include "AlbumModel.h"
#include "PictureModel.h"
#include "ThumbnailProxyModel.h"
#include "PIctureDelegate.h"

AlbumWidget::AlbumWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlbumWidget),
    m_albumModel(nullptr),
    m_albumSelectionModel(nullptr),
    m_pictureModel(nullptr),
    m_pictureSelectionModel(nullptr)
{
    ui->setupUi(this);

    clearUI();
    ui->thumbnailListView->setSpacing(5);
    ui->thumbnailListView->setResizeMode(QListView::Adjust);
    ui->thumbnailListView->setFlow(QListView::LeftToRight);
    ui->thumbnailListView->setWrapping(true);
    ui->thumbnailListView->setItemDelegate(new PIctureDelegate(this));

    QObject::connect(ui->thumbnailListView, &QListView::doubleClicked, this, &AlbumWidget::pictureActivated);
    QObject::connect(ui->deleteButton, &QPushButton::clicked, this, &AlbumWidget::deleteAlbum);
    QObject::connect(ui->editButton, &QPushButton::clicked, this, &AlbumWidget::editAlbum);
    QObject::connect(ui->addPictureButton, &QPushButton::clicked, this, &AlbumWidget::addPictures);
}

AlbumWidget::~AlbumWidget()
{
    delete ui;
}

void AlbumWidget::setAlbumModel(AlbumModel* albumModel)
{
    m_albumModel = albumModel;
    QObject::connect(m_albumModel, &QAbstractItemModel::dataChanged, [this](const QModelIndex& topLeft) {
        if(topLeft == m_albumSelectionModel->currentIndex()) { loadAlbum(topLeft); }
    });
}

void AlbumWidget::setAlbumSelectionModel(QItemSelectionModel* selectionModel)
{
    m_albumSelectionModel = selectionModel;
    QObject::connect(m_albumSelectionModel, &QItemSelectionModel::selectionChanged, [this](const QItemSelection& selected) {
        if(selected.isEmpty()) {
            clearUI();
            return;
        }
        loadAlbum(selected.indexes().first());
    });
}

void AlbumWidget::setPictureModel(ThumbnailProxyModel* pictureModel)
{
    m_pictureModel = pictureModel;
    ui->thumbnailListView->setModel(m_pictureModel);
}

void AlbumWidget::setPictureSelectionModel(QItemSelectionModel* selectionModel)
{
    ui->thumbnailListView->setSelectionModel(selectionModel);
}

void AlbumWidget::deleteAlbum()
{
    if(m_albumSelectionModel->selectedIndexes().isEmpty())
        return;

    int row = m_albumSelectionModel->currentIndex().row();
    m_albumModel->removeRow(row);

    QModelIndex prevIndex = m_albumModel->index(row-1, 0);
    if(prevIndex.isValid()) {
        m_albumSelectionModel->setCurrentIndex(prevIndex, QItemSelectionModel::SelectCurrent);
        return;
    }

    QModelIndex nextIndex = m_albumModel->index(row, 0);
    if(nextIndex.isValid()) {
        m_albumSelectionModel->setCurrentIndex(nextIndex, QItemSelectionModel::SelectCurrent);
        return;
    }
}

void AlbumWidget::editAlbum()
{    if(m_albumSelectionModel->selectedIndexes().isEmpty())
        return;

     QModelIndex currIndex = m_albumSelectionModel->selectedIndexes().first();
     QString oldName = m_albumModel->data(currIndex, AlbumModel::Roles::NameRole).toString();

     bool ok;
     QString newName = QInputDialog::getText(this,
                                             "Album's name",
                                             "Change Album name",
                                             QLineEdit::Normal,
                                             oldName,
                                             &ok);
      if(ok && !newName.isEmpty()) {
          m_albumModel->setData(currIndex, newName, AlbumModel::Roles::NameRole);
      }
}

void AlbumWidget::addPictures()
{
    QStringList filenames =
            QFileDialog::getOpenFileNames(this,
                                          "Add pictures",
                                          QDir::homePath(),
                                          "Picture files (*.jpg *.png)");
    if(!filenames.isEmpty()) {
        QModelIndex lastIndex;
        for(auto filename: filenames) {
            Picture picture(filename);
            lastIndex = m_pictureModel->pictureModel()->addPicture(picture);
        }
        ui->thumbnailListView->setCurrentIndex(lastIndex);
    }
}

void AlbumWidget::clearUI()
{
    ui->albumName->setText("");
    ui->deleteButton->setVisible(false);
    ui->editButton->setVisible(false);
    ui->addPictureButton->setVisible(false);
}

void AlbumWidget::loadAlbum(const QModelIndex& albumIndex)
{
    m_pictureModel->pictureModel()->setAlbumId(m_albumModel->data(albumIndex, AlbumModel::Roles::IdRole).toInt());
    ui->albumName->setText(m_albumModel->data(albumIndex, AlbumModel::Roles::NameRole).toString());
    ui->deleteButton->setVisible(true);
    ui->editButton->setVisible(true);
    ui->addPictureButton->setVisible(true);
}
