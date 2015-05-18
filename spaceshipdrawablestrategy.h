#ifndef SPACESHIPDRAWABLESTRATEGY_H
#define SPACESHIPDRAWABLESTRATEGY_H
#include "drawablestrategy.h"

/**
 * @brief La classe SpaceShipDrawableStrategy permet la gestion du dessin d'un vaisseau
 */
class SpaceShipDrawableStrategy : public DrawableStrategy
{
public:
    SpaceShipDrawableStrategy();
    void draw(QPainter &painter, QRect &rect, double xRatio, double yRatio, QPoint &pos, int size, int rotation = 0);

    /**
     * @brief rotatePoint effectue une rotation d'un point par rapport à un centre et un angle en radian
     */
    void rotatePoint(QPoint &point, QPoint &axis, float radianRotation);
};

#endif // SpaceShipDrawableStrategy_H
