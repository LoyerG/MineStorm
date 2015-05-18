#ifndef HEARTDRAWABLESTRATEGY_H
#define HEARTDRAWABLESTRATEGY_H
#include "drawablestrategy.h"

/**
 * @brief La classe HeartDrawableStrategy permet la gestion du dessin d'un coeur en jeu
 */
class HeartDrawableStrategy : public DrawableStrategy
{
public:
    HeartDrawableStrategy();
    void draw(QPainter &painter, QRect &rect, double xRatio, double yRatio, QPoint &pos, int size, int rotation = 0);
};

#endif // HEARTDRAWABLESTRATEGY_H
