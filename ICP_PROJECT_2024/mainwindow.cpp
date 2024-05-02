/**
 * @file mainwindow.cpp
 * @brief
 * @author David Zatloukal
 * @author Ondřej Beneš
 * @date 17.3.2024
 */

#include "mainwindow.h"
#include "robots.h"
#include "obstacles.h"
#include "savefiledialog.h"
#include "loadfiledialog.h"
#include "SessionManager.h"

/*!
 * \brief Instantiates the MainWindow
 * \param parent Which widget to inherit from
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Robot simulation");
}


/*!
 * \brief Deletes the instance of MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}


/*!
 * \brief Initiates the robots dialog
 * If any robot is added, it is also loaded into the scene
 */
void MainWindow::AddRobotButton_clicked()
{
    SessionManager *manager = SessionManager::getManagerHandle();
    size_t len = manager->getSessionData().robots.size();
    robots robot_settings_dialog;
    robot_settings_dialog.exec();
    for (size_t i = len; i < manager->getSessionData().robots.size(); i++) {
        this->map->addRobot(this->scene, manager->getSessionData().robots[i]);
    }
}


/*!
 * \brief Initiates the obstacles dialog
 * If any obstacle is added, it is also loaded into the scene
 */
void MainWindow::AddObstacleButton_clicked()
{
    SessionManager *manager = SessionManager::getManagerHandle();
    size_t len = manager->getSessionData().obstacles.size();
    obstacles obstacles_dialog;
    obstacles_dialog.exec();
    for (size_t i = len; i < manager->getSessionData().obstacles.size(); i++) {
        this->map->addObstacle(this->scene, manager->getSessionData().obstacles[i]);
    }
}


/*!
 * \brief Closes the window
 */
void MainWindow::exitButtons()
{
    this->close();
}


/*!
 * \brief Calls the maparea::turnAllUserRobots()
 */
void MainWindow::turnLeft()
{
    this->map->turnAllUserRobots(false);
}


/*!
 * \brief Calls the maparea::turnAllUserRobots()
 */
void MainWindow::turnRight()
{
    this->map->turnAllUserRobots(true);
}


/*!
 * \brief Calls the maparea::stopAllUserRobots()
 */
void MainWindow::stop()
{
    this->map->stopAllUserRobots();
}


/*!
 * \brief Calls the maparea::goAllUserRobots()
 */
void MainWindow::go()
{
    this->map->goAllUserRobots();
}


/*!
 * \brief Calls maparea::pausePlay()
 * Also updates the text of the button
 */
void MainWindow::pausePlay()
{
    this->map->pausePlay();
    if (this->map->isPaused()) {
        this->pausePlayButton->setText("Play");
    }
    else {
        this->pausePlayButton->setText("Pause");
    }
}


/*!
 * \brief Sets up buttons for the simulation
 * \param scene Specifies where the bbuttons should be inserted
 */
void MainWindow::createSceneButtons(QGraphicsScene* scene)
{
    //button to close the window;
    QPushButton* closeWindow = new QPushButton();
    closeWindow->setText("Close");
    closeWindow->setGeometry(1100,0, 100, 50);
    connect(closeWindow, &QPushButton::released, this, &MainWindow::exitButtons);
    scene->addWidget(closeWindow);

    //button to save current state to a file;
    QPushButton* saveCurrentState = new QPushButton();
    saveCurrentState->setText("Save");
    saveCurrentState->setGeometry(980,0, 100, 50);
    connect(saveCurrentState, &QPushButton::released, this, &MainWindow::ButtonSaveSession_clicked);
    scene->addWidget(saveCurrentState);

    //button to add robot;
    QPushButton* addRobotButton = new QPushButton();
    addRobotButton->setText("Add robot");
    addRobotButton->setGeometry(860,0, 100, 50);
    connect(addRobotButton, &QPushButton::released, this, &MainWindow::AddRobotButton_clicked);
    scene->addWidget(addRobotButton);

    //button to add obstacle;
    QPushButton* addObstacleButton = new QPushButton();
    addObstacleButton->setText("Add obstacle");
    addObstacleButton->setGeometry(740,0, 100, 50);
    connect(addObstacleButton, &QPushButton::released, this, &MainWindow::AddObstacleButton_clicked);
    scene->addWidget(addObstacleButton);

    //button to pause/play;
    this->pausePlayButton = new QPushButton();
    this->pausePlayButton->setText("Play");
    this->pausePlayButton->setGeometry(620, 0, 100, 50);
    connect(this->pausePlayButton, &QPushButton::released, this, &MainWindow::pausePlay);
    scene->addWidget(this->pausePlayButton);

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


/*!
 * \brief Sets the refresh rate of the simulation and calls the drawMap function
 * See also drawMap()
 */
void MainWindow::draw()
{
    this->ticker.setInterval(10);
    this->map->drawMap(this->scene);
    this->sceneView->update();
}


/*!
 * \brief Moves the main window to the center of the screen
 */
void MainWindow::moveWindowToCenter() {
    // Get the screen geometry
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    // Move the top left corner to the correct possition
    int x = (screenGeometry.width() - width()) / 2;
    int y = (screenGeometry.height() - height()) / 2;

    // Move the window to the center
    move(x, y);
}


/*!
 * \brief Sets up the scene for simulation
 */
void MainWindow::on_ButtonSimulate_clicked()
{
    // Load all objects for the session
    SessionManager *manager = SessionManager::getManagerHandle();
    SessionManager::sessionData data = manager->getSessionData();

    //setup scene
    this->resize(1400, 1000); // Set size of the window
    this->moveWindowToCenter();
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
}


/*!
 * \brief Initiates the load session dialog
 */
void MainWindow::on_ButtonLoadSession_clicked()
{
    LoadFileDialog loadfile;
    loadfile.exec();
}


/*!
 * \brief Initiates the save session dialog
 */
void MainWindow::ButtonSaveSession_clicked()
{
    SaveFileDialog savefile;
    savefile.exec();
}
