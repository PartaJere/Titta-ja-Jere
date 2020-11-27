#include "customergraphics.hh"

const QString CUSTOMER_FILE = ":/images/customer.png";

const int WIDTH = 30;
const int HEIGHT = 30;
namespace Game {
    CustomerGraphics::CustomerGraphics(int x, int y, std::string type) : x_(x), y_(y), type_(type)
    {
        setPos(mapToParent(x_,y_));
        setOffset(QPointF(-WIDTH/2, -HEIGHT/2));
        assert(picture_.load(CUSTOMER_FILE));
        picture_ = picture_.scaled(WIDTH, HEIGHT);
        setPixmap(picture_);
    }

    CustomerGraphics::~CustomerGraphics()
    {

    }
    void CustomerGraphics::setCoord(int x, int y)
    {
        setX( x );
        setY( y );
    }

}
