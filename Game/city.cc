#include "city.hh"
#include <QTime>

namespace Interface
{

Tampere::Tampere() : Interface::ICity()
{

}

void Tampere::setBackground(QImage &basicbackground, QImage &bigbackground)
{

    return;
}

void Tampere::setClock(QTime clock)
{
    return;
}

void Tampere::addStop(std::shared_ptr<IStop> stop)
{
    return;
}

void Tampere::startGame()
{
    return;
}

void Tampere::addActor(std::shared_ptr<IActor> newactor)
{
    return;
}

void Tampere::removeActor(std::shared_ptr<IActor> actor)
{
    return;
}

void Tampere::actorDestroyed(std::shared_ptr<IActor> actor)
{
    return;
}

bool Tampere::findActor(std::shared_ptr<IActor> actor) const
{
    return false;
}

void Tampere::actorMoved(std::shared_ptr<IActor> actor)
{
    return;
}

std::vector<std::shared_ptr<IActor> > Tampere::getNearbyActors(Location loc) const
{

}

bool Tampere::isGameOver() const
{
    return false;
};
}
