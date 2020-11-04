#ifndef ENGINE_HH
#define ENGINE_HH

#include <QObject>

#include "core/logic.hh"
#include "mainwindow.hh"
#include "city.hh"
#include "creategame.hh"

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
    public slots:


    private:
        CourseSide::Logic logic_;
        MainWindow mainwindow_;
        std::shared_ptr<Game::City> city_;

        QTimer timer_;

        void initGame();
    private slots:
        void startGame();
        void advance();
    };

}

#endif // ENGINE_HH
