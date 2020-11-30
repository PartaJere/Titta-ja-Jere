#ifndef GAMEENDEDWINDOW_HH
#define GAMEENDEDWINDOW_HH

#include <QDialog>

namespace Ui {
class GameEndedWindow;
}

namespace Game {
    /**
     * @brief The GameEndedWindow class defines a dialog, that is shown when
     * the game ends. It displays the reason of the game ending.
     */
    class GameEndedWindow : public QDialog
    {
        Q_OBJECT

    public:
        /**
         * @brief GameEndedWindow
         * @param parent
         * @param message, displayed in the window
         */
        explicit GameEndedWindow(QWidget *parent = nullptr, std::string message = 0);
        ~GameEndedWindow();

    private slots:
        /**
         * @brief on_pushButton_clicked closed the window when called
         */
        void on_pushButton_clicked();

    private:
        Ui::GameEndedWindow *ui;
};
}


#endif // GAMEENDEDWINDOW_HH
