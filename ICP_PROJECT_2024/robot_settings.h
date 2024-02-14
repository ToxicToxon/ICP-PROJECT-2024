#ifndef ROBOT_SETTINGS_H
#define ROBOT_SETTINGS_H

#include <QDialog>

namespace Ui {
class robot_settings;
}

class robot_settings : public QDialog
{
    Q_OBJECT

public:
    explicit robot_settings(QWidget *parent = nullptr);
    ~robot_settings();

private:
    Ui::robot_settings *ui;
};

#endif // ROBOT_SETTINGS_H
