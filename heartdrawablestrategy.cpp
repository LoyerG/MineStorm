#include "heartdrawablestrategy.h"
#include <QPainter>
#include "assert.h"

HeartDrawableStrategy::HeartDrawableStrategy()
{

}

void HeartDrawableStrategy::draw(QPainter &painter, QRect &rect, double xRatio, double yRatio, QPoint &pos, int size, int rotation)
{
    assert(size % 2 == 0);
    //Definit les points du coeur
    //La taille du coeur doit être un multiple de 4
    int newPointX = pos.x();
    int newPointY = pos.y()+size/4;
    QPoint leftPoint = QPoint(newPointX*xRatio, newPointY*yRatio);

    newPointX = pos.x()+size/2;
    newPointY = pos.y() + size;
    QPoint bottomCenterPoint = QPoint(newPointX*xRatio, newPointY*yRatio);

    newPointX = pos.x() + size;
    newPointY = pos.y() + size/4;
    QPoint rightPoint = QPoint(newPointX*xRatio, newPointY*yRatio);

    newPointX = pos.x() + size/4;
    newPointY = pos.y();
    QPoint topLeftPoint = QPoint(newPointX*xRatio, newPointY*yRatio);

    newPointX = pos.x() + (size * 3/4);
    newPointY = pos.y();
    QPoint topRightPoint = QPoint(newPointX*xRatio, newPointY*yRatio);

    newPointX = pos.x() + size/2;
    newPointY = pos.y() + size/4;
    QPoint centerPoint = QPoint(newPointX*xRatio, newPointY*yRatio);



    //Dessine le coeur
    QPen lastPen = painter.pen();
    painter.setPen(Qt::red); //Definit la couleur du coeur
    QLine line = QLine(leftPoint, bottomCenterPoint);
    painter.drawLine(line);

    line = QLine(bottomCenterPoint, rightPoint);
    painter.drawLine(line);

    line = QLine(rightPoint, topRightPoint);
    painter.drawLine(line);

    line = QLine(topRightPoint, centerPoint);
    painter.drawLine(line);

    line = QLine(centerPoint, topLeftPoint);
    painter.drawLine(line);

    line = QLine(topLeftPoint, leftPoint);
    painter.drawLine(line);

    painter.setPen(lastPen);

}

