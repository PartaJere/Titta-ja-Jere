#include "dialog.hh"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    std::string playerName = ui->lineEdit->text().toStdString();
    Dialog::close();
}

void Dialog::on_buttonBox_rejected()
{
    Dialog::close();
}
