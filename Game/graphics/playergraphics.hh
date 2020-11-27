#ifndef PLAYERGRAPHICS_H
#define PLAYERGRAPHICS_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QString>
#include <QPixmap>

#include "graphics/graphicsobject.hh"

namespace Game {

/**
 * @brief The PlayerGraphics class creates and controls the graphics of players
 */
class PlayerGraphics : public GraphicsObject
{
public:
    /**
     * @brief PlayerGraphics constructs the graphics of a player by loading the file as a pixmap and setting it
     * @param x is the wanted x-coordinate for playergraphics
     * @param y is the wanted y-coordinate for playergraphics
     * @param type tells which type of actor this is
     */
    PlayerGraphics(int x, int y, std::string type=0);

    /**
     * @brief ~PlayerGraphics default destructor
     */
    virtual ~PlayerGraphics();

    /**
     * @brief setCoord changes the coordinates of the graphicsitem
     * @param x is the x-coordinate that graphics' coord will be changed to
     * @param y is the y-coordinate that graphics' coord will be changed to
     */
    void setCoord(int x, int y);

private:
    int x_;
    int y_;
    std::string type_;
    QPixmap pictureLeft_;
    QPixmap pictureRight_;
};


}

#endif // PLAYERGRAPHICS_H
