/**
 * @file savefiledialog.h
 * @brief Declaration of the save file dialog functions
 * @author Ondřej Beneš
 * @date 30.4.2024
 */

#ifndef SAVEFILEDIALOG_H
#define SAVEFILEDIALOG_H

#include <QDialog>

namespace Ui {
class SaveFileDialog;
}

class SaveFileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SaveFileDialog(QWidget *parent = nullptr);
    ~SaveFileDialog();

private slots:

    void on_saveButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::SaveFileDialog *ui;
};

#endif // SAVEFILEDIALOG_H
