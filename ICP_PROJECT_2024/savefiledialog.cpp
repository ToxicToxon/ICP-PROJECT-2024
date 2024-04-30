#include "savefiledialog.h"
#include "SessionManager.h"
#include "ui_savefiledialog.h"

SaveFileDialog::SaveFileDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SaveFileDialog)
{
    ui->setupUi(this);
}

SaveFileDialog::~SaveFileDialog()
{
    delete ui;
}

void SaveFileDialog::on_pushButton_clicked()
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

void SaveFileDialog::on_pushButton_2_clicked()
{
    this->close();
}

