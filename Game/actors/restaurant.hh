#ifndef RESTAURANT_HH
#define RESTAURANT_HH

#include <QTimer>
#include <QDebug>


#include "interfaces/iactor.hh"


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
     * @exception GameError - actor wasn't given a location.
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

    void setMaxFood(int maxFood);

    void setId(int id);

    int getMaxFood();

    int getFoodReady();

public slots:
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
