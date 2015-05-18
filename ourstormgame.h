#ifndef OURSTORMGAME_H
#define OURSTORMGAME_H
#include "game.h"
#include "spaceship.h"
#include "drawablestrategy.h"
#include "star.h"
#include "bullet.h"
#include <vector>
#include <map>

using namespace std;

/**
 * @brief La classe OurStormGame permet la gestion globale du jeu
 */
class OurStormGame : public Game
{
    Q_OBJECT
public:
    OurStormGame(const QSize &size, QObject *parent = nullptr);
    ~OurStormGame();
    virtual void draw(QPainter &painter, QRect &rect);
    void mousePressed( int x, int y);
    void keyPressed( int key );
    void keyReleased( int key );

protected:
    virtual void step();
    void initialize();

private:
    bool checkStarColision(Star &star, DrawableObject &object);
    int checkStarColision(Star &star, vector<Bullet> &bullets);

    /**
     * @brief chooseRandomDirection choissie une direction aléatoire.
     * @return
     */
    QPointF chooseRandomDirection();

    /**
     * @brief chooseRandomPosition choissie une position aléatoire.
     * @return
     */
    QPoint chooseRandomPosition();

    /**
     * @brief removeUnActive supprime tous les objets qui ne sont plus actif
     */
    void removeUnActive();

    /**
     * @brief stepStar incremente les étoiles.
     */
    void stepStar();

    /**
     * @brief stepBullet incremente les missiles.
     */
    void stepBullet();

    /**
     * @brief createNewBullet crée un nouveau missile
     */
    void createNewBullet();

    /**
     * @brief createNewStar crée une nouvelle étoiles
     */
    void createNewStar(QPoint &pos, QPointF &dir, int size);

    /**
     * @brief startTheSpaceShip démare le vaisseau à millieux de l'écran
     */
    void startTheSpaceShip();

    SpaceShip _spaceShip;
    DrawableStrategy *_lifeDrawStrat;
    vector<Star> _stars;
    vector<Bullet> _bullets;
    bool _isShooting;
    int _normalSpeedBuletIntervalTik;
    int _normalSpeedGrowStarIntervalTik;
    typedef map<Star, int> StarTikGrowMap;
    typedef pair<Star, int> StarTikGrowPair;
    StarTikGrowMap _starsTikGrow;
    int _bulletTik;
    int _score;
    int _life;
};

#endif // OURSTORMGAME_H
