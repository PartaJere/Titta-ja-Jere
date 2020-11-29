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


    /**
     * @brief setTick sets tick to the mainwindow
     * @param t
     */
    void setTick(int t);

    /**
     * @brief addActor adds new actor to the scene. It will recognize the type
     * of the actor (player, customer, passenger, bus)
     * @param actor, shared_ptr<Interface::IActor>
     * @post if actor is close to the map, graphics will be drawn
     */
    virtual void addActor(std::shared_ptr<Interface::IActor> actor);

    /**
     * @brief addStop
     * @param stop, shared_ptr<Interface::IStop>
     * @pre stop has location
     * @post stop is added to the scene
     */
    void addStop(std::shared_ptr<Interface::IStop> stop);

    /**
     * @brief addRestaurant
     * @param restaurant
     * @pre restaurant has location
     * @post restaurant and it's counter for food available is added
     */
    void addRestaurant(std::shared_ptr<Game::Restaurant> restaurant);

    /**
     * @brief moveActor
     * @param actor
     * @post actorgraphics location matches actor's location
     */
    void moveActor(std::shared_ptr<Interface::IActor> actor);

    /**
     * @brief setPicture
     * @param img
     * @pre img is loaded
     * @post background picture is set
     */
    void setPicture(QImage &img);

    /**
     * @brief updateTimeLeft
     * @param timeLeft
     * @post graphics for timeLeft is updated
     */
    void updateTimeLeft(int timeLeft);

    /**
     * @brief updateHpBar Updates the hp bar with given value
     * @param hp
     */
    void updateHpBar(int hp);

    /**
     * @brief updateRestaurant updates restaurants foodAvailable value on top
     * of the restaurant graphics
     * @param restaurant
     */
    void updateRestaurant(std::shared_ptr<Game::Restaurant> restaurant);

    /**
     * @brief updateTrunk updates the trunk-value to the given amount.
     * @param amount
     */
    void updateTrunk(int amount);

    /**
     * @brief updatePoints checks points from statistics and updates them to
     * the graphics.
     * @param statistics
     */
    void updatePoints(std::shared_ptr<Game::Statistics> statistics);

    /**
     * @brief moveView moves the center of the game's view to given location.
     * @param loc
     */
    void moveView(Interface::Location loc);

    /**
     * @brief deleteActor deletes given actor's graphics.
     * @pre actor has graphics.
     * @post actor graphics are deleted.
     * @param actor, shared_ptr<Interface::IActor>
     */
    void deleteActor(std::shared_ptr<Interface::IActor> actor);

    /**
     * @brief takeStatistics
     * @param statistics, shared_ptr<Game::Statistics>
     */
    void takeStatistics(std::shared_ptr<Game::Statistics> statistics);

    /**
     * @brief getKeysPressed returns currently pressed buttons integer values.
     * @return QVector<int>
     */
    QVector<int> getKeysPressed();


public slots:

    /**
     * @brief gameEnded displays gameEndedWindow and changes isGameStarted_ to
     * false
     * @param message, forwarded to gameEndedWindow
     */
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

    int width_;
    int height_;
    int tick_;

    std::string name_;

    std::shared_ptr<Game::Statistics> statistics_;
    Interface::Location centerOfMap_;

    bool isGameStarted_;


};

} //namespace
#endif // SIMPLEMAINWINDOW_HH
