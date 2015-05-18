#include "explodedrawablestrategy.h"
#include <QLine>

ExplodeDrawableStrategy::ExplodeDrawableStrategy()
{
}

void ExplodeDrawableStrategy::draw(QPainter &painter, QRect &rect, double xRatio, double yRatio, QPoint &pos, int size, int rotation)
{
    //DRAW HERE AN EXPLOSION
        int newPointX = pos.x()+size/2;
        int newPointY = pos.y();
        QPoint topCenterPoint = QPoint(newPointX*xRatio, newPointY*yRatio);
        newPointX = pos.x()+size;
        newPointY = pos.y();
        QPoint topRightPoint = QPoint(newPointX*xRatio, newPointY*yRatio);
        newPointX = pos.x()+size;
        newPointY = pos.y()+size/2;
        QPoint midRightPoint = QPoint(newPointX*xRatio, newPointY*yRatio);
        newPointX = pos.x()+size;
        newPointY = pos.y()+size;
        QPoint bottomRightPoint = QPoint(newPointX*xRatio, newPointY*yRatio);
        newPointX = pos.x()+size/2;
        newPointY = pos.y()+size;
        QPoint bottomCenterPoint = QPoint(newPointX*xRatio, newPointY*yRatio);
        newPointX = pos.x();
        newPointY = pos.y()+size;
        QPoint bottomLeftPoint = QPoint(newPointX*xRatio, newPointY*yRatio);
        newPointX = pos.x();
        newPointY = pos.y()+size/2;
        QPoint midLeftPoint = QPoint(newPointX*xRatio, newPointY*yRatio);
        newPointX = pos.x();
        newPointY = pos.y();
        QPoint topLeftPoint = QPoint(newPointX*xRatio, newPointY*yRatio);


        QLine line = QLine(topCenterPoint , bottomCenterPoint);
        painter.drawLine(line);
        line = QLine(midLeftPoint , midRightPoint);
        painter.drawLine(line);
        line = QLine(topLeftPoint , bottomRightPoint);
        painter.drawLine(line);
        line = QLine(bottomLeftPoint , topRightPoint);
        painter.drawLine(line);

}
