#ifndef RESTAURANT_HH
#define RESTAURANT_HH

#include <QTimer>
#include <QDebug>


#include "interfaces/iactor.hh"
#include "errors/gameerror.hh"


namespace Game {

class Restaurant : public QObject, Interface::IActor
{
    Q_OBJECT
public:


    Restaurant(Interface::Location location, int maxFood);

    /**
     * @brief giveLocation returns the location of the actor.
     * @pre -
     * @return Actors location.
     * @post Exception guarantee: strong.
     */
    Interface::Location giveLocation() const;

    /**
     * @brief move-method moves the actor to given location.
     * @param loc Actors new location.
     * @pre -
     * @post Actors location is sij. Excaption guarantee: strong.
     * @exception GameError Location is not possible.
     */
    void move(Interface::Location loc);

    /**
     * @brief remove marks the actor as removed.
     * @pre Actor is not removed already.
     * @post Actor is removed, after this isRemoved() returns `true`. Exception guarantee: basic.
     */
    void remove();

    /**
     * @brief isRemoved tells if the actor is removed ingame.
     * @pre -
     * @return `true`, if actor is removed ingame, otherwise `false`.
     * @post Exception guarantee: nothrow.
     */
    bool isRemoved() const;

    /**
     * @brief setMaxFood sets maxFood_ as given parameter
     * @pre maxFood >= 0 and maxFood_ >= 0
     * @param maxFood is the amount of food restaurant can carry at a time
     * @post Restaurants maximum food in now maxFood
     */
    void setMaxFood(int maxFood);

    /**
     * @brief setId sets id of restaurant
     * @pre -
     * @param id is the id of restaurant
     * @post Restaurants id_ is id.
     */
    void setId(int id);

    /**
     * @brief getMaxFood returns the max food of restaurant
     * @return maxFood_
     */
    int getMaxFood();

    /**
     * @brief getFoodReady returns the amount of food that is readily available in restaurant
     * @return foodReady_
     */
    int getFoodReady();

    /**
     * @brief removeFood removes given amount of food from restaurant
     * @pre amount >= 0
     * @param amount is how many foods will we removed
     * @post foodReady -= amount OR foodReady = 0
     */
    void removeFood(int amount);

    /**
     * @brief reset resets the amount of food that is ready in a restaurant
     */
    void reset();

public slots:

    /**
     * @brief addFood adds a food to restaurant
     */
    void addFood();

private:
    Interface::Location location_;
    bool removed_;
    bool hasFood_;
    int maxFood_;
    int foodReady_;
    int id_;
    QTimer timer_;




};


}



#endif // RESTAURANT_HH
