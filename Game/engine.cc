#include "engine.hh"

namespace Game {
    Engine::Engine() :
        logic_(new CourseSide::Logic),
        mainwindow_(new CourseSide::SimpleMainWindow)
    {
        initGame();
    }

    void Engine::initGame()
    {
        std::shared_ptr<Interface::ICity> icityptr = Interface::createGame();
        logic_.takeCity(icityptr);

        std::shared_ptr<Game::City> cityptr = std::dynamic_pointer_cast<Game::City>(icityptr);
        city_ = cityptr;
        mainwindow_.show();
        QImage img = city_->getBasicBackground();
        mainwindow_.setPicture(img);
    }
}

