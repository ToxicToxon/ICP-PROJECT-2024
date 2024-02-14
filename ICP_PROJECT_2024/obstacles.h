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

private:
    Ui::obstacles *ui;
};

#endif // OBSTACLES_H
