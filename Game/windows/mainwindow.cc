#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QDebug>


const int PADDING = 10;

namespace Game {

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    startwindow_(new StartWindow(this)),
    isGameStarted_(false)
{


    ui->setupUi(this);

    ui->gameView->setFixedSize(width_, height_);
    ui->centralwidget->setFixedSize(width_ + ui->startButton->width() + PADDING, height_ + PADDING);

    ui->startButton->move(width_ + PADDING , PADDING);

    map = new QGraphicsScene(this);
    ui->gameView->setScene(map);
    map->setSceneRect(0,0,width_,height_);

    resize(minimumSizeHint());
    //ui->gameView->fitInView(0,0, MAPWIDTH, MAPHEIGHT, Qt::KeepAspectRatio);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, map, &QGraphicsScene::advance);
    timer->start(tick_);

    connect(startwindow_, &StartWindow::setPlayerName, this, &MainWindow::setPlayer);
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

void MainWindow::addActor(std::shared_ptr<Interface::IActor> actor, int locX, int locY)
{
    std::string type;
    Game::ObjectControl* nActor;
    if(std::shared_ptr<Interface::IVehicle> ptr = std::dynamic_pointer_cast<Interface::IVehicle>(actor)){
        type = "bus";
        nActor = new Game::BusGraphics(locX, locY, type);
    }
    else if(std::shared_ptr<Interface::IPassenger> ptr = std::dynamic_pointer_cast<Interface::IPassenger>(actor)){
        type = "passenger";
        nActor = new Game::PassengerGraphics(locX, locY, type);
    }else if(std::shared_ptr<Game::Player> ptr = std::dynamic_pointer_cast<Game::Player>(actor)){
        type = "player";
        nActor = new Game::PlayerGraphics(locX, locY, type);
    }
    actors_.insert(actor, nActor);
    map->addItem(nActor);
    last_ = nActor;
}

void MainWindow::addStop(std::shared_ptr<Interface::IStop> stop, int locX, int locY)
{
    Game::ObjectControl* nActor = new Game::StopGraphics(locX, locY, "stop");
    stops_.insert(stop, nActor);
    map->addItem(nActor);
    last_ = nActor;
}


void MainWindow::moveActor(std::shared_ptr<Interface::IActor> actor)
{
    if(actors_.contains(actor)){
        actors_[actor]->setCoord(actor->giveLocation().giveX(), 500-actor->giveLocation().giveY());
    };
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
void MainWindow::gameEnded(std::string message)
{
    Game::GameEndedWindow w(this, message);
    w.exec();
}

void MainWindow::on_startButton_clicked()
{
    qDebug() << "Start clicked";
    if(!isGameStarted_){
        startwindow_->exec();
        emit gameStarted();
        isGameStarted_ = true;
    };
}

void MainWindow::keyPressEvent( QKeyEvent* event )
{
    emit keyPressed(event->key());
    qDebug() << "Pressed: " << event->key();
}
void MainWindow::keyReleaseEvent( QKeyEvent* event )
{
    emit keyReleased(event->key());
    qDebug() << "Released: " << event->key();
}

void MainWindow::setPlayer(std::string name)
{
    name_ = name;

}
}
