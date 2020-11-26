#ifndef STATISTICS_H
#define STATISTICS_H

#include <iostream>
#include "interfaces/istatistics.hh"



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
    int buses_ = 0;
    int customers_ = 0;
    int points_ = 0;
    int passengers_ = 0;



};

#endif // STATISTICS_H
