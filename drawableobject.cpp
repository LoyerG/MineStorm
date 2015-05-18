#include "drawableobject.h"

DrawableObject::DrawableObject(const QPoint &pos)
{
    _position = pos;
    _size = 1;
    _state = ObjectState::BORN;
    _startingExplodingSize = 20;
    _endingExplodingSize = 80;
    _normalSpeedExplodeIntervalTik = 1;
    _isActive = true;
}

DrawableObject::DrawableObject()
{
    (QPoint(0,0));
}

DrawableObject::~DrawableObject()
{
}

void DrawableObject::step()
{
    growExplosion();
    // move object below

    int newX = _position.x() + (_direction.x() * _acceleration);
    int newY = _position.y() + (_direction.y() * _acceleration);
    _position.setX(newX);
    _position.setY(newY);
}

void DrawableObject::draw(QPainter &painter, QRect &rect, double xRatio, double yRatio)
{
    // Do not draw the object here but in the method draw at the right strategy
    if (_position.x() < (-50) ||
            _position.x() > (rect.width() / xRatio) ||
            _position.y() < (-50) ||
            _position.y() > (rect.height() / yRatio)) {
        this->setIsActive(false);
    } else {
        _drawableStrategy->draw(painter, rect, xRatio, yRatio, _position, _size);
    }
}

bool DrawableObject::isActive() const
{
    return _isActive;
}

void DrawableObject::setIsActive(bool active)
{
    _isActive = active;
}

const QPoint &DrawableObject::position() const
{
    return _position;
}

const QPointF &DrawableObject::direction() const
{
    return _direction;
}

void DrawableObject::setPosition(QPoint &pos)
{
    _position = pos;
}

void DrawableObject::setDirection(QPointF &dir)
{
    _direction = dir;
}

double DrawableObject::acceleration() const
{
    return _acceleration;
}

void DrawableObject::setAcceleration(double acc)
{
    _acceleration = acc;
}

int DrawableObject::size() const
{
    return _size;
}

void DrawableObject::setSize(int newSize)
{
    _size = newSize;
}

bool DrawableObject::checkState(ObjectState state) const
{
    return _state == state;
}

void DrawableObject::startExploding()
{
    _currentExplodingTik = 0;
    _size = _startingExplodingSize;
}

void DrawableObject::endExploding()
{
    _isActive = false;
    _state = ObjectState::DEAD;
}

void DrawableObject::growExplosion()
{
    if (checkState(ObjectState::EXPLODING)) {
        ++_currentExplodingTik;
        if (_size >= _endingExplodingSize) {
            endExploding();
        } else if (_currentExplodingTik == _normalSpeedExplodeIntervalTik) {
            _currentExplodingTik = 0;
        }
        ++_size;
        ++_size;
        QPoint newPos = QPoint(_position.x()-1,_position.y()-1);
        setPosition(newPos);
    }
}
