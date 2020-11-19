#include <QApplication>
#include "core/engine.hh"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);
    Game::Engine engine;
    return a.exec();
}
