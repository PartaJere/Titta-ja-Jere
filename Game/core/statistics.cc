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
    Q_ASSERT(passengers_ >= 0);
    Q_ASSERT(num > 0);
    passengers_ += num;
    return;
}

void Statistics::nysseRemoved()
{
    Q_ASSERT(buses_ > 0);
    if(buses_ > 0){
        buses_ -= 1;
    }

    std::cout <<  "There are" << buses_ << " Nysses in game." << std::endl;

}

void Statistics::newNysse()
{
    Q_ASSERT(buses_ > 0);
    buses_ += 1;
    std::cout <<  "There are" << buses_ << " buses in game." << std::endl;

}

void Statistics::nysseLeft()
{
    Q_ASSERT(buses_ > 0);

    if(buses_ > 0){
        buses_ -= 1;
    }
    std::cout << "Nysse has left the game. There are " << buses_ << " Nysses in game." << std::endl;
    return;
}

void Statistics::newCustomer()
{
    Q_ASSERT(customers_ >= 0);
    customers_ += 1;
    std::cout << "New customer has become hungry." << std::endl;

}

void Statistics::fedCustomer()
{
    Q_ASSERT(customers_ > 0);
    if(customers_ > 0){
        customers_ -= 1;
        std::cout << "Customer has been fed." << std::endl;
    }

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
        isWon_= true;
    }else{
        isWon_ = false;
    }
    return isWon_;
}

void Statistics::reset()
{
    points_ = 0;
    isWon_ = false;
    passengers_ = 0;
    buses_ = 0;
    customers_ = 0;
}

int Statistics::getBuses()
{
    return buses_;
}

int Statistics::getCustomers()
{
    return customers_;
}

int Statistics::getMaxPoints()
{
    return maxpoints_;
}

int Statistics::getPassengers()
{
    return passengers_;
}
void Statistics::lessPassenger(int num)
{
    Q_ASSERT(num >= 0);
    if(passengers_ >= num){
        passengers_-= num;
    }


}





}

