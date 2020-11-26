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
        gameStartedBool(false),
        time_(GAME_DURATION),
        player_(nullptr),
        statistics_(new Game::Statistics)

    {
        initGame();

        QObject::connect(&mainwindow_, &MainWindow::gameStarted,
                         this, &Engine::startGame);
        QObject::connect(&mainwindow_, &MainWindow::keyPressed,
                         this, &Engine::movePlayer);
        QObject::connect(this, &Engine::gameOver, &mainwindow_,
                         &MainWindow::gameEnded);
        QObject::connect(&timer_, &QTimer::timeout, this, &Engine::advance);

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

        logic_.finalizeGameStart();

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

        for( auto restaurant : city_->getRestaurants()){
            unsigned int x = restaurant->giveLocation().giveX();
            unsigned int y = restaurant->giveLocation().giveY();

            mainwindow_.addRestaurant(restaurant, x, y);

        }

        timer_.start(TICK);


    }

    bool Engine::isGameOver()
    {

        if( player_->isRemoved() ){
            qDebug() << "Game is over: player died";
            emit gameOver("Player died!");
            mainwindow_.deleteActor(player_);
            gameStartedBool = false;
            return true;
        }
        else if( time_ <= 0 ){
            qDebug() << "Game is over: time is over";
            emit gameOver("Time ran out!");
            mainwindow_.deleteActor(player_);
            gameStartedBool = false;
            return true;
        }

        else{
            return false;
        }
    }



    void Engine::startGame()
    {
        if(!gameStartedBool){
            //logic_.setTime(10, 00);
            player_ = std::make_shared<Player>(Player());
            city_->addActor(player_);
            Interface::Location loc = player_->giveLocation();
            mainwindow_.addActor(player_, loc.giveX(), loc.giveY());
            mainwindow_.moveView(player_->giveLocation());
            mainwindow_.updateTimeLeft(time_);
            mainwindow_.updateHpBar(player_->getHP());

            gameStartedBool = true;
        };

    }

    void Engine::advance()
    {
        //time_ -= 1/TICK;

        for( auto actor : city_->getMovedActors()){
            mainwindow_.moveActor(actor);
        };
        city_->clearMovedActors();

        for( auto actor : city_->getActors()){
            if( actor->isRemoved()){
                mainwindow_.deleteActor(actor);
            }
        }


        if(gameStartedBool){
            if( rand()%100 > 98 ){
                std::shared_ptr<Customer> newCustomer = std::make_shared<Customer>(Customer());
                city_->addActor(newCustomer);
                Interface::Location loc = newCustomer->giveLocation();
                mainwindow_.addActor(newCustomer, loc.giveX(), loc.giveY());
            }
            isGameOver();
            mainwindow_.moveView(player_->giveLocation());
            checkInteractions();
            mainwindow_.updateHpBar(player_->getHP());
            mainwindow_.updateTimeLeft(time_);
        };




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

    void Engine::checkInteractions()
    {
        Interface::Location loc = player_->giveLocation();
        for( auto bus : city_->getBuses()){
            if(loc.isClose(bus->giveLocation(), 15)){
                player_->decreaseHP(3);
            };
        };
        for( auto restaurant : city_->getRestaurants()){
            if(loc.isClose(restaurant->giveLocation(), 15)){
                restaurant->removeFood(1);
                player_->increaseFood(1);
            }
        };
        for( auto customer : city_->getCustomers()){
            if(loc.isClose(customer->giveLocation(), 15) && !customer->isRemoved()){
                if(player_->decreaseFood(1)){
                    customer->decreaseHunger(1);
                    if(customer->isRemoved()){
                        statistics_->addPoints(customer->getInitialLevelOfHunger());
                    }

                }
            }
        }

    }

    void Engine::restartGame()
    {

    }


}
