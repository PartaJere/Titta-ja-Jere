#include "restaurantgraphics.hh"
#include <QImage>
#include <memory>
#include <QDebug>


const QString RESTAURANT_FILE = ":/images/restaurant.png";
const int WIDTH = 30;
const int HEIGHT = 30;
namespace Game {

RestaurantGraphics::RestaurantGraphics(int x, int y, std::string type): x_(x), y_(y), type_(type)
{
    setPos(mapToParent(x_,y_));
    setOffset(QPointF(-WIDTH/2, -HEIGHT/2));
    assert(picture_.load(RESTAURANT_FILE));
    picture_ = picture_.scaled(WIDTH, HEIGHT);
    setPixmap(picture_);

}

RestaurantGraphics::~RestaurantGraphics()
{

}

void RestaurantGraphics::setCoord(int x, int y)
{
    setX( x );
    setY( y );

}


}
