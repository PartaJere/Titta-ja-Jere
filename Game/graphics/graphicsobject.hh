#ifndef GRAPHICSCONTROL_HH
#define GRAPHICSCONTROL_HH

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QString>
#include <QPixmap>

namespace Game {


class ObjectControl : public QGraphicsPixmapItem
{
public:
    ObjectControl() = default;
    virtual ~ObjectControl() = default;
    virtual void setCoord(int x, int y) = 0;

};

}



#endif // GRAPHICSCONTROL_HH

