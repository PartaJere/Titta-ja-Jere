#include "playergraphics.hh"
#include <QDebug>

const QString PLAYER_FILE = ":/images/autekmopo.png";
const int WIDTH = 30;
const int HEIGHT = 30;

namespace Game {

PlayerGraphics::PlayerGraphics(int x, int y, std::string type):x_(x), y_(y), type_(type)
{
    setPos(mapToParent(x_,y_));
    assert(picture_.load(PLAYER_FILE));
    picture_ = picture_.scaled(WIDTH, HEIGHT);
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
