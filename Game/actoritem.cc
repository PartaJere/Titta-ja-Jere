#include "actoritem.hh"


namespace Game {

ActorItem::ActorItem(int x, int y, int type):
CourseSide::SimpleActorItem(x,y,type)
{
}

void ActorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF bounds = boundingRect();

    if(type_ == 0){
        QColor color(200, 200, 200);
        QBrush brush(color);
        painter->setBrush(brush);
        painter->drawEllipse(bounds);

    }
    else if(type_ == 1){
        QColor color(0, 0, 0);
        QBrush brush(color);
        painter->setBrush(brush);
        painter->drawEllipse(bounds);
    }
    if(type_ == 2){
       QColor color(100, 100, 100);
       QBrush brush(color);
       painter->setBrush(brush);
       painter->drawEllipse(bounds);
    }



}




}

