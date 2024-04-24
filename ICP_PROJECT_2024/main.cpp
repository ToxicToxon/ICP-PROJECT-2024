#include "json_interface.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Json_interface* jsonHandler = new Json_interface("./envObjects.json");
    delete jsonHandler;
    return a.exec();
}
