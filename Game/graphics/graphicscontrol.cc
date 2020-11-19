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
    setPos(mapToParent(x_, y_));
}

GraphicsControl::~GraphicsControl()
{

}

QRectF GraphicsControl::boundingRect() const
{
    if(type_ == "bus"){
        return QRectF(0, 0, 9, 15);
    }else{
        return QRect(0,0,10,10);
    }

}

void GraphicsControl::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QImage picture;
    QRectF bounds;

    if(type_ == "bus"){

        picture = QImage(BUS_FILE, "png");
        bounds = QRectF(0, 0, 9, 15);


    }
    if(type_ == "stop"){
        picture = QImage(BUSSTOP_FILE, "png");
        bounds = QRect(0,0,10,10);

    }
    if(type_ == "player"){
            //picture = QImage(PLAYER_FILE, "png");
            bounds = QRectF(0,0,30,30);
            painter->drawEllipse(10,4,10,4);
    }

    if(type_ == "passenger"){

        QColor color(100, 100, 100);
        QBrush brush(color);
        painter->setBrush(brush);
        painter->drawEllipse(3,3,3,3);

    }

    QBrush brush(picture);
    painter->drawImage(bounds, picture);



}

void GraphicsControl::setCoord(int x, int y)
{
    setX( x );
    setY( y );
}


}





