#ifndef STARSHIPDRAWABLESTRATEGY_H
#define STARSHIPDRAWABLESTRATEGY_H
#include "drawablestrategy.h"

/**
 * @brief La classe StarShipDrawableStrategy permet la gestion du dessin du vaisseau mère
 */
class StarShipDrawableStrategy : public DrawableStrategy
{
public:
    StarShipDrawableStrategy();
    void draw(QPainter &painter, QRect &rect, double xRatio, double yRatio, QPoint &pos, int size, int rotation = 0);
};

#endif // STARSHIPDRAWABLESTRATEGY_H
