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
    /**
     * @brief Statistics constructs statistics for the game and sets all initial values to 0
     */
    Statistics();

    /**
     * @brief morePassengers adds passengers to statistics
     * @pre num > 0 and passengers >= 0
     * @param num tells how many passenger have been added to game
     * @post passengers += num
     */
    void morePassengers(int num) override;

    /**
     * @brief nysseRemoved removes a bus from statistics and informs player
     * that a Nysse has been removed
     * @pre buses_ > 1
     * @post buses_ -= 1 OR buses_ == 0
     */
    void nysseRemoved() override;

    /**
     * @brief newNysse adds a bus to statistics and informs player about it
     * @pre buses_ > 0
     * @post buses_ += 1
     */
    void newNysse() override;

    /**
     * @brief nysseLeft removes a bus from statistics and informs player that
     * a Nysse has left the game.
     * @pre buses_ >= 0
     * @post buses_ -= 1 OR buses_ == 0
     */
    void nysseLeft() override;

    /**
     * @brief newCustomer adds a customer to stats and informs player about it
     * @pre customers_ >= 0
     * @post customers_ += 1
     */
    void newCustomer();

    /**
     * @brief fedCustomer removes a customer from statistics, since they have
     * been given enough food
     * @pre customers_ >= 0
     * @post customers_ -= 1 OR customers_ == 0
     */
    void fedCustomer();

    /**
     * @brief addPoints adds given amount of points to stats and informs player about it
     * @pre points_ >= 0
     * @param points is the amount of points that will be added
     * @post points_ += points
     */
    void addPoints(int points);

    /**
     * @brief getPoints returns the amount of points collected thus far
     * @pre points_ >= 0
     * @return points_
     */
    int getPoints();

    /**
     * @brief setPointGoal sets the points goal player needs to reach to win the game
     * @param difficulty is used to assign the point goal
     */
    void setPointGoal(std::string difficulty);

    /**
     * @brief isWon returns the information of whether the point goal has been reached or not
     * @return boolean isWon_
     */
    bool isWon();

    /**
     * @brief reset resets the statistics
     * @post statistics have been reset back to what they are when the game starts
     */
    void reset();

    int getBuses();
    int getCustomers();
    int getMaxPoints();
    int getPassengers();

private:
    int buses_;
    int customers_;
    int points_;
    int maxpoints_;
    int passengers_;
    bool isWon_;



};


}


#endif // STATISTICS_H
