#include "playergraphics.hh"
#include <QDebug>

const QString PLAYER_FILE_LEFT = ":/images/autekmopoleft.png";
const QString PLAYER_FILE_RIGHT = ":/images/autekmoporight.png";
const float WIDTH = 35;
const float HEIGHT = 35;

namespace Game {

PlayerGraphics::PlayerGraphics(int x, int y, std::string type):x_(x), y_(y), type_(type)
{
    setPos(mapToParent(x_,y_));
    setOffset(QPointF(-WIDTH/2, -HEIGHT/2));
    assert(pictureLeft_.load(PLAYER_FILE_LEFT));
    assert(pictureRight_.load(PLAYER_FILE_RIGHT));
    pictureRight_ = pictureRight_.scaled(WIDTH, HEIGHT);

    pictureLeft_ = pictureLeft_.scaled(WIDTH, HEIGHT);

    setPixmap(pictureRight_);

}

PlayerGraphics::~PlayerGraphics()
{

}

void PlayerGraphics::setCoord(int x, int y)
{
    if( x_ - x > 0){
        setPixmap(pictureLeft_);
    }
    else if( x - x_ > 0){
        setPixmap(pictureRight_);
    }
    setX( x );
    setY( y );
    x_ = x;
    y_ = y;
}

}
