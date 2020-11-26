#ifndef STATISTICS_H
#define STATISTICS_H

#include <iostream>
#include "interfaces/istatistics.hh"


namespace Game {

class Statistics : Interface::IStatistics
{
public:
    Statistics();
    void morePassengers(int num) override;
    void nysseRemoved() override;
    void newNysse() override;
    void nysseLeft() override;
    void newCustomer();
    void fedCustomer();
    void addPoints(int points);

private:
    int buses_;
    int customers_;
    int points_;
    int passengers_;



};


}


#endif // STATISTICS_H
