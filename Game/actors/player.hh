#ifndef PLAYER_HH
#define PLAYER_HH

#include <QObject>
#include "interfaces/iactor.hh"

#include "core/location.hh"

namespace Game {
    class Player : public Interface::IActor
    {
    public:
        Player();

        //Actor interface
        std::string getName() const;

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
        /**
         * @brief getSpeed tells the speed of the actor
         * @pre -
         * @return int, pixels per move
         * @post Exception guarantee: nothrow.
         */
        int getSpeed();
        /**
         * @brief changeSpeed is used to change the speed (pixels per move) of the player
         * @pre -
         * @post speed is between 1-50 pix/move
         * @return 'true' if speed is acceptable, 'false' if not
         * @post Exception guarantee: basic
         */
        bool changeSpeed(int newSpeed);
        /**
         * @brief Decreases hitpoints for the amount given. If HP reaches 0, removes player
         * @pre toDec > 0
         * @post hp > 0 or player removed
         * @return -
         * @post Exception guarantee: basic
         */
        void decreaseHP(int toDec);

        int getHP();

        void increaseFood(int amount);

        bool decreaseFood(int amount);

    private:
        Interface::Location location_;
        bool removed_;
        int speed_;
        int hitpoints_;
        int food_;


    };
}


#endif // PLAYER_HH
