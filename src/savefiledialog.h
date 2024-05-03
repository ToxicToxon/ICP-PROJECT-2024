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
    /*!
     * \brief Instantiates the save file dialog
     * \param parent The parent widget of this dialog
     */
    explicit SaveFileDialog(QWidget *parent = nullptr);

    /*!
     * \brief Deletes the save file dialog instance
     */
    ~SaveFileDialog();

private slots:

    /*!
     * \brief Saves the session data to file using SessionManager
     */
    void on_saveButton_clicked();

    /*!
     * \brief Closes the save file dialog
     */
    void on_closeButton_clicked();

private:
    Ui::SaveFileDialog *ui;
};

#endif // SAVEFILEDIALOG_H
