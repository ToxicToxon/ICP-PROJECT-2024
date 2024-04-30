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


private slots:
    void on_add_robot_Button_clicked();

    void on_add_obstacle_Button_clicked();

    void on_ButtonSimulate_clicked();

    void exitButtons();

    void on_ButtonLoadSession_clicked();

    void on_ButtonSaveSession_clicked();

private:
    Ui::MainWindow *ui;

    QGraphicsView *view;
};
#endif // MAINWINDOW_H
