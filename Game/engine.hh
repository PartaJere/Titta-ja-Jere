#ifndef ENGINE_HH
#define ENGINE_HH

#include <QObject>

#include "core/logic.hh"
#include "mainwindow.hh"
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
    public slots:


    private:
        CourseSide::Logic logic_;
        MainWindow mainwindow_;
        std::shared_ptr<Game::City> city_;
        std::vector<std::shared_ptr<Interface::IActor>> actors_;
        std::vector<std::shared_ptr<Interface::IStop>> stops_;
        int type_;


        QTimer timer_;

        void initGame();
        void setType(std::shared_ptr<Interface::IActor>);

    private slots:
        void startGame();
        void advance();
    };

}

#endif // ENGINE_HH
