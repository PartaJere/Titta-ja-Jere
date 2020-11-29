#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QDebug>


const int PADDING = 10;
const int X_COMPENSATION = 355;
const int Y_COMPENSATION = 547;

namespace Game {

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    startwindow_(new StartWindow(this)),
    width_(1095),
    height_(592),
    centreOfMap_(Interface::Location()),
    isGameStarted_(false)
{
    centreOfMap_.setXY(width_/2, height_/2);
    ui->setupUi(this);

    ui->gameView->setFixedSize(width_, height_);
    ui->centralwidget->setFixedSize(width_ + ui->startButton->width()
                                    + PADDING, height_ + PADDING);

    ui->startButton->move(width_ + PADDING , PADDING);

    map = new QGraphicsScene(this);
    ui->gameView->setScene(map);
    ui->gameView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->gameView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->gameView->scale(1.2,1.2);
    resize(minimumSizeHint());
    //ui->gameView->fitInView(0,0, MAPWIDTH, MAPHEIGHT, Qt::KeepAspectRatio);

    map->setSceneRect(0,0,width_,height_);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, map, &QGraphicsScene::advance);
    timer->start(tick_);

    connect(startwindow_, &StartWindow::setPlayerName,
            this, &MainWindow::setPlayer);
    connect(startwindow_, &StartWindow::setDifficulty,
            this, &MainWindow::setGoal);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setSize(int w, int h)
{
    width_ = w;
    height_ = h;
}

void MainWindow::setTick(int t)
{
    tick_ = t;
}

void MainWindow::addActor(std::shared_ptr<Interface::IActor> actor)
{
    Interface::Location loc = actor->giveLocation();
    loc.setXY(loc.giveX() + X_COMPENSATION, Y_COMPENSATION - loc.giveY());

    if(loc.isClose(centreOfMap_, width_/1.5)){
        int locX = loc.giveX();
        int locY = loc.giveY();
        std::string type;
        Game::GraphicsObject* nActor;
        if(std::shared_ptr<Interface::IVehicle> ptr
                = std::dynamic_pointer_cast<Interface::IVehicle>(actor)){
            type = "bus";
            nActor = new Game::BusGraphics(locX, locY, type);
        }
        else if(std::shared_ptr<Interface::IPassenger> ptr
                = std::dynamic_pointer_cast<Interface::IPassenger>(actor)){
            type = "passenger";
            nActor = new Game::PassengerGraphics(locX, locY, type);
        }
        else if(std::shared_ptr<Game::Player> ptr
                = std::dynamic_pointer_cast<Game::Player>(actor)){
            type = "player";
            nActor = new Game::PlayerGraphics(locX, locY, type);
        }
        else{
            type = "customer";
            nActor = new Game::CustomerGraphics(locX, locY, type);
        }
        actors_.insert(actor, nActor);
        map->addItem(nActor);
    }
}

void MainWindow::addStop(std::shared_ptr<Interface::IStop> stop)
{
    Interface::Location loc = stop->getLocation();
    int locX = loc.giveX() + X_COMPENSATION;
    int locY = Y_COMPENSATION - loc.giveY();
    Game::GraphicsObject* nActor = new Game::StopGraphics(locX, locY, "stop");
    stops_.insert(stop, nActor);
    map->addItem(nActor);
}

void MainWindow::addRestaurant(std::shared_ptr<Game::Restaurant> restaurant)
{
    Interface::Location loc = restaurant->giveLocation();
    int locX = loc.giveX() + X_COMPENSATION;
    int locY = Y_COMPENSATION - loc.giveY();
    Game::GraphicsObject* nRestaurant
            = new Game::RestaurantGraphics(locX, locY, "restaurant");
    restaurants_.insert(restaurant, nRestaurant);
    map->addItem(nRestaurant);

    QGraphicsTextItem* nLabel = new QGraphicsTextItem();
    nLabel->setPlainText(QString::number(restaurant->getFoodReady()));
    nLabel->setX(locX + nRestaurant->offset().x() + 5);
    nLabel->setY(locY + nRestaurant->offset().y() - 15);
    restaurantLabels_.insert(restaurant, nLabel);
    map->addItem(nLabel);
}


void MainWindow::moveActor(std::shared_ptr<Interface::IActor> actor)
{
    Interface::Location loc = actor->giveLocation();
    loc.setXY(loc.giveX() + X_COMPENSATION, Y_COMPENSATION - loc.giveY());
    if(loc.isClose(centreOfMap_, width_/1.5)){
        if(actors_.contains(actor)){
            actors_[actor]->setCoord(loc.giveX(), loc.giveY());
        }
        else{
            addActor(actor);
        }
    }
    else{
        if(actors_.contains(actor)){
            deleteActor(actor);
        }
    }
}

void MainWindow::setPicture(QImage &img)
{
    map->setBackgroundBrush(img);
}

void MainWindow::updateTimeLeft(int timeLeft)
{
    ui->timeLeft->display(timeLeft);
}

void MainWindow::updateHpBar(int hp)
{
    ui->hpBar->setValue(hp);
}


void MainWindow::updateRestaurant(std::shared_ptr<Restaurant> restaurant)
{
    QGraphicsTextItem* label = restaurantLabels_[restaurant];
    label->setPlainText(QString::number(restaurant->getFoodReady()));
}

void MainWindow::updateTrunk(int amount)
{
    ui->trunk->display(amount);
}

void MainWindow::updatePoints(std::shared_ptr<Game::Statistics> statistics)
{
    statistics_ = statistics;
    ui->points->display(statistics_->getPoints());

}

void MainWindow::moveView(Interface::Location loc)
{
    ui->gameView->centerOn(loc.giveX() + X_COMPENSATION,
                           Y_COMPENSATION - loc.giveY());
}

void MainWindow::deleteActor(std::shared_ptr<Interface::IActor> actor)
{
     delete actors_[actor];
     actors_.remove(actor);
}

void MainWindow::takeStatistics(std::shared_ptr<Statistics> statistics)
{
    statistics_ = statistics;
}

QVector<int> MainWindow::getKeysPressed()
{
    return keysPressed_;
}

void MainWindow::gameEnded(std::string message)
{
    Game::GameEndedWindow w(this, message);
    keysPressed_.clear();
    w.exec();
    isGameStarted_ = false;
}

void MainWindow::on_startButton_clicked()
{
    if(!isGameStarted_){
        qDebug() << "Start clicked";

        startwindow_->exec();

        emit gameStarted();
        isGameStarted_ = true;
    }
}

void MainWindow::keyPressEvent( QKeyEvent* event )
{
    if(!event->isAutoRepeat()){
        keysPressed_.push_back(event->key());
    }
}

void MainWindow::keyReleaseEvent( QKeyEvent* event )
{
    if(!event->isAutoRepeat()){
        int i = 0;
        int eventKey = event->key();
        for(int key : keysPressed_){
            if(key == eventKey){
                keysPressed_.remove(i);
            }
            ++i;
        }
    }
}

void MainWindow::setPlayer(std::string name)
{
    name_ = name;
}

void MainWindow::setGoal(std::string difficulty)
{
    statistics_->setPointGoal(difficulty);
}
}
