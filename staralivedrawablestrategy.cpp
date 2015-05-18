#include "staralivedrawablestrategy.h"
#include <QLine>
#include "assert.h"

StarAliveDrawableStrategy::StarAliveDrawableStrategy()
{
}

void StarAliveDrawableStrategy::draw(QPainter &painter, QRect &rect, double xRatio, double yRatio, QPoint &pos, int size, int rotation)
{
    assert(size % 4 == 0);
    //Definition des points de l'étoile
    int newPointX = pos.x();
    int newPointY = pos.y();
    QPoint topLeftPoint = QPoint(newPointX*xRatio, newPointY*yRatio);

    newPointX = pos.x()+size/2;
    newPointY = pos.y()+size/4;
    QPoint topMidPoint = QPoint(newPointX*xRatio, newPointY*yRatio);

    newPointX = pos.x()+size;
    newPointY = pos.y();
    QPoint topRightPoint = QPoint(newPointX*xRatio, newPointY*yRatio);

    newPointX = pos.x()+size*3/4;
    newPointY = pos.y()+size/2;
    QPoint midRightPoint = QPoint(newPointX*xRatio, newPointY*yRatio);

    newPointX = pos.x()+size;
    newPointY = pos.y()+size;
    QPoint bottomRightPoint = QPoint(newPointX*xRatio, newPointY*yRatio);

    newPointX = pos.x() + size/2;
    newPointY = pos.y() + size * 3/4;
    QPoint bottomMidPoint = QPoint(newPointX*xRatio, newPointY*yRatio);

    newPointX = pos.x();
    newPointY = pos.y()+size;
    QPoint bottomLeftPoint = QPoint(newPointX*xRatio, newPointY*yRatio);

    newPointX = pos.x()+size/4;
    newPointY = pos.y()+size/2;
    QPoint midLeftPoint = QPoint(newPointX*xRatio, newPointY*yRatio);


    //Dessin de l'étoile
    QLine line = QLine(topLeftPoint , topMidPoint);
    painter.drawLine(line);

    line = QLine(topMidPoint , topRightPoint);
    painter.drawLine(line);

    line = QLine(topRightPoint , midRightPoint);
    painter.drawLine(line);

    line = QLine(midRightPoint , bottomRightPoint);
    painter.drawLine(line);

    line = QLine(bottomRightPoint , bottomMidPoint);
    painter.drawLine(line);

    line = QLine(bottomMidPoint , bottomLeftPoint);
    painter.drawLine(line);

    line = QLine(bottomLeftPoint , midLeftPoint);
    painter.drawLine(line);

    line = QLine(midLeftPoint , topLeftPoint);
    painter.drawLine(line);


}
