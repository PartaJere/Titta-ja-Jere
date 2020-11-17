#include "engine.hh"
<<<<<<< HEAD


const int A_KEY = 65;
const int S_KEY = 83;
const int D_KEY = 68;
const int W_KEY = 87;
const int MOVE_PER_PRESS = 25;

=======
>>>>>>> 231cb46ec6361cc7b4df8616e083663ec74aac81
#include <QDebug>

namespace Game {

    const QString BUS_DATA = ":/offlinedata/offlinedata/final_bus_liteN.json";
    const QString STOP_DATA = ":/offlinedata/offlinedata/full_stations_kkj3.json";

    Engine::Engine() :
        logic_(new CourseSide::Logic),
        mainwindow_(new MainWindow),
        player_(new Game::player)
    {
        initGame();

        QObject::connect(&mainwindow_, &MainWindow::gameStarted,
                         this, &Engine::startGame);
        QObject::connect(&mainwindow_, &MainWindow::keyPressed,
                         this, &Engine::movePlayer);
    }



    void Engine::initGame()
    {
        std::shared_ptr<Interface::ICity> icityptr = Interface::createGame();
        logic_.takeCity(icityptr);
        logic_.fileConfig();

        std::shared_ptr<Game::City> cityptr = std::dynamic_pointer_cast<Game::City>(icityptr);
        city_ = cityptr;

        mainwindow_.show();
        QImage img = city_->getBasicBackground();
        mainwindow_.setPicture(img);

        mainwindow_.addActor(player_, player_->giveLocation().giveX(), player_->giveLocation().giveY());
        city_->addActor(player_);
    }

    void Engine::setType(std::shared_ptr<Interface::IActor> actor)
    {
        if(std::shared_ptr<CourseSide::Passenger> ptr = std::dynamic_pointer_cast<CourseSide::Passenger>(actor)){
            type_ = 0;

        }
        else{
            type_ = 1;

        }

    }

    void Engine::startGame()
    {
        logic_.setTime(10, 00);
        logic_.finalizeGameStart();
        actors_ = city_->getActors();
<<<<<<< HEAD




        for( auto actor : city_->getActors()){
            unsigned int x = actor->giveLocation().giveX();
            unsigned int y = actor->giveLocation().giveY();

            mainwindow_.addActor(actor, x, 500-y);
        };

        for( auto stop : city_->getStops()){
            unsigned int x = stop->getLocation().giveX();
            unsigned int y = stop->getLocation().giveY();

            mainwindow_.addStop(stop, x,500-y);
        };
        QObject::connect(&timer_, &QTimer::timeout, this, &Engine::advance);
        timer_.start(100);

    }

    void Engine::advance()
    {
<<<<<<< HEAD

        for( auto actor : city_->getMovedActors()){
            mainwindow_.moveActor(actor);
        };
        city_->clearMovedActors();



    }

    void Engine::movePlayer(int key)
    {
        int x = player_->giveLocation().giveX();
        int y = player_->giveLocation().giveY();
        if(key == A_KEY){
             x -= MOVE_PER_PRESS;
        }
        if(key == D_KEY){
            x += MOVE_PER_PRESS;
        }
        if(key == S_KEY){
            y -= MOVE_PER_PRESS;
        }
        if(key == W_KEY){
            y += MOVE_PER_PRESS;
        }
        Interface::Location loc = Interface::Location();
        loc.setXY(x,y);
        player_->move(loc);
        city_->actorMoved(player_);
    };
}
