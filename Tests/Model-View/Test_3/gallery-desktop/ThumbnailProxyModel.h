#pragma once

#include <QIdentityProxyModel>
#include <QHash>
#include <QPixmap>

class PictureModel;

class ThumbnailProxyModel : public QIdentityProxyModel
{
    Q_OBJECT

public:
    explicit ThumbnailProxyModel(QObject *parent = nullptr);

    PictureModel* pictureModel() const;


public:
    // QAbstractItemModel interface
    QVariant data(const QModelIndex &index, int role) const override;
    // QAbstractProxyModel interface
    void setSourceModel(QAbstractItemModel *sourceModel) override;

private:
    void generateThumbnails(const QModelIndex& startIndex, int count);
    void reloadThumbnails();

private:
    QHash<QString, QPixmap*> m_thumbnails;
};

