#include "passengergraphics.hh"
#include <QDebug>



namespace Game {

PassengerGraphics::PassengerGraphics(int x, int y, std::string type):x_(x), y_(y), type_(type)
{
    pix_ = new QPixmap(5,5);
    painter_ = new QPainter(pix_);
    painter_->setPen(*(new QColor(255,34,255,255)));
    painter_->drawRect(100,100,5,5);
    setPixmap(*pix_);
}

PassengerGraphics::~PassengerGraphics()
{

}

void PassengerGraphics::setCoord(int x, int y)
{
    setX( x );
    setY( y );

}


}
