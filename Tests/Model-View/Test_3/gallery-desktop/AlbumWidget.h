#pragma once

#include <QWidget>
#include <QModelIndex>

namespace Ui {
class AlbumWidget;
}

class AlbumModel;
class PictureModel;
class QItemSelectionModel;
class ThumbnailProxyModel;

class AlbumWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AlbumWidget(QWidget *parent = nullptr);
    ~AlbumWidget();

    void setAlbumModel(AlbumModel* albumModel);
    void setAlbumSelectionModel(QItemSelectionModel* selectionModel);
    void setPictureModel(ThumbnailProxyModel* pictureModel);
    void setPictureSelectionModel(QItemSelectionModel* selectionModel);

signals:
    void pictureActivated(const QModelIndex& index);

private slots:
    void deleteAlbum();
    void editAlbum();
    void addPictures();

private:
    void clearUI();
    void loadAlbum(const QModelIndex& albumIndex);

private:
    Ui::AlbumWidget *ui;

    AlbumModel* m_albumModel;
    QItemSelectionModel* m_albumSelectionModel;
    ThumbnailProxyModel* m_pictureModel;
    QItemSelectionModel* m_pictureSelectionModel;
};

