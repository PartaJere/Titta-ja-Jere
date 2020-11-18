#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QDebug>


const int PADDING = 10;

namespace Game {

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    startwindow_(new StartWindow(this))
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
    connect(startwindow_, &StartWindow::setPlayerName, this, &MainWindow::setPlayer);
    startwindow_->show();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, map, &QGraphicsScene::advance);
    timer->start(tick_);


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
    if(std::shared_ptr<Interface::IVehicle> ptr = std::dynamic_pointer_cast<Interface::IVehicle>(actor)){
        type = "bus";
    }
    else if(std::shared_ptr<Interface::IPassenger> ptr = std::dynamic_pointer_cast<Interface::IPassenger>(actor)){
        type = "passenger";
    }else if(std::shared_ptr<Game::player> ptr = std::dynamic_pointer_cast<Game::player>(actor)){
        type = "player";
    }

    Game::GraphicsControl* nActor = new Game::GraphicsControl(locX, locY, type);
    actors_.insert(actor, nActor);
    map->addItem(nActor);
    last_ = nActor;
}

void MainWindow::addStop(std::shared_ptr<Interface::IStop> stop, int locX, int locY)
{
    Game::GraphicsControl* nActor = new Game::GraphicsControl(locX, locY, "stop");
    stops_.insert(stop, nActor);
    map->addItem(nActor);
    last_ = nActor;
}

void MainWindow::updateCoords(int nX, int nY)
{
    last_->setCoord(nX, nY);
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

void MainWindow::on_startButton_clicked()
{
    qDebug() << "Start clicked";
    emit gameStarted();
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
