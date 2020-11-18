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

        Interface::Location giveLocation() const;
        void move(Interface::Location loc);
        void remove();
        bool isRemoved() const;
        int getSpeed();
        bool changeSpeed(int newSpeed);

    private:
        Interface::Location location_;
        bool removed_;
        int speed_;


    };
}


#endif // PLAYER_HH
