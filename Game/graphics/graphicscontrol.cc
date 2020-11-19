#include "graphicscontrol.hh"
#include <QImage>
#include <memory>
#include <QDebug>

const QString BUS_FILE = ":/images/pipsabussi.png";
const QString BUSSTOP_FILE = ":/images/bussikyltti.png";
const QString PLAYER_FILE = ":/images/plate.png";




namespace Game {

GraphicsControl::GraphicsControl(int x, int y, std::string type):x_(x), y_(y), type_(type)
{
    setPos(mapToParent(x_,y_));
    assert(picture_.load(BUS_FILE));
    setPixmap(picture_);
}

GraphicsControl::~GraphicsControl()
{

}


void GraphicsControl::setCoord(int x, int y)
{
    setX( x );
    setY( y );
}


}





