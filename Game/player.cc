#include "player.hh"

int DEFAULT_SPEED = 25;
namespace Game {
    Player::Player() : location_(),
                       removed_(false),
                       speed_(DEFAULT_SPEED)

    {
        location_.setXY(250,250);
    }

    Interface::Location Player::giveLocation() const
    {
        return location_;
    }

    void Player::move(Interface::Location loc)
    {
        location_ = loc;
    }

    void Player::remove()
    {
        removed_ = true;
    }

    bool Player::isRemoved() const
    {
        return removed_;
    }

    int Player::getSpeed()
    {
        return speed_;
    }

    bool Player::changeSpeed(int newSpeed)
    {
        if(5 < newSpeed && newSpeed < 50){
            speed_ = newSpeed;
            return true;
        }
        else{
            return false;
        }
    }


}
