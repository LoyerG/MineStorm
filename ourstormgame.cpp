#include "ourstormgame.h"
#include "heartdrawablestrategy.h"
#include <QPainter>
#include <QFontDatabase>
#include <iostream>
#include "assert.h"
#include <time.h>

OurStormGame::OurStormGame(const QSize &size, QObject *parent) : Game(size,parent) {
    int loadedFontID = QFontDatabase::addApplicationFont(":/fonts/spaceage.ttf");
    assert(loadedFontID != -1);
    _bulletTik = 0;
    _isShooting = false;
    _normalSpeedBuletIntervalTik = 5; // 4 fire by second
    _normalSpeedGrowStarIntervalTik = 100; // 5 seconde before grow
    _lifeDrawStrat = new HeartDrawableStrategy();
    initialize();
}

OurStormGame::~OurStormGame()
{
    delete _lifeDrawStrat;
}

void OurStormGame::draw(QPainter &painter, QRect &rect) {
    auto x_ratio = (double)rect.width() / size().width();
    auto y_ratio = (double)rect.height() / size().height();
    painter.fillRect(rect, QColor(6,22,58));
    painter.setPen(QColor(70,212,255));
    for (auto starIndex = 0u; starIndex < _stars.size(); ++starIndex) {
        Star &star = _stars[starIndex];
        if (star.isActive()) {
            star.draw(painter, rect, x_ratio, y_ratio);


        }
    }
    for (auto bulletIndex = 0u; bulletIndex < _bullets.size(); ++bulletIndex) {
        Bullet &bullet = _bullets[bulletIndex];
        if (bullet.isActive()) {
            bullet.draw(painter, rect, x_ratio, y_ratio);
        }
    }

    if (_life > 0) {
        _spaceShip.draw(painter, rect, x_ratio, y_ratio);
    }

    //Draw the life
    int marginLife = 10;
    int lifeSize = 14;
    int leftLifeStart = size().width() - (lifeSize * 3) - (marginLife * 3);
    int topLife = rect.height() - (lifeSize) - (marginLife);
    for (auto i = 0; i < _life; ++i) {
        int leftLife = leftLifeStart + (lifeSize * i) + (marginLife  * i);
        QPoint pos = QPoint(leftLife, topLife);
        _lifeDrawStrat->draw(painter, rect, x_ratio, y_ratio, pos, lifeSize, 0);
    }

    //Draw the score
    QPoint position = QPoint(10 * x_ratio, 20 * y_ratio);
    QString text = QString("Score : %1").arg(_score);
    QFont font = QFont("Space Age");
    painter.setFont(font);
    painter.drawText(position,text);


    if (_life <= 0) {
        QPoint positionGameOver = QPoint(size().width()/2 - 25 * x_ratio, size().height()/2 * y_ratio);
        QString textGameOver = QString("Game Over");
        painter.drawText(positionGameOver,textGameOver);
    }
}

void OurStormGame::mousePressed( int x, int y) {
}

void OurStormGame::keyPressed( int key ) {
    switch(key) {
    case Qt::Key_Space:
        if (!_isShooting && _life > 0) {
            _isShooting = true;
            createNewBullet();
        }
        break;
    case Qt::Key_Up:
        if (_spaceShip.checkState(DrawableObject::ObjectState::ALIVE))
            _spaceShip.setAcceleration(_spaceShip.acceleration()+0.25);
        break;
    case Qt::Key_Down:
        if (_spaceShip.checkState(DrawableObject::ObjectState::ALIVE))
            _spaceShip.setAcceleration(_spaceShip.acceleration()-0.125);
        break;
    case Qt::Key_Left:
        _spaceShip.setRotation(_spaceShip.Rotation()-10);
        break;
    case Qt::Key_Right:
        _spaceShip.setRotation(_spaceShip.Rotation()+10);
        break;
    }
}

void OurStormGame::keyReleased( int key ) {
    switch(key) {
    case Qt::Key_Space:
        if (_isShooting) {
            _bulletTik = 0;
            _isShooting = false;
        }
        break;
    }
}

void OurStormGame::step() {
    removeUnActive();
    stepStar();
    stepBullet();

    if (_life > 0) {
        _spaceShip.setAcceleration(_spaceShip.acceleration()-0.125);
        _spaceShip.step(); // also if the spaceship is unactive you need to restart the spaceship it in the center
    }

    if (_isShooting) {
        ++_bulletTik;
        if (_bulletTik == _normalSpeedBuletIntervalTik) {
            createNewBullet();
            _bulletTik = 0;
        }
    }

}

