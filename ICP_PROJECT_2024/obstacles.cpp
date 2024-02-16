#include "obstacles.h"
#include "ui_obstacles.h"

obstacles::obstacles(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::obstacles)
{
    ui->setupUi(this);
    this->setWindowTitle("Obstacle settings");
}

obstacles::~obstacles()
{
    delete ui;
}
