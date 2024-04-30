/**
 * @file mainwindow.h
 * @brief
 * @author David Zatloukal
 * @author Ondřej Beneš
 * @date 17.3.2024
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "robot_settings.h"
#include "obstacles.h"
#include "savefiledialog.h"
#include "loadfiledialog.h"
#include "SessionManager.h"
#include "maparea.h"
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


void MainWindow::AddRobotButton_clicked()
{
    robot_settings robot_settings_dialog;
    robot_settings_dialog.exec();
}


void MainWindow::AddObstacleButton_clicked()
{
    obstacles obstacles_dialog;
    obstacles_dialog.exec();
}


void MainWindow::exitButtons()
{
    this->close();
}


void MainWindow::createSceneButtons(QGraphicsScene* scene)
{
    //button to close the window;
    QPushButton* closeWindow = new QPushButton();
    closeWindow->setText("Close");
    closeWindow->setGeometry(1140,20, 100, 50);
    connect(closeWindow, &QPushButton::released, this, &MainWindow::exitButtons);
    scene->addWidget(closeWindow);

    //button to save current state to a file;
    QPushButton* saveCurrentState = new QPushButton();
    saveCurrentState->setText("Save");
    saveCurrentState->setGeometry(1015,20, 100, 50);
    connect(saveCurrentState, &QPushButton::released, this, &MainWindow::ButtonSaveSession_clicked);
    scene->addWidget(saveCurrentState);

    //button to add robot;
    QPushButton* addRobotButton = new QPushButton();
    addRobotButton->setText("Add robot");
    addRobotButton->setGeometry(890,20, 100, 50);
    connect(addRobotButton, &QPushButton::released, this, &MainWindow::AddRobotButton_clicked);
    scene->addWidget(addRobotButton);

    //button to add obstacle;
    QPushButton* addObstacleButton = new QPushButton();
    addObstacleButton->setText("Add obstacle");
    addObstacleButton->setGeometry(765,20, 100, 50);
    connect(addObstacleButton, &QPushButton::released, this, &MainWindow::AddObstacleButton_clicked);
    scene->addWidget(addObstacleButton);
}


void MainWindow::draw()
{
    this->ticker.setInterval(10);
    this->map->drawMap(this->scene);
    this->sceneView->update();
}


void MainWindow::on_ButtonSimulate_clicked()
{
    // Load all objects for the session
    SessionManager *manager = SessionManager::getManagerHandle();
    SessionManager::sessionData data = manager->getSessionData();

    //setup scene
    this->resize(1920, 1080); // Set size of the window
    this->scene = new QGraphicsScene();
    this->scene->setSceneRect(0, 0, 1920, 1080);
    this->sceneView = new QGraphicsView();
    this->map = new MapArea(1920, 1080);
    this->setCentralWidget(this->sceneView);
    this->createSceneButtons(this->scene);
    this->ticker.start();
    this->sceneView->setScene(this->scene);
    for (SessionManager::robotData robot : data.robots) {
        this->map->AddRobot(this->scene, robot);
    }
    for (SessionManager::obstacleData obstacle : data.obstacles) {
        this->map->AddObstacle(this->scene, obstacle);
    }
    connect(&ticker, &QTimer::timeout, this, &MainWindow::draw);
    //delete this->map;
}


void MainWindow::on_ButtonLoadSession_clicked()
{
    LoadFileDialog loadfile;
    loadfile.exec();
}

void MainWindow::ButtonSaveSession_clicked()
{
    SaveFileDialog savefile;
    savefile.exec();
}
