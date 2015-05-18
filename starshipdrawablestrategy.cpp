#include "starshipdrawablestrategy.h"
#include <QLine>
#include "assert.h"

StarShipDrawableStrategy::StarShipDrawableStrategy()
{
}

void StarShipDrawableStrategy::draw(QPainter &painter, QRect &rect, double xRatio, double yRatio, QPoint &pos, int size, int rotation)
{
    assert(size % 4 == 0);
    // DRAW THE STARSHIP OF DEATH !
    int newPointX = pos.x();
    int newPointY = pos.y();
    QPoint topLeftPoint = QPoint(newPointX * xRatio, newPointY * yRatio);
    newPointX = pos.x() + (size * 1/4);
    newPointY = pos.y() + (size * 1/4);
    QPoint leftMiddlePoint = QPoint(newPointX * xRatio, newPointY * yRatio);
    newPointX = pos.x() + (size * 3/4);
    newPointY = pos.y() + (size * 1/4);
    QPoint rightMiddlePoint = QPoint(newPointX * xRatio, newPointY * yRatio);
    newPointX = pos.x() + size;
    newPointY = pos.y();
    QPoint topRightPoint = QPoint(newPointX * xRatio, newPointY * yRatio);
    newPointX = pos.x() + size/2;
    newPointY = pos.y() + (size * 3/4);
    QPoint middlePoint = QPoint(newPointX * xRatio, newPointY * yRatio);
    newPointX = pos.x() + (size * 1/4);
    newPointY = pos.y() + size;
    QPoint bottomLeftPoint = QPoint(newPointX * xRatio, newPointY * yRatio);
    newPointX = pos.x() + (size * 3/4);
    newPointY = pos.y() + size;
    QPoint bottomRightPoint = QPoint(newPointX * xRatio, newPointY * yRatio);

    QLine line = QLine(topLeftPoint, leftMiddlePoint);
    painter.drawLine(line);
    line = QLine(leftMiddlePoint, rightMiddlePoint);
    painter.drawLine(line);
    line = QLine(rightMiddlePoint, topRightPoint);
    painter.drawLine(line);
    line = QLine(topRightPoint, bottomRightPoint);
    painter.drawLine(line);
    line = QLine(bottomRightPoint, middlePoint);
    painter.drawLine(line);
    line = QLine(middlePoint, bottomLeftPoint);
    painter.drawLine(line);
    line = QLine(bottomLeftPoint, topLeftPoint);
    painter.drawLine(line);

}
