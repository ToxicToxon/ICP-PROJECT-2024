/**
 * @file robots.cpp
 * @brief Implementation of the Robot Settings dialog.
 * @author David Zatloukal
 * @author Ondřej Beneš
 * @date 16.4.2024
 */

#include "robots.h"
#include "ui_robots.h"
#include "SessionManager.h"

/*!
 * \brief Instantiates the robots
 * \param parent Specifies which widget to inherit from
 */
robots::robots(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::robots)
{
    ui->setupUi(this);
    this->setWindowTitle("Robot settings");
}


/*!
 * \brief Removes an instance of the robots
 */
robots::~robots()
{
    delete ui;
}


/*!
 * \brief Saves data from robots form to SessionManager if the data is valid
 * Upon receiving invalid values, informs the user and waits for new data, otherwise clears the form and waits for next input
 */
void robots::on_saveButton_clicked()
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
    if (!OK || x_pos >= 1200 - diameter || x_pos <= 0) {
        this->ui->text_x->clear();
        this->ui->text_x->setPlaceholderText("X");
        return;
    }
    int y_pos = this->ui->text_y->toPlainText().toInt(&OK);
    if (!OK || y_pos >= 800 - diameter || y_pos <= 0) {
        this->ui->text_y->clear();
        this->ui->text_y->setPlaceholderText("Y");
        return;
    }
    int fov = this->ui->text_fov->toPlainText().toInt(&OK);
    if (!OK || fov <= 0) {
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
    if (!OK || (r_direction != 1 && r_direction != -1)) {
        this->ui->text_r_direction->clear();
        this->ui->text_r_direction->setPlaceholderText("INVALID");
        return;
    }

    SessionManager* manager = SessionManager::getManagerHandle();
    manager->addRobot(type, diameter, angle, x_pos, y_pos, fov, r_angle, r_direction);

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
}

