#include "busgraphics.hh"
#include <QDebug>



const QString BUS_FILE = ":/images/pipsabussi.png";
const int WIDTH = 15;
const int HEIGHT = 20;
namespace Game {

BusGraphics::BusGraphics(int x, int y, std::string type): x_(x), y_(y), type_(type)
{
    setPos(mapToParent(x_,y_));
    setOffset(QPointF(-WIDTH/2, -HEIGHT/2));
    assert(picture_.load(BUS_FILE));
    picture_ = picture_.scaled(WIDTH, HEIGHT);
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
