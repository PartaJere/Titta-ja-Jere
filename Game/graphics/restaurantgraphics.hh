#ifndef RESTAURANTGRAPHICS_H
#define RESTAURANTGRAPHICS_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QString>
#include <QPixmap>
#include "graphics/graphicsobject.hh"

namespace Game {

class RestaurantGraphics : public GraphicsObject
{
public:
    RestaurantGraphics(int x, int y, std::string type=0);
    virtual ~RestaurantGraphics();
    void setCoord(int x, int y);

private:

    int x_;
    int y_;
    std::string type_;
    QPixmap picture_;

};


}

#endif // RESTAURANTGRAPHICS_H
