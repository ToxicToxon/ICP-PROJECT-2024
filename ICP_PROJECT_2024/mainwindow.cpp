#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "robot_settings.h"
#include "obstacles.h"
//#include "simulation.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Robot simulation");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_4_clicked()
{
    robot_settings robot_settings_dialog;
    robot_settings_dialog.exec();
}


void MainWindow::on_pushButton_5_clicked()
{
    obstacles obstacles_dialog;
    obstacles_dialog.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
   // pushButton_2->hide();
}

