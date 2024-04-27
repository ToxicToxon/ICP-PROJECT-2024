#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

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

private slots:
    void on_add_robot_Button_clicked();

    void on_add_obstacle_Button_clicked();

    void on_set_path_Button_clicked();

    void on_Button_simulate_clicked();

    void on_create_file_Button_clicked();

private:
    Ui::MainWindow *ui;

    void updateButtons();
};
#endif // MAINWINDOW_H
