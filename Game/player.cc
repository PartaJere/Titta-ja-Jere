#include "player.hh"

namespace Game {
    player::player() : location_(),
                       removed_(false)

    {
        location_.setXY(250,250);
    }

    Interface::Location player::giveLocation() const
    {
        return location_;
    }

    void player::move(Interface::Location loc)
    {
        location_ = loc;
    }

    void player::remove()
    {
        removed_ = true;
    }

    bool player::isRemoved() const
    {
        return removed_;
    }

}
