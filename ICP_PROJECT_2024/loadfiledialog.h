#ifndef LOADFILEDIALOG_H
#define LOADFILEDIALOG_H

#include <QDialog>
#include "SessionManager.h"

namespace Ui {
class LoadFileDialog;
}

class LoadFileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoadFileDialog(QWidget *parent = nullptr);
    ~LoadFileDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::LoadFileDialog *ui;
};

#endif // LOADFILEDIALOG_H
