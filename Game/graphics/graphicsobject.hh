#ifndef GRAPHICSCONTROL_HH
#define GRAPHICSCONTROL_HH

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QString>
#include <QPixmap>

namespace Game {

/**
 * @brief The GraphicsObject is a baseclass for all graphicsitems in Game
 */

class GraphicsObject : public QGraphicsPixmapItem
{
public:

    /**
      * @brief Default constructor
      * @post Graphics have been added to given actor
      */
    GraphicsObject() = default;

    /**
      * @brief Default destructor
      */
    virtual ~GraphicsObject() = default;

    /**
     * @brief setCoord changes the coordinates of the graphicsitem
     * @param x is the x-coordinate that graphics' coord will be changed to
     * @param y is the y-coordinate that graphics' coord will be changed to
     */
    virtual void setCoord(int x, int y) = 0;

};

}



#endif // GRAPHICSCONTROL_HH

