/**
 * @file savefiledialog.cpp
 * @brief Implementation of the load file dialog functions
 * @author Ondřej Beneš
 * @date 30.4.2024
 */

#include "loadfiledialog.h"
#include "ui_loadfiledialog.h"
#include "SessionManager.h"

/*!
 * \brief Instantiates the load file dialog
 * \param parent The parent widget of this dialog
 */
LoadFileDialog::LoadFileDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoadFileDialog)
{
    ui->setupUi(this);
}


/*!
 * \brief Removes the load file dialog instance
 */
LoadFileDialog::~LoadFileDialog()
{
    delete ui;
}


/*!
 * \brief Takes a path to file form the dialog ui, and tries to load the given file
 * Upon failure, informs the user via ui
 */
void LoadFileDialog::on_loadButton_clicked()
{
    SessionManager *manager = SessionManager::getManagerHandle();
    if (manager->loadSessionData(this->ui->filePathText->toPlainText())) {
        this->close();
    }
    this->ui->infoLabel->setText("File couldn't be loaded.");
}


/*!
 * \brief Closes the load file dialog window
 */
void LoadFileDialog::on_closeButton_clicked()
{
    this->close();
}

