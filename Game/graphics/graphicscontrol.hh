#ifndef GRAPHICSCONTROL_HH
#define GRAPHICSCONTROL_HH

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QString>
#include <QPixmap>

namespace Game {


class GraphicsControl : public QGraphicsPixmapItem
{
public:
    GraphicsControl(int x, int y, std::string type=0);
    virtual ~GraphicsControl();
    void setCoord(int x, int y);


private:
    int x_;
    int y_;
    std::string type_;
    QPixmap picture_;
};

}



#endif // GRAPHICSCONTROL_HH

