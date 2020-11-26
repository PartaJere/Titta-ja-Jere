#include "player.hh"

#include <QDebug>

int DEFAULT_SPEED = 25;
namespace Game {
    Player::Player() : location_(),
                       removed_(false),
                       speed_(DEFAULT_SPEED),
                       hitpoints_(100),
                       food_(0)

    {
        location_.setXY(100, 100);
        maxfood_ = 50;
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

    void Player::decreaseHP(int toDec)
    {
        hitpoints_ -= toDec;
        qDebug() << "hp: " << hitpoints_;
        if (hitpoints_ <= 0){
            remove();
        }
    }

    int Player::getHP()
    {
        return hitpoints_;
    }

    void Player::increaseFood(int amount)
    {
        if(food_ < maxfood_){
            food_ += amount;
            qDebug() << "Player has food: " << food_;
        }


    }

    bool Player::decreaseFood(int amount)
    {
        if(food_ >= amount){
            food_ -= amount;
            qDebug() << "Player has food: " << food_;
            return true;
        }
        else{
            qDebug() << "No food in the trunk";
            return false;
        }

    }

    int Player::getFood()
    {
        return food_;
    }

    int Player::getmaxFood()
    {
        return maxfood_;
    }

}
