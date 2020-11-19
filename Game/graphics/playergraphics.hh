#ifndef PLAYERGRAPHICS_H
#define PLAYERGRAPHICS_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QString>
#include <QPixmap>

namespace Game {

class PlayerGraphics : public QGraphicsPixmapItem
{
public:
    PlayerGraphics(int x, int y, std::string type=0);
    virtual ~PlayerGraphics();
    void setCoord(int x, int y);

private:
    int x_;
    int y_;
    std::string type_;
    QPixmap picture_;
};


}

#endif // PLAYERGRAPHICS_H
