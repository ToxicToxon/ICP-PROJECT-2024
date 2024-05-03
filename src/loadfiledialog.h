/**
 * @file loadfiledialog.h
 * @brief Declaration of the load file dialog functions
 * @author Ondřej Beneš
 * @date 30.4.2024
 */

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

    /*!
     * \brief Instantiates the load file dialog
     * \param parent The parent widget of this dialog
     */
    explicit LoadFileDialog(QWidget *parent = nullptr);

    /*!
     * \brief Removes the load file dialog instance
     */
    ~LoadFileDialog();

private slots:
    /*!
     * \brief Takes a path to file form the dialog ui, and tries to load the given file
     * Upon failure, informs the user via ui
     */
    void on_loadButton_clicked();

    /*!
     * \brief Closes the load file dialog window
     */
    void on_closeButton_clicked();

private:
    Ui::LoadFileDialog *ui;
};

#endif // LOADFILEDIALOG_H
