#include "statistics.hh"

namespace Game {

Statistics::Statistics()
{
    buses_ = 0;
    customers_ = 0;
    points_ = 0;
    passengers_ = 0;


}

void Statistics::morePassengers(int num)
{

    passengers_ += num;
    return;
}

void Statistics::nysseRemoved()
{
    buses_ -= 1;
    std::cout <<  "There are" << buses_ << "buses in game." << std::endl;

}

void Statistics::newNysse()
{
    buses_ += 1;
    std::cout <<  "There are" << buses_ << "buses in game." << std::endl;

}

void Statistics::nysseLeft()
{
    return;
}

void Statistics::newCustomer()
{
    customers_ += 1;
    std::cout << "New customer has become hungry." << std::endl;

}

void Statistics::fedCustomer()
{
    customers_ -= 1;
    std::cout << "Customer has been fed." << std::endl;

}

void Statistics::addPoints(int points)
{
    points_ += points;
    std::cout << "Player has" << points_ << "points!" << std::endl;
}
int Statistics::getPoints()
{
    return points_;
}

void Statistics::setPointGoal(std::string difficulty)
{

    if(difficulty == "Easy"){
        maxpoints_ = 100;
    }else if(difficulty == "Medium"){
        maxpoints_ = 250;
    }else{
        maxpoints_ = 500;
    }
}

bool Statistics::isWon()
{
    if(points_ >= maxpoints_){
        hasWon_ = true;
    }else{
        hasWon_ = false;
    }
    return hasWon_;
}

void Statistics::reset()
{
    points_ = 0;
    hasWon_ = false;
}





}

