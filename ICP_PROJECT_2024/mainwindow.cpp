#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "robot_settings.h"
#include "obstacles.h"

#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
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

class Robot
{
    public:
        int Diameter;
        int Velocity;
        int Angle;
        int XPos;
        int YPos;
        int DetectionRange;
        bool IsControlled;

        Robot(int diameter, int velocity, int angle, int xPos, int yPos, bool isControlled) //Constructor
        {
            Diameter = diameter;
            Velocity = velocity;
            Angle = angle;
            XPos = xPos;
            YPos = yPos;
            IsControlled = isControlled;
        }
        void Move()
        {

        }


};



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
    QGraphicsScene* scene = new QGraphicsScene(0,0,300,300); //TODO: somehow move it into main
    QGraphicsView* view = new QGraphicsView(scene);
    view->show();
    close();


}

