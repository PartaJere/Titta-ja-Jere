#include "restaurant.hh"

namespace Game {

Restaurant::Restaurant(Interface::Location location, int maxFood) :  location_(location),
                            removed_(false), maxFood_(maxFood)

    {
        connect(&timer_, &QTimer::timeout, this, &Restaurant::addFood);
        timer_.start(1000);
        foodReady_ = maxFood_/2;
    }

    Interface::Location Restaurant::giveLocation() const
    {
        return location_;
    }

    void Restaurant::move(Interface::Location loc)
    {
        location_ = loc;
    }

    void Restaurant::remove()
    {
        removed_ = true;
    }

    bool Restaurant::isRemoved() const
    {
        return removed_;
    }

    void Restaurant::setMaxFood(int maxFood)
    {
        maxFood_ = maxFood;
    }

    void Restaurant::setId(int id)
    {
        id_ = id;
    }

    int Restaurant::getMaxFood()
    {
        return maxFood_;
    }

    int Restaurant::getFoodReady()
    {
        return foodReady_;
    }

    void Restaurant::addFood()
    {
        if(foodReady_ < maxFood_){
            foodReady_ += 1;
            qDebug() << "Restaurant has " << foodReady_ << "food ready.";
        }
    }

}

