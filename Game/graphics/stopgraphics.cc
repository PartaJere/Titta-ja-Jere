#include "stopgraphics.hh"
#include <QDebug>

const QString BUSSTOP_FILE = ":/images/bussikyltti.png";
const int WIDTH = 12;
const int HEIGHT = 10;


namespace Game {

StopGraphics::StopGraphics(int x, int y, std::string type):x_(x), y_(y), type_(type)
{
    setPos(mapToParent(x_,y_));
    setOffset(QPointF(-WIDTH/2, -HEIGHT/2));
    assert(picture_.load(BUSSTOP_FILE));
    picture_ = picture_.scaled(WIDTH, HEIGHT);
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
