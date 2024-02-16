#include "robot_settings.h"
#include "ui_robot_settings.h"

robot_settings::robot_settings(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::robot_settings)
{
    ui->setupUi(this);
    this->setWindowTitle("Robot settings");
}

robot_settings::~robot_settings()
{
    delete ui;
}

void robot_settings::on_pushButton_clicked()
{
    this->reject();
}