void OurStormGame::stepStar()
{
    for (auto starIndex = 0u; starIndex < _stars.size(); ++starIndex) {
        Star &star = _stars[starIndex];
        if (star.checkState(DrawableObject::ObjectState::ALIVE)) { // IS ALIVE
            if (_spaceShip.checkState(DrawableObject::ObjectState::ALIVE)
                    && checkStarColision(star, _spaceShip)) {
                _spaceShip.kill();
                star.kill();
                --_life;
            } else {
                int hitByOne = checkStarColision(star, _bullets);
                if (hitByOne >= 0) {
                    Bullet &bullet = _bullets[hitByOne];
                    bullet.kill();
                    star.kill();
                    _score+=10;
                } else {
                    star.step();
                }
            }
        } else if (star.checkState(DrawableObject::ObjectState::BORN)) { // IS BORN
            int tik = _starsTikGrow[star];
            ++tik;
            if (tik == _normalSpeedGrowStarIntervalTik) {
                star.grow();
                star.setAcceleration(1);
                _starsTikGrow.erase(star);
            } else {
                _starsTikGrow[star] = tik;
            }
        } else if (star.checkState(DrawableObject::ObjectState::EXPLODING)) {
            star.step();
        }
    }
}

void OurStormGame::stepBullet()
{
    for (auto i = 0u; i < _bullets.size(); ++i) {
        Bullet &bullet = _bullets[i];
        if (!bullet.isActive())
            continue;
        bullet.step();
    }
}

void OurStormGame::initialize()
{
    _life = 3;
    _score = 0;
    srand(time(NULL));
    //empty list
    _bullets.clear();
    _stars.clear();
    _starsTikGrow.clear();

    // Start spaceShip
    startTheSpaceShip();

    // create new stars
    for (auto i = 0; i < 30; ++i) {
        QPointF dir = chooseRandomDirection();
        QPoint pos = chooseRandomPosition();
        int size = 24; // BIG
        if (i < 5) {
            size = 8; // SMALL
        } else if (i < 25) {
            size = 16; // MEDIUM
        }
        createNewStar(pos, dir, size);

    }
}

int OurStormGame::checkStarColision(Star &star, vector<Bullet> &bullets)
{
    for (auto i = 0u; i < bullets.size(); ++i) {
        Bullet &bullet = bullets[i];
        if (!bullet.isActive())
            continue;
        if (checkStarColision(star, bullet))
            return i;
    }
    return -1;
}

bool OurStormGame::checkStarColision(Star &star, DrawableObject &object)
{
    float starCenterX = star.position().x() + star.size() / 2;
    float starCenterY = star.position().y() + star.size() / 2;

    float objectCenterX = object.position().x() + object.size() / 2;
    float objectCenterY = object.position().y() + object.size() / 2;

    float hypotenuseMax = object.size() / 2 + star.size() / 2;

    float hypotenuse, a, b;
    a = fabs(starCenterX - objectCenterX);
    b = fabs(starCenterY - objectCenterY);
    hypotenuse = sqrt(a*a + b*b);
    if (hypotenuse <= hypotenuseMax) {
        return true;
    }
    return false;
}

void OurStormGame::removeUnActive()
{
    auto index = 0u;
    while(index < _stars.size())
    {
        Star &star = _stars[index];
        if (star.isActive()) {
            ++index;
        } else {
            _stars.erase(_stars.begin()+index);
        }
    }

    index = 0u;
    while(index < _bullets.size())
    {
        Bullet &bullet = _bullets[index];
        if (bullet.isActive()) {
            ++index;
        } else {
            _bullets.erase(_bullets.begin()+index);
        }
    }

    if (!_spaceShip.isActive()) {
        startTheSpaceShip();
    }
}

void OurStormGame::createNewBullet()
{
    Bullet newBullet = _spaceShip.createBullet();
    _bullets.push_back(newBullet);
}

QPointF OurStormGame::chooseRandomDirection()
{
    return QPointF((rand() % 5) - (rand() % 5), (rand() % 5) - (rand() % 5));
}

QPoint OurStormGame::chooseRandomPosition()
{
    return QPoint((rand() % size().width()), (rand() % size().height()));;
}

void OurStormGame::createNewStar(QPoint &pos, QPointF &dir, int size)
{
    Star newStar = Star(pos);
    newStar.setDirection(dir);
    newStar.setSize(size);
    _stars.push_back(newStar);
    _starsTikGrow[newStar] = 0;
}

void OurStormGame::startTheSpaceShip()
{
    _spaceShip.reborn();
    int spaceshipSize = _spaceShip.size();
    assert(spaceshipSize % 3 == 0);
    QSize windowSize = size();
    QPoint pos = QPoint(windowSize.width() / 2 - spaceshipSize / 2, windowSize.height() / 2 - spaceshipSize / 2);
    _spaceShip.setPosition(pos);
}
