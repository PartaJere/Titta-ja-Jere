#ifndef DIALOG_HH
#define DIALOG_HH

#include <QDialog>
#include <QDebug>
#include <string>
#include <algorithm>
#include <locale>
namespace Ui {
class StartWindow;
}

namespace Game{
/**
 * @brief The StartWindow class is dialog window that the user input their name and chosen difficutly
 * into to start the game
 */
class StartWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief StartWindow sets up Ui
     * @param parent QDialog
     */
    explicit StartWindow(QWidget *parent = nullptr);

    ~StartWindow();

signals:

    /**
     * @brief setPlayerName is a signal that carries player's name to be set somewhere
     * @param name is the name player has inserted for themselved
     */
    void setPlayerName(std::string name);

    /**
     * @brief setDifficulty is a signal that carries the game difficulty to be set
     * @param difficulty is the difficulty the player has chosen for their game
     */
    void setDifficulty(std::string difficulty);

private slots:

    /**
     * @brief on_buttonBox_accepted gets information from startwindow and sends signals out into the world
     */
    void on_buttonBox_accepted();

    /**
     * @brief on_buttonBox_rejected closes the startwindow
     */
    void on_buttonBox_rejected();

private:
    Ui::StartWindow *ui;
};

}


#endif // DIALOG_HH
