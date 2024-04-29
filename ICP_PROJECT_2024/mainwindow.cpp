#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "robot_settings.h"
#include "obstacles.h"
#include "json_interface.h"
#include "maparea.h"
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
}

void MainWindow::draw()
{
    int i = rand()%100+1;
    this->ticker.setInterval(50);
    qDebug() << "test"; //TODO: use items
    QGraphicsItem* ellipse = this->scene->addEllipse(20+i + this->map->getWidth()/2,20+i + this->map->getHeight()/2,50+i*6,50+i*6);
    this->sceneView->update();
}

void MainWindow::on_Button_simulate_clicked()
{
    QJsonObject objects;
    JsonInterface *handle = JsonInterface::getJsonHandle();
    /*if (!handle->getJsonObjects(&objects))
    {
        return; // Failed to load file
    }*/
    //setup scene
    this->scene = new QGraphicsScene();
    this->scene->setSceneRect(0, 0, 1920, 1080);

    this->sceneView = new QGraphicsView();
    this->map = new MapArea(1920, 1080);
    this->setCentralWidget(this->sceneView);
    this->createSceneButtons(this->scene);
    this->ticker.start();
    this->sceneView->setScene(this->scene);
    QObject::connect(&ticker, &QTimer::timeout, this, &MainWindow::draw);
    delete this->map;

    // TODO: Go Through objects and call a constructor
}


