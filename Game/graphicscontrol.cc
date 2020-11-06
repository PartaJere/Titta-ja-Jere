#include "graphicscontrol.hh"
#include <QImage>
#include <memory>

const QString BUS_FILE = ":/images/images/pipsapussi.png";




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
    QRectF bounds = boundingRect();

    if(type_ == "bus"){
        QImage busPicture = QImage(BUS_FILE, "png");
        QBrush brush(busPicture);
        painter->setBrush(busPicture);
        painter->drawRect(bounds);


    }
    else{

        QColor color(100, 100, 100);
        QBrush brush(color);
        painter->setBrush(brush);
        painter->drawEllipse(bounds);

    }
    /*if(type_ == "passenger"){
        QColor color;
    }

    if(type_ == "stop"){
        QColor color;
    }*/


}

void GraphicsControl::setCoord(int x, int y)
{
    setX( x );
    setY( y );
}


}





