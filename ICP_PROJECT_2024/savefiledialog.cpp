#include "savefiledialog.h"
#include "SessionManager.h"
#include "ui_savefiledialog.h"


/*!
 * \brief Instantiates the save file dialog
 * \param parent Specifies which widget to inherit from
 */
SaveFileDialog::SaveFileDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SaveFileDialog)
{
    ui->setupUi(this);
}


/*!
 * \brief Deletes the save file dialog instance
 */
SaveFileDialog::~SaveFileDialog()
{
    delete ui;
}


/*!
 * \brief Saves the session data to file using SessionManager
 */
void SaveFileDialog::on_saveButton_clicked()
{
    static bool overwrite = false;
    SessionManager *manager = SessionManager::getManagerHandle();
    int rv = manager->saveSession(this->ui->filePathText->toPlainText(), overwrite);
    if (rv == -1) {
        this->ui->infoLabel->setText("Failed to save session.");
    } else if (rv == 1) {
        this->ui->infoLabel->setText("File already exists.\nDo you want to overwrite it?");
        overwrite = true;
    } else {
        overwrite = false;
        this->close();
    }
}


/*!
 * \brief Closes the save file dialog
 */
void SaveFileDialog::on_closeButton_clicked()
{
    this->close();
}

