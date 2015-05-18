#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H
#include "drawablestrategy.h"
#include <QSize>
#include <QPoint>
class QPainter;
class QRect;

using namespace std;
/**
 * @brief La classe DrawableObject est une classe abstraite
 * Elle permet la gestion de tous les objets affiché à l'écran
 */
class DrawableObject
{
public:
    enum ObjectState {BORN, ALIVE, EXPLODING, DEAD};
    DrawableObject(const QPoint &pos);
    DrawableObject();
    ~DrawableObject();

    /**
     * @brief draw appelée pour afficher l'objet
     * @param painter context d'affichage voir [la documentation Qt](http://doc.qt.io/qt-5/qpainter.html)
     * @param rect taille de la zone dans laquelle peindre le jeu
     * @param xRatio ratio de l'écran en x
     * @param yRatio ratio de l'écran en y
     */
    void draw(QPainter &painter, QRect &rect, double xRatio, double yRatio);

    /**
     * @brief step fait avancer l'objet d'une itération
     */
    void step();

    /**
     * @brief isActive retourne true si l'objet est activé
     * @return
     */
    bool isActive() const;

    /**
     * @brief setIsActive définie si l'objet est actif ou non
     * @param active
     */
    void setIsActive(bool active);

    /**
     * @brief position retourne la position de l'objet
     * @return
     */
    const QPoint &position() const;

    /**
     * @brief position retourne la direction de l'objet
     * @return
     */
    const QPointF &direction() const;

    /**
     * @brief setPosition définie la possition de l'objet
     * @param pos
     */
    void setPosition(QPoint &pos);

    /**
     * @brief setDirection définie la direction de l'objet
     * @param dir
     */
    void setDirection(QPointF &dir);

    /**
     * @brief acceleration retourne l'accélération de l'objet
     * @return
     */
    double acceleration() const;

    /**
     * @brief setAcceleration définie l'acceleration de l'objet
     * @param acc
     */
    void setAcceleration(double acc);

    /**
     * @brief size retourne la taille de l'objet
     * @return
     */
    int size() const;

    /**
     * @brief setSize définie la taille de l'objet
     * @param newSize
     */
    void setSize(int newSize);

    /**
     * @brief checkState retourne true si l'objet est à l'état passé
     * @param state enumération des états possible
     * @return
     */
    bool checkState(ObjectState state) const;
    /**
     * @brief tue l'objet pour le détruire ou lancé une éxplosion.
     * Doit être implémenté dans les classes enfants
     */
    virtual void kill() = 0;
    bool operator<(const DrawableObject& obj) const // for map insert
    {
        const QPoint pos = position();
        const QPoint objPos = obj.position();
        const QPointF dir = direction();
        const QPointF objdir = obj.direction();
        int posCal = pos.x() + pos.y();
        int objPosCal = objPos.x() + objPos.y();
        double dirCal = dir.x() + dir.y();
        double objDirCal = objdir.x() + objdir.y();
        return (_size != obj.size() && _size < obj.size());
    }

protected:
    /**
     * @brief startExploding lance l'éxplosion de l'objet
     */
    void startExploding();

    /**
     * @brief endExploding arrete l'éxplosion de l'objet et le désactive
     */
    void endExploding();

    QPoint _position;
    QPointF _direction;
    double _acceleration;
    int _size;
    ObjectState _state;
    DrawableStrategy *_drawableStrategy;
    int _startingExplodingSize;

private:
    /**
     * @brief growExplosion fait grandir l'explosion de l'objet
     */
    void growExplosion();

    bool _isActive;
    int _endingExplodingSize;
    int _normalSpeedExplodeIntervalTik;
    int _currentExplodingTik;
};

#endif // DRAWABLEOBJECT_H
