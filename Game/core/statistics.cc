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


}

