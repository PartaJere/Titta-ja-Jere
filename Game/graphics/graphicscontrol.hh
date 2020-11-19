#ifndef GRAPHICSCONTROL_HH
#define GRAPHICSCONTROL_HH

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QString>

namespace Game {


const int WIDTH = 5;
const int HEIGHT = 5;

class GraphicsControl : public QGraphicsItem
{
public:
    GraphicsControl(int x, int y, std::string type=0);
    virtual ~GraphicsControl();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option = 0, QWidget *widget = 0);
    void setCoord(int x, int y);


private:
    int x_;
    int y_;
    std::string type_;
};

}



#endif // GRAPHICSCONTROL_HH

