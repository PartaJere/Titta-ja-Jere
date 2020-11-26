#ifndef BUSGRAPHICS_H
#define BUSGRAPHICS_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QString>
#include <QPixmap>

#include "graphics/graphicsobject.hh"


namespace Game {

/**
 * @brief The BusGraphics class creates and controls the graphics of buses
 */
class BusGraphics : public GraphicsObject
{
public:
    /**
     * @brief BusGraphics constructs the graphics of a bus by loading the file as a pixmap and setting it
     * @param x is the wanted x-coordinate for busgraphics
     * @param y is the wanted y-coordinate for busgraphics
     * @param type tells which type of actor this is
     */
    BusGraphics(int x, int y, std::string type=0);
    /**
     * @brief ~BusGraphics default destructor
     */
    virtual ~BusGraphics();

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


#endif // BUSGRAPHICS_H
