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
    explicit robots(QWidget *parent = nullptr);
    ~robots();

private slots:
    void on_saveButton_clicked();

private:
    Ui::robots *ui;
};

#endif // ROBOTS_H
