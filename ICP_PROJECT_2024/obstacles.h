/**
 * @file obstacles.h
 * @brief Declaration of the obstacles dialog functions
 * @author David Zatloukal
 * @author Ondřej Beneš
 * @date 28.4.2024
 */

#ifndef OBSTACLES_H
#define OBSTACLES_H

#include <QDialog>

namespace Ui {
class obstacles;
}

class obstacles : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Instantiates obstacles dialog
     * \param parent The parent widget of this dialog
     */
    explicit obstacles(QWidget *parent = nullptr);

    /*!
     * \brief Removes an instance of obstacles
     */
    ~obstacles();

private slots:
    /*!
     * \brief Saves data from obstacles form to SessionManager if the data is valid
     * Upon receiving invalid values, informs the user and waits for new data, otherwise clears the form and waits for next input
     */
    void on_saveButton_clicked();

private:
    Ui::obstacles *ui;
};

#endif // OBSTACLES_H
