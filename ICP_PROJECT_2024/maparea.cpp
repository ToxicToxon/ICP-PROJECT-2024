#include "maparea.h"


MapArea::MapArea(size_t width, size_t height)
{
    this->width = width;
    this->height = height;
}

void MapArea::drawMap()
{
    //foreach cycle through each robot and obstacle, draw them, clear scene with every frame
    /*this->window->setCentralWidget(this->view);
    this->view->setScene(this->scene);
    this->ticker.start(30);
    this->scene->addEllipse(20 + this->width/2,20 + this->height/2,50*6,50*6);
    this->view->show();
    QObject::connect(&ticker, &QTimer::timeout, this, &MapArea::drawTick); //this no workie*/
}

size_t MapArea::getWidth()
{
    return this->width;
}

size_t MapArea::getHeight()
{
    return this->height;
}


MapArea::~MapArea()
{}
