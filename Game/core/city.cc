#include "city.hh"
#include <QTime>
#include <algorithm>

const QString RESTAURANT_DATA = ":/data/restaurantdata.json";

namespace Game
{

City::City() : Interface::ICity()
{


}

void City::setBackground(QImage &basicbackground, QImage &bigbackground)
{
    try {
        background_ = bigbackground;
    }

     catch (...) {
        Interface::InitError badpic("Setting the picture was unsuccesful or the picture was invalid.");
        throw badpic;
    }

    return;
}

void City::setClock(QTime clock)
{
    Q_ASSERT(clock.isValid() == true);
    clock_ = clock;

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
    if(std::shared_ptr<CourseSide::Nysse> ptr = std::dynamic_pointer_cast<CourseSide::Nysse>(newactor)){
        buses_.push_back(ptr);
    }
    else if(std::shared_ptr<CourseSide::Passenger> ptr = std::dynamic_pointer_cast<CourseSide::Passenger>(newactor)){
        passengers_.push_back(ptr);
    }
    else if(std::shared_ptr<Game::Player> ptr = std::dynamic_pointer_cast<Game::Player>(newactor)){
        players_.push_back(ptr);
    }
    else if(std::shared_ptr<Game::Customer> ptr = std::dynamic_pointer_cast<Game::Customer>(newactor)){
        customers_.push_back(ptr);
    }
    else{
        Interface::GameError err("Tried to add unknown actor!");
        throw err;
    }
}

void City::removeActor(std::shared_ptr<Interface::IActor> actor)
{
    actor->remove();
}

void City::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{
    Q_ASSERT(actor->isRemoved() == true);

    return;
}

bool City::findActor(std::shared_ptr<Interface::IActor> actor) const
{
    auto it = std::find(actors_.begin(),actors_.end(), actor);
    if(it == actors_.end()){
        return false;
    }
    else{
        return true;
    };
}


void City::actorMoved(std::shared_ptr<Interface::IActor> actor)
{
    Q_ASSERT(std::find(actors_.begin(), actors_.end(), actor) != actors_.end());

    movedActors_.push_back(actor);

    return;
}

std::vector<std::shared_ptr<Interface::IActor> > City::getNearbyActors(Interface::Location loc) const
{
    std::vector<std::shared_ptr<Interface::IActor>> nearBy;

    for( std::shared_ptr<Interface::IActor> actor: actors_){
        if(actor->giveLocation().isClose(loc) == true){

            nearBy.push_back(actor);
        }

    }
    return nearBy;
}

bool City::isGameOver() const
{
    return false;
}

void City::addRestaurants()
{
    QString filecontent;
    QFile file;
    file.setFileName(RESTAURANT_DATA);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    filecontent = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(filecontent.toUtf8());
    QJsonObject jsonObject = document.object();
    QJsonArray jsonArray = document.array();


    for (int i = 0; i < jsonArray.size(); i++) {
        QJsonObject o = jsonArray.at(i).toObject();
        int id = o.value("restaurantId").toString().toInt();
        int maxFood = o.value("maxFood").toString().toInt();
        int x = o.value("x").toString().toInt();
        int y = o.value("y").toString().toInt();

        loc_.setXY(x,y);
        std::shared_ptr<Game::Restaurant> NewRestaurant = std::make_shared<Game::Restaurant>(loc_);
        restaurants_.push_back(NewRestaurant);

    }
}

QImage City::getBackground()
{
    return background_;
}

std::vector<std::shared_ptr<Interface::IActor> > City::getActors()
{
    return actors_;
}

std::vector<std::shared_ptr<Interface::IActor> > City::getMovedActors()
{
    return movedActors_;
}

void City::clearMovedActors()
{
    movedActors_.clear();
}

std::vector<std::shared_ptr<Interface::IStop> > City::getStops()
{
    return stops_;
}

std::vector<std::shared_ptr<Restaurant> > City::getRestaurants()
{
    return restaurants_;
}

std::vector<std::shared_ptr<CourseSide::Passenger> > City::getPassengers()
{
    return passengers_;
}

std::vector<std::shared_ptr<CourseSide::Nysse> > City::getBuses()
{
    return buses_;
}

std::vector<std::shared_ptr<Customer> > City::getCustomers()
{
    return customers_;
}

std::vector<std::shared_ptr<Player> > City::getPlayers()
{
    return players_;
};

}
