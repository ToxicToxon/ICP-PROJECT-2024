#include "loadfiledialog.h"
#include "ui_loadfiledialog.h"

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

void LoadFileDialog::on_pushButton_clicked()
{
    SessionManager *manager = SessionManager::getManagerHandle();
    if (manager->loadSessionData(this->ui->filePathText->toPlainText())) {
        this->close();
    }
    this->ui->infoLabel->setText("File couldn't be loaded.");
}


void LoadFileDialog::on_pushButton_2_clicked()
{
    this->close();
}

