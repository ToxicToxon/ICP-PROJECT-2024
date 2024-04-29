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

    void on_set_path_Button_clicked();

    void on_Button_simulate_clicked();

    void on_create_file_Button_clicked();

    void exitButtons();

private:
    Ui::MainWindow *ui;

    QGraphicsView *view;

    void updateButtons();
};
#endif // MAINWINDOW_H
