#ifndef BULLETDRAWABLESTRATEGY_H
#define BULLETDRAWABLESTRATEGY_H
#include "drawablestrategy.h"

/**
 * @brief La classe BulletDrawableStrategy permet la gestion du dessin des missiles en jeu
 */
class BulletDrawableStrategy : public DrawableStrategy
{
public:
    BulletDrawableStrategy();
    void draw(QPainter &painter, QRect &rect, double xRatio, double yRatio, QPoint &pos, int size, int rotation = 0);
};

#endif // BulletDrawableStrateg_H

