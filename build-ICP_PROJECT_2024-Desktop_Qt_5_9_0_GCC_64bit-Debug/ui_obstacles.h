/********************************************************************************
** Form generated from reading UI file 'obstacles.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBSTACLES_H
#define UI_OBSTACLES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_obstacles
{
public:

    void setupUi(QDialog *obstacles)
    {
        if (obstacles->objectName().isEmpty())
            obstacles->setObjectName(QStringLiteral("obstacles"));
        obstacles->resize(400, 300);

        retranslateUi(obstacles);

        QMetaObject::connectSlotsByName(obstacles);
    } // setupUi

    void retranslateUi(QDialog *obstacles)
    {
        obstacles->setWindowTitle(QApplication::translate("obstacles", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class obstacles: public Ui_obstacles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBSTACLES_H
