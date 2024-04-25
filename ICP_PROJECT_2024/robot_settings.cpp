#include "robot_settings.h"
#include "ui_robot_settings.h"
#include "json_interface.h"

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

void robot_settings::on_cancelButton_clicked()
{
    this->reject();
}


void robot_settings::on_saveButton_clicked()
{
    int type = 0;
    if (this->ui->checkBox_contoled) {
        type= 1;
    }
    int diameter = this->ui->text_diameter->toPlainText().toInt();
    int angle = this->ui->text_angle->toPlainText().toInt();
    int x_pos =  this->ui->text_x->toPlainText().toInt();
    int y_pos = this->ui->text_y->toPlainText().toInt();
    int fov = this->ui->text_fov->toPlainText().toInt();
    int r_angle = this->ui->text_r_angle->toPlainText().toInt();
    int r_direction = this->ui->text_r_direction->toPlainText().toInt();

    JsonInterface* jsonHandler = JsonInterface::getJsonHandle();

    jsonHandler->add_robot("robot", type, diameter, angle, x_pos, y_pos, fov, r_angle, r_direction);

    // Clear all textboxes
    this->ui->text_diameter->clear();
    this->ui->text_diameter->clear();
    this->ui->text_angle->clear();
    this->ui->text_x->clear();
    this->ui->text_y->clear();
    this->ui->text_fov->clear();
    this->ui->text_r_angle->clear();
    this->ui->text_r_direction->clear();

    this->ui->checkBox_contoled->setChecked(false);
    this->ui->checkBox_random->setChecked(false);
}

