/**
 * @file obstacles.cpp
 * @brief Implementation of the obstacles dialog functions
 * @author David Zatloukal
 * @author Ondřej Beneš
 * @date 28.4.2024
 */

#include "obstacles.h"
#include "ui_obstacles.h"
#include "SessionManager.h"

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


void obstacles::on_saveButton_clicked()
{
    bool OK = false;

    int angle = this->ui->text_angle->toPlainText().toInt(&OK);
    if (!OK) {
        this->ui->text_angle->clear();
        this->ui->text_angle->setText("0");
        return;
    }
    int diameter = this->ui->text_diameter->toPlainText().toInt(&OK);
    if (!OK || diameter < 1) {
        this->ui->text_diameter->clear();
        this->ui->text_diameter->setPlaceholderText("INVALID");
        return;
    }
    int x_pos =  this->ui->text_x->toPlainText().toInt(&OK);
    if (!OK || x_pos > 1200 - diameter || x_pos < 0) {
        this->ui->text_x->clear();
        this->ui->text_x->setPlaceholderText("X");
        return;
    }
    int y_pos = this->ui->text_y->toPlainText().toInt(&OK);
    if (!OK || y_pos > 800 - diameter || y_pos < 0) {
        this->ui->text_y->clear();
        this->ui->text_y->setPlaceholderText("Y");
        return;
    }

    SessionManager* manager = SessionManager::getManagerHandle();

    manager->addObstacle(diameter, angle, x_pos, y_pos);

    // Clear all text fields
    this->ui->text_diameter->clear();
    this->ui->text_angle->clear();
    this->ui->text_x->clear();
    this->ui->text_y->clear();

    this->ui->text_diameter->setPlaceholderText("");
    this->ui->text_angle->setPlaceholderText("");
    this->ui->text_x->setPlaceholderText("");
    this->ui->text_y->setPlaceholderText("");
}

