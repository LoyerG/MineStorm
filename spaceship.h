#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "drawableobject.h"
#include "bullet.h"

using namespace std;

/**
 * @brief La classe SpaceShip permet la gestion du vaisseau
 */
class SpaceShip : public DrawableObject
{
public:
    SpaceShip(const QPoint &pos);
    SpaceShip();
    void draw(QPainter &painter, QRect &rect, double xRatio, double yRatio);
    void step();

    /**
     * @brief createBullet crée un missile en fonction de l'emplacement du vaisseau
     * @return
     */
    Bullet createBullet();

    /**
     * @brief Rotation retourne la rotation de l'objet en degres.
     * Une rotation possitive est égal à sens des aiguilles d'une montre
     * @return
     */
    int Rotation() const;

    /**
     * @brief setRotation definie la rotation de l'objet en degres.
     * Une rotation possitive est égal à sens des aiguilles d'une montre
     * @param rot
     */
    void setRotation(int rot);
    void kill();
    void setAcceleration(double acc);

    /**
     * @brief reborn reinitialise le vaisseau
     */
    void reborn();

private:
    /**
     * @brief calcDirectionFromRotation calcule une vecteur de direction en fonction de la rotation du vaisseau
     * @return
     */
    QPointF calcDirectionFromRotation();

    int _rotation;
    int _bornSize;
};

#endif // SPACESHIP_H
