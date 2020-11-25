#ifndef CUSTOMER_HH
#define CUSTOMER_HH

#include <string>

#include "interfaces/iactor.hh"

namespace Game {
    class Customer : public Interface::IActor
    {
    public:
        Customer();

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

    private:
        Interface::Location location_;
        bool removed_;
    };
}


#endif // CUSTOMER_HH