#ifndef EXPLODEDRAWABLESTRATEGY_H
#define EXPLODEDRAWABLESTRATEGY_H
#include "drawablestrategy.h"

/**
 * @brief La classe ExplodeDrawableStrategy permet la gestion du dessin d'une explotion en jeu
 */
class ExplodeDrawableStrategy : public DrawableStrategy
{
public:
    ExplodeDrawableStrategy();
    void draw(QPainter &painter, QRect &rect, double xRatio, double yRatio, QPoint &pos, int size, int rotation = 0);
};

#endif // ExplodeDrawableStrategy_H
