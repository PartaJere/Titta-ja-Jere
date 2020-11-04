#ifndef ENGINE_HH
#define ENGINE_HH

#include <QObject>

#include "core/logic.hh"
#include "graphics/simplemainwindow.hh"
#include "city.hh"
#include "creategame.hh"
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

    private:
        CourseSide::Logic logic_;
        CourseSide::SimpleMainWindow mainwindow_;
        std::shared_ptr<Game::City> city_;
        std::vector<std::shared_ptr<Interface::IActor>> actors_;
        std::vector<std::shared_ptr<Interface::IStop>> stops_;


        void initGame();
    private slots:
        void startGame();

    };

}

#endif // ENGINE_HH
