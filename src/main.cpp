/**
 * @file main.cpp
 * @brief Implementation of the core of the project
 * @author David zatloukal
 * @author Ondřej Beneš
 * @date 20.3.2024
 */

#include "SessionManager.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    SessionManager::getManagerHandle();

    int ret = a.exec();

    SessionManager::deleteManagerHandle();
    return ret;
}
