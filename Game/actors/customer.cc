#include "customer.hh"
#include <QDebug>
namespace Game {
    Customer::Customer() : location_(),
                            removed_(false)
    {
        int x = 100;
        int y = 200;
        location_.setXY(x, y);
        levelOfHunger_ = 1+rand()%20;
    }

    Interface::Location Customer::giveLocation() const
    {
        return location_;
    }

    void Customer::move(Interface::Location loc)
    {
        location_ = loc;
    }

    void Customer::remove()
    {
        removed_ = true;
    }

    bool Customer::isRemoved() const
    {
        return removed_;
    }

    void Customer::decreaseHunger(int amount){
        qDebug() << "Level of hunger: " << levelOfHunger_;
        levelOfHunger_ -= amount;
        if(levelOfHunger_ <= 0){
            remove();
        }
    }
}
