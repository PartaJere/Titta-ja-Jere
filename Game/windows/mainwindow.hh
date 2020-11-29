#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include "interfaces/iactor.hh"
#include "interfaces/iactor.hh"
#include "interfaces/istop.hh"
#include "actors/player.hh"
#include "actors/restaurant.hh"
#include "windows/startwindow.hh"
#include "windows/gameendedwindow.hh"
#include "graphics/graphicsobject.hh"
#include "graphics/busgraphics.hh"
#include "graphics/stopgraphics.hh"
#include "graphics/playergraphics.hh"
#include "graphics/passengergraphics.hh"
#include "core/statistics.hh"

#include "graphics/customergraphics.hh"

#include "graphics/restaurantgraphics.hh"


#include <iostream>
#include <string>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTimer>
#include <iostream>
#include <memory>
#include <QVector>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QMap>
#include <map>

namespace Ui {
class MainWindow;
}

namespace Game {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

    void setSize(int w, int h);
    void setTick(int t);

    /**
     * @brief addActor adds new actor to the scene. It will recognize the type
     * of the actor (player, customer, passenger, bus)
     * @param actor, shared_ptr<Interface::IActor>
     */
    virtual void addActor(std::shared_ptr<Interface::IActor> actor);
    /**
     * @brief addStop
     * @param stop, shared_ptr<Interface::IStop>
     */
    void addStop(std::shared_ptr<Interface::IStop> stop);
    void addRestaurant(std::shared_ptr<Game::Restaurant> restaurant);

    void moveActor(std::shared_ptr<Interface::IActor> actor);
    void setPicture(QImage &img);
    void updateTimeLeft(int timeLeft);
    void updateHpBar(int hp);
    void updateRestaurant(std::shared_ptr<Game::Restaurant> restaurant);
    void updateTrunk(int amount);
    void updatePoints(std::shared_ptr<Game::Statistics> statistics);

    void moveView(Interface::Location loc);
    void deleteActor(std::shared_ptr<Interface::IActor> actor);

    void takeStatistics(std::shared_ptr<Game::Statistics> statistics);

    QVector<int> getKeysPressed();


public slots:
    void gameEnded(std::string message);
signals:
    /**
     * @brief gameStarted signal
     */
    void gameStarted();
    /**
     * @brief keyEvent
     * @param keysPressed_, QVector, contains pressed keys number values
     */
    void keyEvent(QVector<int> keysPressed_);

private slots:
    /**
     * @brief on_startButton_clicked opens startWindow, and emits gameStarted
     * signal
     */
    void on_startButton_clicked();
    /**
     * @brief keyPressEvent reads key presses, updates keysPressed_ and emits
     * it in signal keyEvent
     * @param event
     */
    void keyPressEvent( QKeyEvent* event );
    /**
     * @brief keyReleaseEvent reads key presses, updates keysPressed_ and emits
     * it in signal keyEvent
     * @param event
     */
    void keyReleaseEvent( QKeyEvent* event);
    /**
     * @brief setPlayer saves players name to the mainwindow
     * @param name
     */
    void setPlayer(std::string name);
    /**
     * @brief setGoal gives the point goal to statistics
     * @param difficulty
     */
    void setGoal(std::string difficulty);

private:
    Ui::MainWindow *ui;

    QGraphicsScene *map;

    QTimer *timer;
    QMap<std::shared_ptr<Interface::IActor>, Game::GraphicsObject*> actors_;
    QMap<std::shared_ptr<Interface::IStop>, Game::GraphicsObject*> stops_;
    QMap<std::shared_ptr<Game::Restaurant>, Game::GraphicsObject*> restaurants_;
    QMap<std::shared_ptr<Game::Restaurant>, QGraphicsTextItem*> restaurantLabels_;
    StartWindow* startwindow_;

    QVector<int> keysPressed_;

    int width_ = 1095; //pxls
    int height_ = 592;

    Interface::Location centreOfMap_;
    int tick_ = 500; //ms
    int type_;
    std::string name_;

    std::shared_ptr<Game::Statistics> statistics_;

    bool isGameStarted_;


};

} //namespace
#endif // SIMPLEMAINWINDOW_HH
