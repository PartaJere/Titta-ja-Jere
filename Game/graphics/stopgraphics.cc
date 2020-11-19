#include "stopgraphics.hh"
#include <QDebug>

const QString BUSSTOP_FILE = ":/images/bussikyltti.png";

namespace Game {

StopGraphics::StopGraphics(int x, int y, std::string type):x_(x), y_(y), type_(type)
{
    setPos(mapToParent(x_,y_));
    assert(picture_.load(BUSSTOP_FILE));
    setPixmap(picture_);


}

StopGraphics::~StopGraphics()
{

}

void StopGraphics::setCoord(int x, int y)
{
    setX( x );
    setY( y );
}

}
