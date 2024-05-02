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
    explicit obstacles(QWidget *parent = nullptr);
    ~obstacles();

private slots:
    void on_saveButton_clicked();

private:
    Ui::obstacles *ui;
};

#endif // OBSTACLES_H
