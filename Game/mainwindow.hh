#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include "interfaces/iactor.hh"
#include "graphics/simpleactoritem.hh"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>
#include <memory>
#include <QVector>
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

    virtual void addActor(int locX, int locY, int type = 0);
    void updateCoords(int nX, int nY);
    void setPicture(QImage &img);

    QGraphicsScene *map;

signals:
    void gameStarted();

private slots:
    void on_startButton_clicked();

private:
    Ui::MainWindow *ui;

    QTimer *timer;
    QVector<CourseSide::SimpleActorItem*> actors_;
    CourseSide::SimpleActorItem* last_;

    int width_ = 500; //pxls
    int height_ = 500;
    int tick_ = 500; //ms
};

} //namespace
#endif // SIMPLEMAINWINDOW_HH
