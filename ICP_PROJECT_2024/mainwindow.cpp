#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "robot_settings.h"
#include "obstacles.h"
#include "json_interface.h"
//#include "simulation.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Robot simulation");
    this->ui->filePath->setPlaceholderText("Path to file for readiong and writing simulation settings.");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_add_robot_Button_clicked()
{
    robot_settings robot_settings_dialog;
    robot_settings_dialog.exec();
}


void MainWindow::on_add_obstacle_Button_clicked()
{
    obstacles obstacles_dialog;
    obstacles_dialog.exec();
}


void MainWindow::on_set_path_Button_clicked()
{
    QString filePath = this->ui->filePath->toPlainText();
    JsonInterface *handle = JsonInterface::getJsonHandle() ;
    if (!handle->setPath(filePath, true)) {
        qDebug() << "Error: Could not read file";
        return;
    }
    this->updateButtons();
}


void MainWindow::on_create_file_Button_clicked()
{
    QString filePath = this->ui->filePath->toPlainText();
    JsonInterface *handle = JsonInterface::getJsonHandle() ;
    if (!handle->setPath(filePath, false)) {
        qDebug() << "Error: Could not create file";
        return;
    }
    this->updateButtons();
}


void MainWindow::updateButtons() {
    this->ui->filePath->setReadOnly(true);

    // Set buttons state
    this->ui->Button_simulate->setEnabled(true);
    this->ui->new_simulation_Button->setEnabled(true);
    this->ui->add_obstacle_Button->setEnabled(true);
    this->ui->add_robot_Button->setEnabled(true);
    this->ui->set_path_Button->setEnabled(false);
    this->ui->create_file_Button->setEnabled(false);

    // Indicate change of state via color
    QTextCursor cursor = this->ui->filePath->textCursor();
    QTextCharFormat format;
    format.setForeground(QColor(Qt::gray));
    format.setFontItalic(true);
    cursor.select(QTextCursor::Document);
    cursor.mergeCharFormat(format);
}


void MainWindow::on_Button_simulate_clicked()
{
    QJsonObject objects;
    JsonInterface *handle = JsonInterface::getJsonHandle();
    if (!handle->getJsonObjects(&objects)) {
        return; // Failed to load file
    }

    // TODO: Go Through objects and call a constructor
}


