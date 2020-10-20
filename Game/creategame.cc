#include "creategame.hh"

#include "tampere.hh"

#include <memory>
#include <QImage>

const QString DEFAULT_SMALLBACKGROUND_FILE = ":/offlinedata/offlinedata/kartta_pieni_500x500.png";
const QString DEFAULT_BIGBACKGROUND_FILE = ":/offlinedata/offlinedata/kartta_iso_1095x592.png";

using StudentSide::Tampere;

std::shared_ptr<Interface::ICity> Interface::createGame()
{
    std::shared_ptr<Tampere> city = std::make_shared<Tampere>(Tampere());
    QImage smallBackground = QImage(DEFAULT_SMALLBACKGROUND_FILE, "png");
    QImage bigBackground = QImage(DEFAULT_BIGBACKGROUND_FILE, "png");
    city->setBackground(smallBackground, bigBackground);
    return city;
}
