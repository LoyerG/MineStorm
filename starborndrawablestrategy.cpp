#include "starborndrawablestrategy.h"

StarBornDrawableStrategy::StarBornDrawableStrategy()
{
}

void StarBornDrawableStrategy::draw(QPainter &painter, QRect &rect, double xRatio, double yRatio, QPoint &pos, int size, int rotation)
{
    //DRAW HERE THE start when they are born (very small)
    // IGNORE THE SIZE VARAIBLE

    int taille = 3;
    painter.fillRect(pos.x() * xRatio, pos.y() * yRatio, taille, taille, painter.pen().color());
}
