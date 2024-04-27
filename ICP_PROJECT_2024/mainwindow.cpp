#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "robot_settings.h"
#include "obstacles.h"
#include "json_interface.h"
//#include "simulation.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Robot simulation");
    this->ui->filePath->setPlaceholderText("Path to file for readiong and writing simulation settings. If not set, default path will be used. Can only be set first.");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_4_clicked()
{
    robot_settings robot_settings_dialog;
    robot_settings_dialog.exec();
}


void MainWindow::on_pushButton_5_clicked()
{
    obstacles obstacles_dialog;
    obstacles_dialog.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
   // pushButton_2->hide();
}


void MainWindow::on_set_path_Button_clicked()
{
    QString filePath = this->ui->filePath->toPlainText();
    JsonInterface *handle = JsonInterface::getJsonHandle() ;
    handle->setPath(filePath);
    this->ui->filePath->setReadOnly(true);

    // Indicate change of state via color
    QTextCursor cursor = this->ui->filePath->textCursor();
    QTextCharFormat format;
    format.setForeground(QColor(Qt::gray));
    format.setFontItalic(true);
    cursor.select(QTextCursor::Document);
    cursor.mergeCharFormat(format);
}


void MainWindow::on_Button_simulate_clicked()
{
    QJsonObject objects;
    JsonInterface *handle = JsonInterface::getJsonHandle();
    if (!handle->getJsonObjects(&objects)) {
        return; // Failed to load file
    }

    // TODO: Go Through objects and call a constructor
}

