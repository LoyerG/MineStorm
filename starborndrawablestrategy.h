#ifndef STARBORNDRAWABLESTRATEGY_H
#define STARBORNDRAWABLESTRATEGY_H
#include "drawablestrategy.h"

/**
 * @brief La classe StarBornDrawableStrategy permet la gestion du dessin d'une étoile en cours de naissance
 */
class StarBornDrawableStrategy : public DrawableStrategy
{
public:
    StarBornDrawableStrategy();
    void draw(QPainter &painter, QRect &rect, double xRatio, double yRatio, QPoint &pos, int size, int rotation = 0);
};

#endif // StarBornDrawableStrategy_H
