/**
 * @file main.cpp
 * @brief Implementation of the core of the project.
 * @author David zatloukal
 * @date 20.3.2024
 */

#include "json_interface.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    JsonInterface::getJsonHandle();

    int ret = a.exec();

    JsonInterface::deleteJsonHandler();
    return ret;
}
