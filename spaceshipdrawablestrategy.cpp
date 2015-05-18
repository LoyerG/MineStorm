#include "spaceshipdrawablestrategy.h"
#include <QLine>
#include "assert.h"

SpaceShipDrawableStrategy::SpaceShipDrawableStrategy()
{
}

void SpaceShipDrawableStrategy::draw(QPainter &painter, QRect &rect, double xRatio, double yRatio, QPoint &pos, int size, int rotation)
{
    assert(size % 3 == 0);
    QPoint spaceShipCenter = QPoint(pos.x() + size / 2, pos.y() + size / 2);
    float radianRotation = rotation * (3.14159265358979323846 / 180);
    //DRAW HERE THE SpaceShip
    int newPointX = pos.x() + (size/2);
    int newPointY = pos.y();
    QPoint topPoint = QPoint(newPointX*xRatio, newPointY*yRatio);
    rotatePoint(topPoint, spaceShipCenter, radianRotation);
    newPointX = pos.x();
    newPointY = pos.y() + size;
    QPoint bottomLeftPoint = QPoint(newPointX*xRatio, newPointY*yRatio);
    rotatePoint(bottomLeftPoint, spaceShipCenter, radianRotation);
    newPointX = pos.x() + size;
    newPointY = pos.y() + size;
    QPoint bottomRightPoint = QPoint(newPointX*xRatio, newPointY*yRatio);
    rotatePoint(bottomRightPoint, spaceShipCenter, radianRotation);
    newPointX = pos.x() + (size/2);
    newPointY = pos.y() + (size * 2/3);
    QPoint middlePoint = QPoint(newPointX*xRatio, newPointY*yRatio);
    rotatePoint(middlePoint, spaceShipCenter, radianRotation);

    QLine line = QLine(topPoint, bottomLeftPoint);
    painter.drawLine(line);
    line = QLine(bottomLeftPoint, middlePoint);
    painter.drawLine(line);
    line = QLine(middlePoint, topPoint);
    painter.drawLine(line);
    line = QLine(topPoint, bottomRightPoint);
    painter.drawLine(line);
    line = QLine(bottomRightPoint, middlePoint);
    painter.drawLine(line);
}

void SpaceShipDrawableStrategy::rotatePoint(QPoint &point, QPoint &axis, float radianRotation)
{
    float si = sin(radianRotation);
    float co = cos(radianRotation);
    int newY, newX;
    newX = ((co*(point.x() - axis.x())) - (si*(point.y()-axis.y())))+axis.x();
    newY = ((si*(point.x() - axis.x())) + (co*(point.y()-axis.y())))+axis.y();
    point.setX(newX);
    point.setY(newY);
}
