#include "customer.hh"

namespace Game {
    Customer::Customer() : location_(),
                            removed_(false)
    {
        int x = 100;
        int y = 200;
        location_.setXY(x, y);
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

}
