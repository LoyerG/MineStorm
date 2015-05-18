#include "spaceship.h"
#include "spaceshipdrawablestrategy.h"
#include "explodedrawablestrategy.h"

SpaceShip::SpaceShip(const QPoint &pos) : DrawableObject(pos)
{
    // Have to be a 3 multiple
    _bornSize = 18;
    _size = _bornSize;
    //initialisation de la direction du vaisseau. Au debut du jeux, pointe vers le haut
    _direction.setX(0);
    _direction.setY(-5);
    _rotation = 0;
    _acceleration = 0;
    _drawableStrategy = new SpaceShipDrawableStrategy();
    _state = ObjectState::ALIVE;
}

SpaceShip::SpaceShip() : SpaceShip(QPoint(0,0))
{
}

void SpaceShip::draw(QPainter &painter, QRect &rect, double xRatio, double yRatio)
{
    // Do not draw the object here but in the method
    if (_position.x() < -_size) {
        _position.setX(rect.width() / xRatio);
    } else if (_position.x() > rect.width() / xRatio) {
        _position.setX(-_size);
    }
    if (_position.y() < -_size) {
        _position.setY(rect.height() / yRatio);
    } else if (_position.y() > rect.height() / yRatio) {
        _position.setY(-_size);
    }
    _drawableStrategy->draw(painter, rect, xRatio, yRatio, _position, _size, _rotation);
}

void SpaceShip::step()
{
    QPointF direc = calcDirectionFromRotation();
    _direction = direc;
    DrawableObject::step();
}

int SpaceShip::Rotation() const
{
    return _rotation;
}

void SpaceShip::setRotation(int rot)
{
    _rotation = rot % 360;
}

void SpaceShip::setAcceleration(double acc)
{
    if (acc<0)
    {
        acc = 0;
    }
    else if (acc>3)
    {
        acc = 3;
    }
    DrawableObject::setAcceleration(acc);
}

Bullet SpaceShip::createBullet()
{
    QPointF dir = calcDirectionFromRotation();
    QPoint pos = _position;
    // make the bullet on the axis of the spaceship
    pos.setX(_position.x() + _size / 2);
    // calculate the center of the spaceship
    QPoint spaceShipCenter = QPoint(_position.x() + _size / 2, _position.y() + _size / 2);
    float radianRotation = _rotation * (3.14159265358979323846 / 180);
    float s = sin(radianRotation);
    float c = cos(radianRotation);
    // Rotate the points by the center of the spaceship
    int newX = c * (pos.x()-spaceShipCenter.x()) - s * (pos.y()-spaceShipCenter.y()) + spaceShipCenter.x();
    int newY = s * (pos.x()-spaceShipCenter.x()) + c * (pos.y()-spaceShipCenter.y()) + spaceShipCenter.y();
    pos.setX(newX);
    pos.setY(newY);

    Bullet newBullet = Bullet(pos);
    newBullet.setDirection(dir);
    newBullet.setAcceleration(_acceleration + 1);
    return newBullet;
}

QPointF SpaceShip::calcDirectionFromRotation()
{
    QPointF newDir;
    float radianRotation = _rotation * (3.14159265358979323846 / 180);
    float s = sin(radianRotation);
    float c = cos(radianRotation);
    // Rotate the points by the center of the spaceship
    newDir.setX(- s * (-5));
    newDir.setY(c * (-5));
    return newDir;
}

void SpaceShip::kill()
{
    _drawableStrategy = new ExplodeDrawableStrategy();
    _state = ObjectState::EXPLODING;
    _size = _startingExplodingSize;
    _acceleration = 0;
}

void SpaceShip::reborn()
{
    _drawableStrategy = new SpaceShipDrawableStrategy();
    _state = ObjectState::ALIVE;
    _acceleration = 0;
    _rotation = 0;
    _size = _bornSize;
    setIsActive(true);
}
