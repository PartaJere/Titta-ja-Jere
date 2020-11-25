#include "engine.hh"
#include "actors/customer.hh"

const int A_KEY = 65;
const int S_KEY = 83;
const int D_KEY = 68;
const int W_KEY = 87;
const int MOVE_PER_PRESS = 5;

const int GAME_DURATION = 300; //seconds
const int TICK = 30; //updates per second



#include <QDebug>

namespace Game {

    const QString BUS_DATA = ":/offlinedata/offlinedata/final_bus_liteN.json";
    const QString STOP_DATA = ":/offlinedata/offlinedata/full_stations_kkj3.json";

    Engine::Engine() :
        logic_(new CourseSide::Logic),
        mainwindow_(new MainWindow),
        time_(GAME_DURATION),
        player_(new Game::Player),
        keyPressed_(0)

    {
        initGame();

        QObject::connect(&mainwindow_, &MainWindow::gameStarted,
                         this, &Engine::startGame);
        QObject::connect(&mainwindow_, &MainWindow::keyPressed,
                         this, &Engine::movePlayer);
        QObject::connect(this, &Engine::gameOver, &mainwindow_,
                         &MainWindow::gameEnded);

        mainwindow_.setTick(TICK);
    }



    void Engine::initGame()
    {
        std::shared_ptr<Interface::ICity> icityptr = Interface::createGame();
        logic_.takeCity(icityptr);
        logic_.fileConfig();

        std::shared_ptr<Game::City> cityptr = std::dynamic_pointer_cast<Game::City>(icityptr);
        city_ = cityptr;

        mainwindow_.show();
        QImage img = city_->getBackground();
        mainwindow_.setPicture(img);
        std::shared_ptr<Customer> customer = std::make_shared<Customer>(Customer());
        city_->addActor(customer);


    }

    bool Engine::isGameOver()
    {
        if( player_->isRemoved() ){
            qDebug() << "Game is over: player died";
            emit gameOver("Player died!");
            timer_.stop();
            return true;
        }
        else if( time_ <= 0 ){
            qDebug() << "Game is over: time is over";
            emit gameOver("Time ran out!");
            timer_.stop();
            return true;
        }

        else{
            return false;
        }
    }



    void Engine::startGame()
    {
        logic_.setTime(10, 00);
        logic_.finalizeGameStart();
        actors_ = city_->getActors();
        city_->addActor(player_);
        mainwindow_.moveView(player_->giveLocation());

        for( auto actor : city_->getActors()){
            unsigned int x = actor->giveLocation().giveX();
            unsigned int y = actor->giveLocation().giveY();

            mainwindow_.addActor(actor, x, y);
        };

        for( auto stop : city_->getStops()){
            unsigned int x = stop->getLocation().giveX();
            unsigned int y = stop->getLocation().giveY();

            mainwindow_.addStop(stop, x, y);
        };
        QObject::connect(&timer_, &QTimer::timeout, this, &Engine::advance);
        timer_.start(TICK);
        mainwindow_.updateTimeLeft(time_);
        mainwindow_.updateHpBar(player_->getHP());

    }

    void Engine::advance()
    {
        time_ -= 1/TICK;
        if( keyPressed_ ){
            movePlayer(keyPressed_);
        }
        for( auto actor : city_->getMovedActors()){
            mainwindow_.moveActor(actor);
        };
        city_->clearMovedActors();
        mainwindow_.moveView(player_->giveLocation());

        checkPlayerDmg();


        mainwindow_.updateHpBar(player_->getHP());
        isGameOver();
        mainwindow_.updateTimeLeft(time_);



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

    void Engine::checkPlayerDmg()
    {
        for( auto actor : city_->getActors()){
            if(player_ != actor){
                if(std::dynamic_pointer_cast<Interface::IVehicle>(actor)){
                    if(player_->giveLocation().isClose(actor->giveLocation())
                       && !actor->isRemoved()){
                        player_->decreaseHP(5);
                    };
                };
            };
        };
    }
}
