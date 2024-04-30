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


void MainWindow::exitButtons()
{
    this->close();
}

void MainWindow::turnLeft()
{
    this->map->turnAllUserRobots(false);
}

void MainWindow::turnRight()
{
    qDebug() << "turn right";
    this->map->turnAllUserRobots(true);
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
    connect(saveCurrentState, &QPushButton::released, this, &MainWindow::on_ButtonSaveSession_clicked);
    scene->addWidget(saveCurrentState);


    //button to add robot;
    QPushButton* addRobotButton = new QPushButton();
    addRobotButton->setText("Add robot");
    addRobotButton->setGeometry(890,20, 100, 50);
    connect(addRobotButton, &QPushButton::released, this, &MainWindow::on_add_robot_Button_clicked);
    scene->addWidget(addRobotButton);

    //button to add obstacle;
    QPushButton* addObstacleButton = new QPushButton();
    addObstacleButton->setText("Add obstacle");
    addObstacleButton->setGeometry(765,20, 100, 50);
    connect(addObstacleButton, &QPushButton::released, this, &MainWindow::on_add_obstacle_Button_clicked);
    scene->addWidget(addObstacleButton);

    //button to turn all user robots left;
    QPushButton* addTurnUserLeftButton = new QPushButton();
    addTurnUserLeftButton->setText("<-");
    addTurnUserLeftButton->setGeometry(890, 900, 100, 50);
    connect(addTurnUserLeftButton, &QPushButton::released, this, &MainWindow::turnLeft);
    scene->addWidget(addTurnUserLeftButton);

    //button to turn all user robots right;
    QPushButton* addTurnUserRightButton = new QPushButton();
    addTurnUserRightButton->setText("->");
    addTurnUserRightButton->setGeometry(1015, 900, 100, 50);
    connect(addTurnUserRightButton, &QPushButton::released, this, &MainWindow::turnRight);
    scene->addWidget(addTurnUserRightButton);
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
        this->map->addRobot(this->scene, robot);
    }
    for (SessionManager::obstacleData obstacle : data.obstacles) {
        this->map->addObstacle(this->scene, obstacle);
    }
    connect(&ticker, &QTimer::timeout, this, &MainWindow::draw);
    //delete this->map;
}


void MainWindow::on_ButtonLoadSession_clicked()
{
    SessionManager *manager = SessionManager::getManagerHandle();
    if (manager->loadSessionData(this->ui->TextPathToFile->toPlainText())) {
        this->ui->TextPathToFile->setPlaceholderText("Session loaded.");
        return;
    }
    this->ui->TextPathToFile->setPlaceholderText("Loading failed");
}

void MainWindow::on_ButtonSaveSession_clicked()
{
    SessionManager *manager = SessionManager::getManagerHandle();
    //manager->saveSession("/Users/ondra/Desktop/testout.json", true); // TODO: Change file to "this->ui->TextPathToFile->toPlainText()"
}
