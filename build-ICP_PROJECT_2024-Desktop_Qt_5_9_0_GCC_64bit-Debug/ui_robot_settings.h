/********************************************************************************
** Form generated from reading UI file 'robot_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOT_SETTINGS_H
#define UI_ROBOT_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_robot_settings
{
public:
    QTextEdit *textEdit;
    QLineEdit *lineEdit;

    void setupUi(QDialog *robot_settings)
    {
        if (robot_settings->objectName().isEmpty())
            robot_settings->setObjectName(QStringLiteral("robot_settings"));
        robot_settings->resize(295, 729);
        textEdit = new QTextEdit(robot_settings);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(9, 9, 101, 61));
        lineEdit = new QLineEdit(robot_settings);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(120, 20, 141, 31));

        retranslateUi(robot_settings);

        QMetaObject::connectSlotsByName(robot_settings);
    } // setupUi

    void retranslateUi(QDialog *robot_settings)
    {
        robot_settings->setWindowTitle(QApplication::translate("robot_settings", "Dialog", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("robot_settings", "number of robots", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class robot_settings: public Ui_robot_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOT_SETTINGS_H
