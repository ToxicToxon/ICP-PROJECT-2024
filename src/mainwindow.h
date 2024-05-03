/**
 * @file mainwindow.h
 * @brief Declaration of the MainWindow class
 * @author David Zatloukal
 * @author Ondřej Beneš
 * @date 17.3.2024
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QApplication>
#include <QGuiApplication>
#include "ui_mainwindow.h"
#include "maparea.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Instantiates the MainWindow
     * \param parent The parent widget of this dialog
     */
    MainWindow(QWidget *parent = nullptr);

    /*!
     * \brief Deletes an instance of MainWindow
     */
    ~MainWindow();

    /*!
     * \brief Sets up buttons for the simulation window
     * \param scene Specifies where the bbuttons should be inserted
     */
    void createSceneButtons(QGraphicsScene* scene);

    /*!
     * \brief Sets the refresh rate of the simulation and calls the drawMap function
     */
    void draw();

    QTimer ticker;

    QGraphicsScene* scene;

    QGraphicsView* sceneView;

    MapArea* map;

    QTextEdit *fileSpecifier;


private slots:
    /*!
     * \brief Initiates the robots dialog
     * If any robot is added, it is also loaded into the scene
     */
    void AddRobotButton_clicked();

    /*!
     * \brief Initiates the obstacles dialog
     * If any obstacle is added, it is also loaded into the scene
     */
    void AddObstacleButton_clicked();

    /*!
     * \brief Sets up the scene for simulation
     */
    void on_ButtonSimulate_clicked();

    /*!
     * \brief Closes the window
     */
    void exitButtons();

    /*!
     * \brief Initiates the load session dialog
     */
    void on_ButtonLoadSession_clicked();

    /*!
     * \brief Initiates the save session dialog
     */
    void ButtonSaveSession_clicked();

    /*!
     * \brief Calls the maparea::turnAllUserRobots()
     */
    void turnLeft();

    /*!
     * \brief Calls the maparea::turnAllUserRobots()
     */
    void turnRight();

    /*!
     * \brief Calls the maparea::stopAllUserRobots()
     */
    void stop();

    /*!
     * \brief Calls the maparea::goAllUserRobots()
     */
    void go();

    /*!
     * \brief Calls maparea::pausePlay()
     * Also updates the text of the button
     */
    void pausePlay();

private:
    Ui::MainWindow *ui;

    QGraphicsView *view;

    /*!
     * \brief Moves the main window to the center of the screen
     */
    void moveWindowToCenter();

    // Pause button
    QPushButton* pausePlayButton;
};
#endif // MAINWINDOW_H
