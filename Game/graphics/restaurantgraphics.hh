#ifndef RESTAURANTGRAPHICS_H
#define RESTAURANTGRAPHICS_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QString>
#include <QPixmap>
#include "graphics/graphicsobject.hh"

namespace Game {

/**
 * @brief The RestaurantGraphics class creates and controls the graphics of restaurants
 */
class RestaurantGraphics : public GraphicsObject
{
public:
    /**
     * @brief RestaurantGraphics constructs the graphics of a restaurant by loading the file as a pixmap and setting it
     * @param x is the wanted x-coordinate for busgraphics
     * @param y is the wanted y-coordinate for busgraphics
     * @param type tells which type of actor this is
     */
    RestaurantGraphics(int x, int y, std::string type=0);

    /**
     * @brief ~RestaurantGraphics default destructor
     */
    virtual ~RestaurantGraphics();

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

#endif // RESTAURANTGRAPHICS_H
