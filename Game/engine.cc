#include "engine.hh"

#include <QDebug>
namespace Game {

    const QString BUS_DATA = ":/offlinedata/offlinedata/final_bus_liteN.json";
    const QString STOP_DATA = ":/offlinedata/offlinedata/full_stations_kkj3.json";

    Engine::Engine() :
        logic_(new CourseSide::Logic),
        mainwindow_(new MainWindow)
    {
        initGame();

        QObject::connect(&mainwindow_, &MainWindow::gameStarted,
                         this, &Engine::startGame);
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

    }

    void Engine::startGame()
    {
        //logic_.setTime(10, 00);
        logic_.finalizeGameStart();
        actors_ = city_->getActors();
        for(auto actor : actors_){
            int x = actor->giveLocation().giveX();
            int y = actor->giveLocation().giveY();

            mainwindow_.addActor(x,y);
        }

        stops_ = city_->getStops();
        for(auto stop : stops_){
            int x_stop = stop->getLocation().giveX();
            int y_stop = stop->getLocation().giveY();
            qDebug() << "x: " << x_stop << "y: " << y_stop;
            mainwindow_.addActor(x_stop,y_stop);
        }





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

        for( auto actor : city_->getMovedActors()){
            mainwindow_.moveActor(actor);
        };
        city_->clearMovedActors();
    };
}
