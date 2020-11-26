#include "customer.hh"
#include <QDebug>
namespace Game {
    Customer::Customer() : location_(),
                            removed_(false)
    {
        int x = 100 + rand()%500;
        int y = 200 + rand()%500;
        location_.setXY(x, y);
        levelOfHunger_ = 1+rand()%20;
        initialLevelOfHunger_ = levelOfHunger_;
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
        levelOfHunger_ -= amount;
        qDebug() << "Level of hunger: " << levelOfHunger_;
        if(levelOfHunger_ <= 0){
            remove();


        }
    }

    int Customer::getInitialLevelOfHunger()
    {
        return initialLevelOfHunger_;
    }


}
