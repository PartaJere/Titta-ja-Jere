#ifndef BUSSTOPGRAPHICS_H
#define BUSSTOPGRAPHICS_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QString>
#include <QPixmap>

#include "graphics/objectcontrol.hh"

namespace Game {

class StopGraphics : public ObjectControl
{
public:
    StopGraphics(int x, int y, std::string type=0);
    virtual ~StopGraphics();
    void setCoord(int x, int y);

private:
    int x_;
    int y_;
    std::string type_;
    QPixmap picture_;
};

}


#endif // BUSSTOPGRAPHICS_H
