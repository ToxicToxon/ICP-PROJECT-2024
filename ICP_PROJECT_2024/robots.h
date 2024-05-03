/**
 * @file robots.h
 * @brief Declaration of the robots dialog functions
 * @author David Zatloukal
 * @author Ondřej Beneš
 * @date 28.4.2024
 */

#ifndef ROBOTS_H
#define ROBOTS_H

#include <QDialog>

namespace Ui {
class robots;
}

class robots : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Instantiates the robots dialog
     * \param parent The parent widget of this dialog
     */
    explicit robots(QWidget *parent = nullptr);

    /*!
     * \brief Removes an instance of the robots dialog
     */
    ~robots();

private slots:
    /*!
     * \brief Saves data from robots dialog to SessionManager if the data is valid
     * Upon receiving invalid values, informs the user via interface
     */
    void on_saveButton_clicked();

private:
    Ui::robots *ui;
};

#endif // ROBOTS_H
