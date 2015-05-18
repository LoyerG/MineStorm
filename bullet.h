#ifndef BULLET_H
#define BULLET_H
#include "drawableobject.h"

using namespace std;

/**
 * @brief La classe Bullet permet la gestion des missiles en jeu
 */
class Bullet : public DrawableObject
{
public:
    Bullet(const QPoint &pos);
    Bullet();
    void kill();
};

#endif // BULLET_H
