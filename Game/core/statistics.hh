#ifndef STATISTICS_H
#define STATISTICS_H

#include <iostream>
#include <QDebug>
#include <QObject>
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
    int getPoints();
    void setPointGoal(std::string difficulty);
    bool isWon();
    void reset();

private:
    int buses_;
    int customers_;
    int points_;
    int maxpoints_;
    int passengers_;
    bool hasWon_;



};


}


#endif // STATISTICS_H
