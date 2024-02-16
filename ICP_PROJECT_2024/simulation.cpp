#include "simulation.h"
#include "ui_simulation.h"

Simulation::Simulation(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Simulation)
{
    ui->setupUi(this);
}

Simulation::~Simulation()
{
    delete ui;
}
