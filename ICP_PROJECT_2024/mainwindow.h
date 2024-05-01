/**
 * @file mainwindow.h
 * @brief
 * @author David Zatloukal
 * @author Ondřej Beneš
 * @date 17.3.2024
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createSceneButtons(QGraphicsScene* scene);
    void draw();
    QTimer ticker;
    QGraphicsScene* scene;
    QGraphicsView* sceneView;
    MapArea* map;
    QTextEdit *fileSpecifier;


private slots:
    void AddRobotButton_clicked();

    void AddObstacleButton_clicked();

    void on_ButtonSimulate_clicked();

    void exitButtons();

    void on_ButtonLoadSession_clicked();

    void ButtonSaveSession_clicked();

    void turnLeft();

    void turnRight();

    void stop();

    void go();

    void pausePlay();

private:
    Ui::MainWindow *ui;

    QGraphicsView *view;

    void moveWindowToCenter();

    // Pause button
    QPushButton* pausePlayButton;
};
#endif // MAINWINDOW_H
