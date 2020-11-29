#ifndef ENGINE_HH
#define ENGINE_HH

#include <QObject>

#include "core/logic.hh"
#include "windows/mainwindow.hh"
#include "city.hh"
#include "creategame.hh"
#include "actors/player.hh"
#include "graphics/simpleactoritem.hh"
#include "core/statistics.hh"
#include "actors/customer.hh"

/**
  * @file
  * @brief Defines a class that initializes and runs the game. When initialized,
  * it puts the game to the initialization state.
  */
namespace Game  {
    class Engine : public QObject
    {
        Q_OBJECT
    public:
        /**
         * @brief Engine contstructs the engine for the game. Initializes logic, mainwindow, time, player and statistic
         * pointers. Calls for game to be initialized. Connects signals to gameEnded and startGame slots.
         */
        Engine();

    signals:
        /**
         * @brief gameOver emits the message that game has ended.
         * @param message tells the reason that game has ended.
         */
        void gameOver(std::string message);

    public slots:


    private:

        /**
         * @brief initGame initiliazies the game to be ready for game state. Calls for logic to start working and
         * creates a city pointer. Shows MainWindow and sets a background to it. Adds stops and restaurants. Starts
         * timer.
         * @post Game has been initialized
         */
        void initGame();

        /**
         * @brief isGameOver checks if game has been lost or won, and for what reason and emits a gameOver signal if
         * needed to.
         * @return boolean telling whether game is over.
         */
        bool isGameOver();

        /**
         * @brief checkInteractions checks whether player has come close enough to other actors to interact with
         * them. Calls for actions if so.
         */
        void checkInteractions();

        /**
         * @brief clearGame clears the game for it to be ready to be started fresh. Calls for mainwindow to delete actors
         * and for actors classes own reset methods.
         */
        void clearGame();


        CourseSide::Logic logic_;
        MainWindow mainwindow_;
        std::shared_ptr<Game::City> city_;
        bool gameStartedBool;
        QTimer timer_;
        float time_;
        std::shared_ptr<Game::Player> player_;
        std::shared_ptr<Game::Statistics> statistics_;



    private slots:
        /**
         * @brief startGame starts the game. First clears the game and then adds a player to map and updates game's
         * own timer and player's healthbar.
         */
        void startGame();

        /**
         * @brief advance updates all sorts of stuff in game. Adds actors, moves them and clears them out. Calls
         * for checkInteractions and updates points, trunk value, hpbar, timeleft and moves map.
         */
        void advance();

        /**
         * @brief movePlayer moves the player according to pressed keys.
         * @param keysPressed
         */
        void movePlayer(QVector<int> keysPressed);
    };

}

#endif // ENGINE_HH
