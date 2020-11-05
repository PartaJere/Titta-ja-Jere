#ifndef GRAPHICSCONTROL_HH
#define GRAPHICSCONTROL_HH

#include "graphics/simpleactoritem.hh"
#include "city.hh"
#include "core/logic.hh"
#include "mainwindow.hh"



namespace Game {

class Graphicscontrol : public CourseSide::SimpleActorItem

{

public:
    Graphicscontrol(int x, int y, int type = 0);
    void checktype();
    void paintBus();
    void paintPassenger();
    void paintStop();


private:
    int x_;
    int y_;
    int type_;
};


}


#endif // GRAPHICSCONTROL_HH
