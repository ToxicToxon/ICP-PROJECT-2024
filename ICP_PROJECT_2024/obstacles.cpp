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
    int diameter = this->ui->text_diameter->toPlainText().toInt();
    int angle = this->ui->text_angle->toPlainText().toInt();
    int x_pos =  this->ui->text_x->toPlainText().toInt();
    int y_pos = this->ui->text_y->toPlainText().toInt();

    SessionManager* manager = SessionManager::getManagerHandle();

    manager->addObstacle(diameter, angle, x_pos, y_pos);

    // Clear all text fields
    this->ui->text_diameter->clear();
    this->ui->text_angle->clear();
    this->ui->text_x->clear();
    this->ui->text_y->clear();
}

