#include <QApplication>

#include "core/logic.hh"
#include "graphics/simplemainwindow.hh"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);
    CourseSide::SimpleMainWindow mainWindow;
    mainWindow.show();
    return a.exec();
}
