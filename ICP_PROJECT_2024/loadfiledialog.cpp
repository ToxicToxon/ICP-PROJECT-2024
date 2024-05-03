/**
 * @file savefiledialog.cpp
 * @brief Implementation of the load file dialog functions
 * @author Ondřej Beneš
 * @date 30.4.2024
 */

#include "loadfiledialog.h"
#include "ui_loadfiledialog.h"
#include "SessionManager.h"


LoadFileDialog::LoadFileDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoadFileDialog)
{
    ui->setupUi(this);
}


LoadFileDialog::~LoadFileDialog()
{
    delete ui;
}


void LoadFileDialog::on_loadButton_clicked()
{
    SessionManager *manager = SessionManager::getManagerHandle();
    if (manager->loadSessionData(this->ui->filePathText->toPlainText())) {
        this->close();
    }
    this->ui->infoLabel->setText("File couldn't be loaded.");
}


void LoadFileDialog::on_closeButton_clicked()
{
    this->close();
}

