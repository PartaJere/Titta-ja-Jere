#ifndef PASSENGERGRAPHICS_H
#define PASSENGERGRAPHICS_H


#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QString>
#include <QPixmap>
#include <QPainter>

#include "graphics/graphicsobject.hh"

namespace Game {

class PassengerGraphics : public GraphicsObject
{
public:
    PassengerGraphics(int x, int y, std::string type=0);
    virtual ~PassengerGraphics();
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
