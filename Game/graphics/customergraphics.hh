#ifndef CUSTOMERGRAPHICS_HH
#define CUSTOMERGRAPHICS_HH

#include "graphicsobject.hh"
namespace Game {
    class CustomerGraphics : public Game::GraphicsObject
    {
    public:
        CustomerGraphics(int x, int y, std::string type);
        virtual ~CustomerGraphics();
        void setCoord(int x, int y);

    private:
        int x_;
        int y_;
        std::string type_;
        QPixmap picture_;
    };
}


#endif // CUSTOMERGRAPHICS_HH
