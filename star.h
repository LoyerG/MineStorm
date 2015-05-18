#ifndef STAR_H
#define STAR_H
#include "drawableobject.h"

using namespace std;

/**
 * @brief La classe Star permet la gestion d'une étoile
 */
class Star : public DrawableObject
{
public:
    Star(const QPoint &pos);
    Star();
    void kill();

    /**
     * @brief grow fait passer une étoile de l'état en naissance à vivante
     * @return
     */
    void grow();

private:

};

#endif // STAR_H
