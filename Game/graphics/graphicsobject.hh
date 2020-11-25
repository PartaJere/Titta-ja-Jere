#ifndef GRAPHICSCONTROL_HH
#define GRAPHICSCONTROL_HH

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QString>
#include <QPixmap>

namespace Game {


class GraphicsObject : public QGraphicsPixmapItem
{
public:
    GraphicsObject() = default;
    virtual ~GraphicsObject() = default;
    virtual void setCoord(int x, int y) = 0;

};

}



#endif // GRAPHICSCONTROL_HH

