#ifndef DIALOG_HH
#define DIALOG_HH

#include <QDialog>

namespace Ui {
class StartWindow;
}

namespace Game{
class StartWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

signals:
    void setPlayerName(std::string name);
    void setDifficulty(std::string difficulty);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::StartWindow *ui;
};

}


#endif // DIALOG_HH
