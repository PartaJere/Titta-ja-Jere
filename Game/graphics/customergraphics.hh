#ifndef CUSTOMERGRAPHICS_HH
#define CUSTOMERGRAPHICS_HH

#include "graphicsobject.hh"
namespace Game {

    /**
     * @brief The CustomerGraphics class creates and controls the graphics of customers
     */
    class CustomerGraphics : public Game::GraphicsObject
    {
    public:
        /**
         * @brief CustomerGraphics constructs the graphics of a customer by loading the file as a pixmap and setting it
         * @param x is the wanted x-coordinate for customergraphics
         * @param y is the wanted y-coordinate for customergraphics
         * @param type tells which type of actor this is
         */
        CustomerGraphics(int x, int y, std::string type);

        /**
         * @brief ~CustomerGraphics default destructor
         */
        virtual ~CustomerGraphics();

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
        QPixmap picture_;
    };
}


#endif // CUSTOMERGRAPHICS_HH
