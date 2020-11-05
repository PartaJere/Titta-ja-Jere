#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include "interfaces/iactor.hh"
#include "graphics/simpleactoritem.hh"
#include "interfaces/iactor.hh"
#include "interfaces/istop.hh"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>
#include <memory>
#include <QVector>
#include <QKeyEvent>
#include <map>

namespace Ui {
class MainWindow;
}

namespace Game {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

    void setSize(int w, int h);
    void setTick(int t);

    virtual void addActor(std::shared_ptr<Interface::IActor> actor,int locX, int locY);
    void addStop(std::shared_ptr<Interface::IStop> stop, int locX, int locY);
    void updateCoords(int nX, int nY);

    void moveActor(std::shared_ptr<Interface::IActor> actor);
    void setPicture(QImage &img);

    QGraphicsScene *map;

signals:
    void gameStarted();
    void keyPressed(int key);
    void keyReleased(int key);

private slots:
    void on_startButton_clicked();
    void keyPressEvent( QKeyEvent* event );
    void keyReleaseEvent( QKeyEvent* event);

private:
    Ui::MainWindow *ui;

    QTimer *timer;
    QMap<std::shared_ptr<Interface::IActor>, CourseSide::SimpleActorItem*> actors_;
    QMap<std::shared_ptr<Interface::IStop>, CourseSide::SimpleActorItem*> stops_;
    CourseSide::SimpleActorItem* last_;

    int width_ = 500; //pxls
    int height_ = 500;
    int tick_ = 500; //ms
};

} //namespace
#endif // SIMPLEMAINWINDOW_HH
