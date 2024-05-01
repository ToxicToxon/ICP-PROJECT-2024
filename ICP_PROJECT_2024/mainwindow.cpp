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
    SessionManager *manager = SessionManager::getManagerHandle();
    size_t len = manager->getSessionData().robots.size();
    robot_settings robot_settings_dialog;
    robot_settings_dialog.exec();
    if (len < manager->getSessionData().robots.size()) {
        this->map->addRobot(this->scene, manager->getSessionData().robots.back());
    }
}


void MainWindow::AddObstacleButton_clicked()
{
    SessionManager *manager = SessionManager::getManagerHandle();
    size_t len = manager->getSessionData().obstacles.size();
    obstacles obstacles_dialog;
    obstacles_dialog.exec();
    if (len < manager->getSessionData().obstacles.size()) {
        this->map->addObstacle(this->scene, manager->getSessionData().obstacles.back());
    }
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
    this->map->turnAllUserRobots(true);
}

void MainWindow::stop()
{
    this->map->stopAllUserRobots();
}

void MainWindow::go()
{
    this->map->goAllUserRobots();
}

void MainWindow::pausePlay()
{
    this->map->pausePlay();
}

void MainWindow::createSceneButtons(QGraphicsScene* scene)
{
    //button to close the window;
    QPushButton* closeWindow = new QPushButton();
    closeWindow->setText("Close");
    closeWindow->setGeometry(1100,20, 100, 50);
    connect(closeWindow, &QPushButton::released, this, &MainWindow::exitButtons);
    scene->addWidget(closeWindow);

    //button to save current state to a file;
    QPushButton* saveCurrentState = new QPushButton();
    saveCurrentState->setText("Save");
    saveCurrentState->setGeometry(980,20, 100, 50);
    connect(saveCurrentState, &QPushButton::released, this, &MainWindow::ButtonSaveSession_clicked);
    scene->addWidget(saveCurrentState);

    //button to add robot;
    QPushButton* addRobotButton = new QPushButton();
    addRobotButton->setText("Add robot");
    addRobotButton->setGeometry(860,20, 100, 50);
    connect(addRobotButton, &QPushButton::released, this, &MainWindow::AddRobotButton_clicked);
    scene->addWidget(addRobotButton);

    //button to add obstacle;
    QPushButton* addObstacleButton = new QPushButton();
    addObstacleButton->setText("Add obstacle");
    addObstacleButton->setGeometry(740,20, 100, 50);
    connect(addObstacleButton, &QPushButton::released, this, &MainWindow::AddObstacleButton_clicked);
    scene->addWidget(addObstacleButton);

    //button to pause/play;
    QPushButton* addPausePlayButton = new QPushButton();
    addPausePlayButton->setText("Play/Pause");
    addPausePlayButton->setGeometry(620, 20, 100, 50);
    connect(addPausePlayButton, &QPushButton::released, this, &MainWindow::pausePlay);
    scene->addWidget(addPausePlayButton);

    //button to turn all user robots left;
    QPushButton* addTurnUserLeftButton = new QPushButton();
    addTurnUserLeftButton->setText("<-");
    addTurnUserLeftButton->setGeometry(900, 750, 100, 50);
    connect(addTurnUserLeftButton, &QPushButton::released, this, &MainWindow::turnLeft);
    scene->addWidget(addTurnUserLeftButton);

    //button to turn all user robots right;
    QPushButton* addTurnUserRightButton = new QPushButton();
    addTurnUserRightButton->setText("->");
    addTurnUserRightButton->setGeometry(1100, 750, 100, 50);
    connect(addTurnUserRightButton, &QPushButton::released, this, &MainWindow::turnRight);
    scene->addWidget(addTurnUserRightButton);

    //button to turn all user robots left;
    QPushButton* addGoUserButton = new QPushButton();
    addGoUserButton->setText("^");
    addGoUserButton->setGeometry(1000, 700, 100, 50);
    connect(addGoUserButton, &QPushButton::released, this, &MainWindow::go);
    scene->addWidget(addGoUserButton);

    //button to turn all user robots right;
    QPushButton* addStopUserButton = new QPushButton();
    addStopUserButton->setText("x");
    addStopUserButton->setGeometry(1000, 750, 100, 50);
    connect(addStopUserButton, &QPushButton::released, this, &MainWindow::stop);
    scene->addWidget(addStopUserButton);
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
    this->resize(1400, 1000); // Set size of the window
    this->scene = new QGraphicsScene();
    this->scene->setSceneRect(0, 0, 1200, 800);
    this->sceneView = new QGraphicsView();
    this->map = new MapArea(1200, 800);
    this->setCentralWidget(this->sceneView);
    this->createSceneButtons(this->scene);
    this->ticker.start();
    this->sceneView->setScene(this->scene);
    this->map->setBorders(this->scene, 1200, 800);
    for (SessionManager::robotData robot : data.robots) {
        this->map->addRobot(this->scene, robot);
    }
    for (SessionManager::obstacleData obstacle : data.obstacles) {
        this->map->addObstacle(this->scene, obstacle);
    }
    this->map->drawMap(this->scene);
    this->map->pausePlay();
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
