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
        Engine();

    signals:
        void gameOver(std::string message);

    public slots:


    private:
        CourseSide::Logic logic_;
        MainWindow mainwindow_;
        std::shared_ptr<Game::City> city_;
        bool gameStartedBool;
        QTimer timer_;
        float time_;
        std::shared_ptr<Game::Player> player_;
        std::shared_ptr<Game::Statistics> statistics_;




        void initGame();

        bool isGameOver();

        void stopGame();

        void checkInteractions();

        void clearGame();


    private slots:
        void startGame();
        void advance();
        void movePlayer(QVector<int> keysPressed);
    };

}

#endif // ENGINE_HH
