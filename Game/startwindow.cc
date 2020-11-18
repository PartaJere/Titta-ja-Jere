#include "startwindow.hh"
#include "ui_startwindow.h"


namespace Game {

StartWindow::StartWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_buttonBox_accepted()
{
    std::string playerName = ui->lineEdit->text().toStdString();
    emit setPlayerName(playerName);
    StartWindow::close();
}

void StartWindow::on_buttonBox_rejected()
{
    StartWindow::close();
}

}

