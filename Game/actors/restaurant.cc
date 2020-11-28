#include "restaurant.hh"

namespace Game {

Restaurant::Restaurant(Interface::Location location, int maxFood) :  location_(location),
                            removed_(false), maxFood_(maxFood)

    {
        connect(&timer_, &QTimer::timeout, this, &Restaurant::addFood);
        timer_.start(2000);
        foodReady_ = maxFood_/2;
    }

    Interface::Location Restaurant::giveLocation() const
    {

            return location_;

    }

    void Restaurant::move(Interface::Location loc)
    {
        try {
        location_ = loc;

        }  catch (...) {

        Interface::GameError badloc("Location is not possible.");
        badloc.what();
        throw badloc;

    }
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
        Q_ASSERT(maxFood >= 0);
        Q_ASSERT(maxFood_ >= 0);
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

    void Restaurant::removeFood(int amount)
    {
        Q_ASSERT(amount >= 0);
        if(foodReady_ > amount){
            foodReady_ -= amount;
        }else{
            foodReady_ = 0;
        }

    }

    void Restaurant::reset()
    {
        foodReady_ = maxFood_/2;
    }



    void Restaurant::addFood()
    {
        if(foodReady_ < maxFood_){
            foodReady_ += 1;
        }
    }


}

