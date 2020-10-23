#ifndef ENGINE_HH
#define ENGINE_HH

#include <QObject>

#include "core/logic.hh"
#include "graphics/simplemainwindow.hh"
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

    private:
        CourseSide::Logic logic_;
        CourseSide::SimpleMainWindow mainwindow_;
        std::shared_ptr<Game::City> city_;

        void initGame();
    };

}

#endif // ENGINE_HH
