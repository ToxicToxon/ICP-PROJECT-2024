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

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SaveFileDialog *ui;
};

#endif // SAVEFILEDIALOG_H