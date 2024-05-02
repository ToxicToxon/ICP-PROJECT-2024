#ifndef LOADFILEDIALOG_H
#define LOADFILEDIALOG_H

#include <QDialog>

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
    void on_loadButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::LoadFileDialog *ui;
};

#endif // LOADFILEDIALOG_H
