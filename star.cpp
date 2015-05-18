#include "star.h"
#include "starborndrawablestrategy.h"
#include "staralivedrawablestrategy.h"
#include "explodedrawablestrategy.h"

Star::Star(const QPoint &pos) : DrawableObject(pos)
{
    _size = 0; // choose randomly
    _acceleration = 0;
    _drawableStrategy = new StarBornDrawableStrategy();
}

Star::Star() : Star(QPoint(0,0))
{
}


void Star::kill()
{
    _drawableStrategy = new ExplodeDrawableStrategy();
    _state = ObjectState::EXPLODING;
    _size = _startingExplodingSize;
    _acceleration = 0;
}

void Star::grow()
{
    _state = ObjectState::ALIVE;
    _drawableStrategy = new StarAliveDrawableStrategy();
}
