#include "triangleitem.h"
#include <QSGGeometryNode>

TriangleItem::TriangleItem(QQuickItem *parent)
    : QQuickItem(parent),
      m_geometry(QSGGeometry::defaultAttributes_Point2D(), 3)
{
    setFlag(ItemHasContents);
    m_material.setColor(Qt::red);
}

QSGNode *TriangleItem::updatePaintNode(QSGNode *n, UpdatePaintNodeData *)
{
    QSGGeometryNode *node = static_cast<QSGGeometryNode *>(n);
    if (!node) {
        node = new QSGGeometryNode();
    }

    QSGGeometry::Point2D *v = m_geometry.vertexDataAsPoint2D();
    const QRectF rect = boundingRect();
    v[0].x = (float)rect.left();
    v[0].y = (float)rect.bottom();

    v[1].x = (float)rect.left() + (float)rect.width()/2;
    v[1].y = (float)rect.top();

    v[2].x = (float)rect.right();
    v[2].y = (float)rect.bottom();

    node->setGeometry(&m_geometry);
    node->setMaterial(&m_material);

    return node;
}
