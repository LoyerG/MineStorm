#include "bulletdrawablestrategy.h"
#include <QPainter>

BulletDrawableStrategy ::BulletDrawableStrategy ()
{
}

void BulletDrawableStrategy ::draw(QPainter &painter, QRect &rect, double xRatio, double yRatio, QPoint &pos, int size, int rotation)
{
    painter.fillRect(pos.x() * xRatio, pos.y() * yRatio, size * xRatio, size * yRatio, painter.pen().color());
}
