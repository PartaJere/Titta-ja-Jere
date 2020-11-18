#ifndef GRAPHICSCONTROL_HH
#define GRAPHICSCONTROL_HH

#include "graphics/simpleactoritem.hh"
#include "city.hh"
#include "core/logic.hh"
#include "mainwindow.hh"



namespace Game {

class ActorItem : public CourseSide::SimpleActorItem

{

public:
    ActorItem(int x, int y, int type = 0);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option = 0, QWidget *widget = 0) override;



private:
    int x_;
    int y_;
    int type_;
};


}


#endif // GRAPHICSCONTROL_HH
