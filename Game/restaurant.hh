#ifndef RESTAURANT_HH
#define RESTAURANT_HH

#include "interfaces/iactor.hh"


namespace Game {

class Restaurant : Interface::IActor
{
public:
    Restaurant(Interface::Location location);
    Interface::Location giveLocation() const;
    void move(Interface::Location loc);
    void remove();
    bool isRemoved() const;

private:
    Interface::Location location_;
    bool removed_;
    bool hasFood_;

};


}



#endif // RESTAURANT_HH
