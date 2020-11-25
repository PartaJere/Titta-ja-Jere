#ifndef ENGINE_HH
#define ENGINE_HH

#include <QObject>

#include "core/logic.hh"
#include "windows/mainwindow.hh"
#include "city.hh"
#include "creategame.hh"
#include "actors/player.hh"
#include "graphics/simpleactoritem.hh"


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
        std::vector<std::shared_ptr<Interface::IActor>> actors_;
        std::vector<std::shared_ptr<Interface::IStop>> stops_;
        int type_;


        QTimer timer_;
        float time_;
        std::shared_ptr<Game::Player> player_;

        int keyPressed_;

        void initGame();

        bool isGameOver();

        void stopGame();

        void checkPlayerDmg();

    private slots:
        void startGame();
        void advance();
        void movePlayer(int key);
    };

}

#endif // ENGINE_HH
