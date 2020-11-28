#ifndef CITY_HH
#define CITY_HH

#include "interfaces/icity.hh"
#include "interfaces/istop.hh"
#include "graphics/simplemainwindow.hh"
#include "errors/initerror.hh"
#include "errors/gameerror.hh"
#include "graphics/simpleactoritem.hh"
#include "actors/restaurant.hh"
#include "actors/nysse.hh"
#include "actors/player.hh"
#include "actors/customer.hh"



#include <vector>
#include <QTime>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>
#include <QString>

namespace Game
{
class City : public Interface::ICity
{
public:
    City();


    /**
     * @brief setBackground sets the bitmap picture of the game area.
     * @param basicbackground  Normal sized picture used as the game area. Bottom left position of the picture in pixelcoordinates can be found out using the offset()-method.
     * @param bigbackground  Background of the game that is bigger than normal. Used only if doing Scrolling map-expansion. Bottom left position of the picture in pixelcoordinates can be found out using the offset()-method.
     * @pre City is in init state.
     * @post Picture for the game area is set. Exception guarantee: basic.
     * @exception InitError Setting the picture was unsuccesful or the picture was invalid.
     */
    void setBackground(QImage &basicbackground, QImage &bigbackground) override;

    /**
     * @brief setClock sets the time of the game clock.
     * @param clock Game clock time at the function call.
     * @pre `kello.isValid() == true`.
     * @post Time is set. Exception guarantee: nothrow.
     */
    void setClock(QTime clock) override;


    /**
     * @brief addStop adds a stop to the city.
     * @param stop pointer to a stop object.
     * @pre City is in init state.
     * @post Stop is added to the city. Exception guarantee: basic
     * @exception InitError Stops position is not valid.
     */
    void addStop(std::shared_ptr<Interface::IStop> stop) override;

    /**
     * @brief startGame shofts city from init state to the gamestate.
     * @pre City is in init state. setBackground() and setClock() have been called.
     * @post City is in gamestate. Exception guarantee: nothrow.
     */
    void startGame() override;

    /**
     * @brief addActor adds a new actor to the city.
     * @param newactor actor to be added to the city that fulfills ActorIF.
     * @pre -
     * @post Actor is added to the city. Exception guarantee: basic.
     * @exception GameError Actor is already in the city.
     */
    void addActor(std::shared_ptr<Interface::IActor> newactor) override;

    /**
     * @brief removeActor removes the actor from the city.
     * @param actor Actor to be removed.
     * @pre City is in gamestate.
     * @post Actor is removed from the city. Exception guarantee: strong.
     * @exception GameError Actor not found in the city
     */
    void removeActor(std::shared_ptr<Interface::IActor> actor) override;

    /**
     * @brief actorRemoved tells the city that actor is removed ingame.
     * @param actor Actor that is set removed ingame.
     * @pre City is in gamestate. Given actor is found in the city. Actor has `actor.isRemoved() == true`.
     * @post Exception guarantee: strong.
     */
    void actorRemoved(std::shared_ptr<Interface::IActor> actor) override;

    /**
     * @brief findActor checks if the given actor is in the city.
     * @param actor Actor that that is looked for in the city.
     * @pre -
     * @return Boolean that tells wether the actor is in the city.
     * @post Exception guarantee: nothrow.
     */
    bool findActor(std::shared_ptr<Interface::IActor> actor) const override;

    /**
     * @brief actorMoved is an operation that is used to tell wether certain actor has moved.
     * @param actor Actor that has moved.
     * @pre City is in gamestate. Given actor is found in the city.
     * @post Exception guarantee: basic.
     */
    void actorMoved(std::shared_ptr<Interface::IActor> actor) override;

    /**
     * @brief getNearbyActors returns actors that are close to given position.
     * @param loc Location for getting the actors close to it.
     * @pre City is in gamestate.
     * @return Vector containing actors close to the location, that pass `giveLocation().isClose(loc) == true`.
     * @post Exception guarantee: strong.
     */
    std::vector<std::shared_ptr<Interface::IActor>> getNearbyActors(Interface::Location loc) const override;

    /**
     * @brief isGameOver tells wether the game is overor not.
     * @pre City is in gamestate.
     * @return `true`, if game is over, else ´false´
     * @post Exception guarantee: nothrow.
     */
    bool isGameOver() const override;

    /**
     * @brief creates pointers to restaurants from restaurant data and adds them to restaurant vector
     * @pre City is in initstate
     */
    void addRestaurants();

    /**
     * @brief getBackground returns background
     * @return Image of background
     */
    QImage getBackground();

    /**
     * @brief getActors returns actors.
     * @return vector containing all existing actors.
     */
    std::vector<std::shared_ptr<Interface::IActor>> getActors();

    /**
     * @brief getMovedActors returns moved actors.
     * @return vector of actors that have been moved.
     */
    std::vector<std::shared_ptr<Interface::IActor>> getMovedActors();

    /**
     * @brief clearMovedActors empties the movedActors_ vector
     */
    void clearMovedActors();

    /**
     * @brief getNewActors
     * @return vector of recently added actors
     */
    std::vector<std::shared_ptr<Interface::IActor>> getNewActors();
    /**
     * @brief clearNewActors empties the newActors_ vector
     */
    void clearNewActors();

    /**
     * @brief getStops returns all stops.
     * @return vector containing stops.
     */
    std::vector<std::shared_ptr<Interface::IStop>> getStops();

    /**
     * @brief getRestaurants returns restaurants.
     * @return vector containing restaurants.
     */
    std::vector<std::shared_ptr<Game::Restaurant>> getRestaurants();

    /**
     * @brief getPassengers returns passengers.
     * @return vector containing passengers.
     */
    std::vector<std::shared_ptr<CourseSide::Passenger>> getPassengers();

    /**
     * @brief getBuses returns buses.
     * @return vector containing buses.
     */
    std::vector<std::shared_ptr<CourseSide::Nysse>> getBuses();

    /**
     * @brief getCustomers returns customers.
     * @return vector containing customers.
     */
    std::vector<std::shared_ptr<Game::Customer>> getCustomers();

    /**
     * @brief getPlayers returns players
     * @return vector containing players.
     */
    std::vector<std::shared_ptr<Game::Player>> getPlayers();

    /**
     * @brief resetCity puts city back in init state. Clears
     *  players and customers
     */
    void resetCity();
private:
    QImage background_;
    QTime clock_;

    std::vector<std::shared_ptr<Interface::IStop>> stops_;
    std::vector<std::shared_ptr<CourseSide::Nysse>> buses_;
    std::vector<std::shared_ptr<CourseSide::Passenger>> passengers_;
    std::vector<std::shared_ptr<Game::Restaurant>> restaurants_;
    std::vector<std::shared_ptr<Game::Customer>> customers_;
    std::vector<std::shared_ptr<Game::Player>> players_;
    std::vector<std::shared_ptr<Interface::IActor>> actors_;
    std::vector<std::shared_ptr<Interface::IActor>> movedActors_;
    std::vector<std::shared_ptr<Interface::IActor>> newActors_;

    Interface::Location loc_;



};
}

#endif // CITY_HH
