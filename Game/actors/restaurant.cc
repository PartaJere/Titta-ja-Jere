#include "restaurant.hh"

namespace Game {

Restaurant::Restaurant(Interface::Location location) :  location_(location),
                            removed_(false)

    {

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

}

