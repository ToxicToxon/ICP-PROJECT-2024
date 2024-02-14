#include "robot_settings.h"
#include "ui_robot_settings.h"

robot_settings::robot_settings(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::robot_settings)
{
    ui->setupUi(this);
}

robot_settings::~robot_settings()
{
    delete ui;
}
