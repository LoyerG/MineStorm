#ifndef DRAWABLESTRATEGY_H
#define DRAWABLESTRATEGY_H
#include <QSize>
#include <QPoint>
#include <QPainter>
class QRect;

/**
 * @brief La classe DrawableStrategy est une classe abstraite
 * Elle permet la gestion du dessin des objets en jeu
 */
class DrawableStrategy
{
public:
    DrawableStrategy();

    /**
     * @brief draw appelée pour afficher l'objet
     * @param painter context d'affichage voir [la documentation Qt](http://doc.qt.io/qt-5/qpainter.html)
     * @param rect taille de la zone dans laquelle peindre le jeu
     * @param xRatio ratio de l'écran en x
     * @param yRatio ratio de l'écran en y
     * @param pos position à l'écran du dessin
     * @param size taille du dessin
     * @param rotation rotation de l'objet pour les dessins qui on besoin de la rotation
     */
    virtual void draw(QPainter &painter, QRect &rect, double xRatio, double yRatio
                      , QPoint &pos, int size, int rotation = 0) = 0;
};

#endif // DrawableStrategy_H
