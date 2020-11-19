#include "busgraphics.hh"
#include <QImage>
#include <memory>
#include <QDebug>



const QString BUS_FILE = ":/images/pipsabussi.png";

namespace Game {

BusGraphics::BusGraphics(int x, int y, std::string type): x_(x), y_(y), type_(type)
{
    setPos(mapToParent(x_,y_));
    assert(picture_.load(BUS_FILE));
    setPixmap(picture_);

}

BusGraphics::~BusGraphics()
{

}

void BusGraphics::setCoord(int x, int y)
{

    setX( x );
    setY( y );

}


}
