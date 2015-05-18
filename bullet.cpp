#include "bullet.h"
#include "bulletdrawablestrategy.h"

Bullet::Bullet(const QPoint &pos) : DrawableObject(pos)
{
    _size = 2;
    _acceleration = 2;
    _drawableStrategy = new BulletDrawableStrategy();
    _state = ObjectState::ALIVE;
    setIsActive(true);
}

Bullet::Bullet() : Bullet(QPoint(0,0))
{
}

void Bullet::kill()
{
    setIsActive(false);
    _state = ObjectState::DEAD;
}

