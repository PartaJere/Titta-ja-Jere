#ifndef STATISTICS_H
#define STATISTICS_H

#include "interfaces/istatistics.hh"


class Statistics : Interface::IStatistics
{
public:
    Statistics();
    void morePassengers(int num) override;
    void nysseRemoved() override;
    void newNysse() override;
    void nysseLeft() override;



};

#endif // STATISTICS_H
