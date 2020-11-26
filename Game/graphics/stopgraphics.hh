#ifndef BUSSTOPGRAPHICS_H
#define BUSSTOPGRAPHICS_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QString>
#include <QPixmap>

#include "graphics/graphicsobject.hh"

namespace Game {

/**
 * @brief The StopGraphics class creates and controls the graphics of stops
 */
class StopGraphics : public GraphicsObject
{
public:
    /**
     * @brief StopGraphics constructs the graphics of a stop by loading the file as a pixmap and setting it
     * @param x is the wanted x-coordinate for stopgraphics
     * @param y is the wanted y-coordinate for stopgraphics
     * @param type tells which type of actor this is
     */
    StopGraphics(int x, int y, std::string type=0);

    /**
     * @brief ~StopGraphics default destructor
     */
    virtual ~StopGraphics();

    /**
     * @brief setCoord changes the coordinates of the graphicsitem
     * @param x is the x-coordinate that graphics' coord will be changed to
     * @param y is the y-coordinate that graphics' coord will be changed to
     */
    void setCoord(int x, int y);

private:
    int x_;
    int y_;
    std::string type_;
    QPixmap picture_;
};

}


#endif // BUSSTOPGRAPHICS_H
