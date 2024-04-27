/**
 * @file robot_settings.cpp
 * @brief Implementation of the Robot Settings dialog.
 * @author David Zatloukal
 * @author Ondřej Beneš
 * @date 16.4.2024
 */

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
    if (this->ui->checkBox_controlled->isChecked()) {
        type= 1;
    }

    bool OK = false;

    int angle = this->ui->text_angle->toPlainText().toInt(&OK);
    if (!OK) {
        this->ui->text_angle->clear();
        this->ui->text_angle->setText("0");
    }
    int diameter = this->ui->text_diameter->toPlainText().toInt(&OK);
    if (!OK) {
        this->ui->text_diameter->clear();
        this->ui->text_diameter->setPlaceholderText("INVALID");
        return;
    }
    int x_pos =  this->ui->text_x->toPlainText().toInt(&OK);
    if (!OK) {
        this->ui->text_x->clear();
        this->ui->text_x->setPlaceholderText("INVALID");
        return;
    }
    int y_pos = this->ui->text_y->toPlainText().toInt(&OK);
    if (!OK) {
        this->ui->text_y->clear();
        this->ui->text_y->setPlaceholderText("INVALID");
        return;
    }
    int fov = this->ui->text_fov->toPlainText().toInt(&OK);
    if (!OK) {
        this->ui->text_fov->clear();
        this->ui->text_fov->setPlaceholderText("INVALID");
        return;
    }
    int r_angle = this->ui->text_r_angle->toPlainText().toInt(&OK);
    if (!OK) {
        this->ui->text_r_angle->clear();
        this->ui->text_r_angle->setPlaceholderText("INVALID");
        return;
    }
    int r_direction = this->ui->text_r_direction->toPlainText().toInt(&OK);
    if (!OK) {
        this->ui->text_r_direction->clear();
        this->ui->text_r_direction->setPlaceholderText("INVALID");
        return;
    }

    JsonInterface* jsonHandler = JsonInterface::getJsonHandle();

    jsonHandler->add_robot("r", type, diameter, angle, x_pos, y_pos, fov, r_angle, r_direction);

    // Clear all textboxes
    this->ui->text_diameter->clear();
    this->ui->text_diameter->clear();
    this->ui->text_angle->clear();
    this->ui->text_x->clear();
    this->ui->text_y->clear();
    this->ui->text_fov->clear();
    this->ui->text_r_angle->clear();
    this->ui->text_r_direction->clear();

    // Clear the placeholder text
    this->ui->text_diameter->setPlaceholderText("");
    this->ui->text_diameter->setPlaceholderText("");
    this->ui->text_angle->setPlaceholderText("");
    this->ui->text_x->setPlaceholderText("");
    this->ui->text_y->setPlaceholderText("");
    this->ui->text_fov->setPlaceholderText("");
    this->ui->text_r_angle->setPlaceholderText("");
    this->ui->text_r_direction->setPlaceholderText("");

    if (this->ui && this->ui->checkBox_controlled) {
        this->ui->checkBox_controlled->setChecked(false);
    }
    if (this->ui && this->ui->checkBox_controlled) {
        this->ui->checkBox_random->setChecked(false);
    }
}

