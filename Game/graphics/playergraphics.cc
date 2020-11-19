#include "playergraphics.hh"

#include <QDebug>

const QString PLAYER_FILE = ":/images/plate.png";

namespace Game {

PlayerGraphics::PlayerGraphics(int x, int y, std::string type):x_(x), y_(y), type_(type)
{
    setPos(mapToParent(x_,y_));
    assert(picture_.load(PLAYER_FILE));
    setPixmap(picture_);


}

PlayerGraphics::~PlayerGraphics()
{

}

void PlayerGraphics::setCoord(int x, int y)
{
    setX( x );
    setY( y );
}

}
