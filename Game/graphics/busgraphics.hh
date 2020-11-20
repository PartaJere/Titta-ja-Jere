#ifndef BUSGRAPHICS_H
#define BUSGRAPHICS_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QString>
#include <QPixmap>

#include "graphics/objectcontrol.hh"


namespace Game {

class BusGraphics : public ObjectControl
{
public:
    BusGraphics(int x, int y, std::string type=0);
    virtual ~BusGraphics();
    void setCoord(int x, int y);

private:

    int x_;
    int y_;
    std::string type_;
    QPixmap picture_;
};



}


#endif // BUSGRAPHICS_H
