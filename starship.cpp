#include "starship.h"
#include "starshipdrawablestrategy.h"
#include "explodedrawablestrategy.h"

StarShip::StarShip(const QPoint &pos) : DrawableObject(pos)
{
    _bornSize = 18;
    _size = _bornSize;
    _life = 5;
    _drawableStrategy = new StarShipDrawableStrategy;

}

StarShip::StarShip() : StarShip(QPoint(0,0))
{

}

void StarShip::kill()
{
   if(_life <= 0)
   {
    _drawableStrategy = new ExplodeDrawableStrategy();
    _state  = ObjectState::EXPLODING;
    _size = _startingExplodingSize;
    _acceleration = 0;
   }

}

void StarShip::reborn()
{
    _drawableStrategy = new StarShipDrawableStrategy();
    _state = ObjectState::ALIVE;
    _acceleration = 0;
    _size = _bornSize;
    setIsActive(true);
}

Star StarShip::createStar()
{
    QPointF dir = chooseRandomDirection();
    QPoint pos = chooseRandomPosition();
    int random = (rand() % 2);
    int size = 24; // BIG
    if (random == 0) {
        size = 8; // SMALL
    } else if (random == 1) {
        size = 16; // MEDIUM
    }
    Star newStar = Star(pos);
    newStar.setDirection(dir);
    newStar.setSize(size);

    return newStar;
}

void StarShip::setLife(int life)
{
    _life = life;
}

int StarShip::life() const
{
    return _life;
}

QPointF StarShip::chooseRandomDirection()
{
    return QPointF((rand() % 5) - (rand() % 5), (rand() % 5) - (rand() % 5));
}

QPoint StarShip::chooseRandomPosition()
{
    int x = (rand() % 200) - (rand() % 200) + _position.x();
    int y = (rand() % 50) - (rand() % 50) + _position.y();
    return QPoint(x,y);
}
