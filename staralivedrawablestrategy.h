#ifndef STARALIVEDRAWABLESTRATEGY_H
#define STARALIVEDRAWABLESTRATEGY_H
#include "drawablestrategy.h"

/**
 * @brief La classe StarAliveDrawableStrategy permet la gestion du dessin d'une étoile vivante
 */
class StarAliveDrawableStrategy : public DrawableStrategy
{
public:
    StarAliveDrawableStrategy();
    void draw(QPainter &painter, QRect &rect, double xRatio, double yRatio, QPoint &pos, int size, int rotation = 0);
};

#endif // StarAliveDrawableStrategy_H
