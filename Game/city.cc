#include "city.hh"
#include <QTime>
#include "main.cc"

namespace Game
{

City::City() : Interface::ICity()
{

}

void City::setBackground(QImage &basicbackground, QImage &bigbackground)
{
    try {
        basicbackground_ = basicbackground;
        bigbackground_ = bigbackground;
    }

     catch (...) {
        Interface::InitError badpic("Setting the picture was unsuccesful or the picture was invalid.");
        throw badpic;
    }

    return;
}

void City::setClock(QTime clock)
{
    return;
}

void City::addStop(std::shared_ptr<Interface::IStop> stop)
{
    stops_.push_back(stop);
}

void City::startGame()
{
    return;
}

void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    actors_.push_back(newactor);
}

void City::removeActor(std::shared_ptr<Interface::IActor> actor)
{
    return;
}

void City::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{
    return;
}

bool City::findActor(std::shared_ptr<Interface::IActor> actor) const
{
    return false;
}

void City::actorMoved(std::shared_ptr<Interface::IActor> actor)
{
    return;
}

std::vector<std::shared_ptr<Interface::IActor> > City::getNearbyActors(Interface::Location loc) const
{
    std::vector<std::shared_ptr<Interface::IActor>> nearBy;
    return nearBy;
}

bool City::isGameOver() const
{
    return false;
}

QImage City::getBasicBackground()
{
    return basicbackground_;
};

}
