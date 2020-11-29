#include "gameendedwindow.hh"
#include "ui_gameendedwindow.h"

namespace Game {
    GameEndedWindow::GameEndedWindow(QWidget *parent, std::string message) :
        QDialog(parent),
        ui(new Ui::GameEndedWindow)
    {
        ui->setupUi(this);
        QString QStrMsg = QString::fromStdString(message);
        ui->gameEndReason->setText(QStrMsg);
        ui->pushButton->setText(QString("Ok"));
    }

    GameEndedWindow::~GameEndedWindow()
    {
        delete ui;
    }

    void GameEndedWindow::on_pushButton_clicked()
    {
        GameEndedWindow::close();
}
}

