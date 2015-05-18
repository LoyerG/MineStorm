#ifndef STARSHIP_H
#define STARSHIP_H
#include "drawableobject.h"
#include "star.h"

using namespace std;

/**
 * @brief La classe StarShip permet la gestion du vaisseau mère
 */
class StarShip : public DrawableObject
{
public:
    StarShip(const QPoint &pos);
    StarShip();
    void kill();

    /**
     * @brief createStar crée une étoile en fonction de l'emplacement du vaisseau
     * @return
     */
    Star createStar();

    /**
     * @brief reborn reinitialise le vaisseau
     */
    void reborn();

    /**
     * @brief life retourne le nombre de point de vie de l'objet.
     * @return
     */
    int life() const;

    /**
     * @brief setLife definie le nombre de point de vie de l'objet.
     * @param life
     */
    void setLife(int life);

    /**
     * @brief chooseRandomDirection choissie une direction aléatoire.
     * En fonction de l'emplacement du vaisseau
     * @return
     */
    QPointF chooseRandomDirection();

    /**
     * @brief chooseRandomPosition choissie une possition aléatoire.
     * En fonction de l'emplacement du vaisseau
     * @return
     */
    QPoint chooseRandomPosition();

private:
    int _bornSize;
    int _life;
};

#endif // STARSHIP_H
