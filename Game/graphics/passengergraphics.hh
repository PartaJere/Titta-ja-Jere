#ifndef PASSENGERGRAPHICS_H
#define PASSENGERGRAPHICS_H


#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QString>
#include <QPixmap>
#include <QPainter>

#include "graphics/graphicsobject.hh"

namespace Game {

/**
 * @brief The PassengerGraphics class creates and controls the graphics of passengers
 */
class PassengerGraphics : public GraphicsObject
{
public:
    /**
     * @brief PassengerGraphics constructs the graphics of a passenger
     * @param x is the wanted x-coordinate for passengergraphics
     * @param y is the wanted y-coordinate for passengergraphics
     * @param type
     */
    PassengerGraphics(int x, int y, std::string type=0);

    /**
     * @brief ~PassengerGraphics default destructor
     */
    virtual ~PassengerGraphics();

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
    QPixmap *pix_;
    QPainter *painter_;
};

}


#endif // PASSENGERGRAPHICS_H
