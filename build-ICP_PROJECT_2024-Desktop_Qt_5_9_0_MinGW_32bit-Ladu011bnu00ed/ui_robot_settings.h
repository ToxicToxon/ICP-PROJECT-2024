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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_robot_settings
{
public:
    QTextEdit *textEdit;
    QLabel *label;
    QTextEdit *textEdit_2;
    QLabel *label_2;
    QTextEdit *textEdit_3;
    QLabel *label_3;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_5;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton;
    QCheckBox *checkBox;
    QPushButton *pushButton_2;
    QLabel *label_6;
    QTextEdit *textEdit_6;

    void setupUi(QDialog *robot_settings)
    {
        if (robot_settings->objectName().isEmpty())
            robot_settings->setObjectName(QStringLiteral("robot_settings"));
        robot_settings->resize(295, 297);
        textEdit = new QTextEdit(robot_settings);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 20, 101, 31));
        label = new QLabel(robot_settings);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 30, 101, 16));
        textEdit_2 = new QTextEdit(robot_settings);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(10, 70, 101, 31));
        label_2 = new QLabel(robot_settings);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 80, 81, 16));
        textEdit_3 = new QTextEdit(robot_settings);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(10, 120, 101, 31));
        label_3 = new QLabel(robot_settings);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(130, 130, 161, 16));
        textEdit_4 = new QTextEdit(robot_settings);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(10, 170, 51, 31));
        textEdit_5 = new QTextEdit(robot_settings);
        textEdit_5->setObjectName(QStringLiteral("textEdit_5"));
        textEdit_5->setGeometry(QRect(60, 170, 51, 31));
        label_4 = new QLabel(robot_settings);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(130, 180, 121, 16));
        label_5 = new QLabel(robot_settings);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(130, 150, 71, 16));
        pushButton = new QPushButton(robot_settings);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 250, 80, 24));
        checkBox = new QCheckBox(robot_settings);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(10, 210, 78, 22));
        pushButton_2 = new QPushButton(robot_settings);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 250, 80, 24));
        label_6 = new QLabel(robot_settings);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(230, 150, 101, 16));
        textEdit_6 = new QTextEdit(robot_settings);
        textEdit_6->setObjectName(QStringLiteral("textEdit_6"));
        textEdit_6->setGeometry(QRect(110, 140, 101, 31));

        retranslateUi(robot_settings);
        QObject::connect(pushButton_2, SIGNAL(clicked()), robot_settings, SLOT(reject()));

        QMetaObject::connectSlotsByName(robot_settings);
    } // setupUi

    void retranslateUi(QDialog *robot_settings)
    {
        robot_settings->setWindowTitle(QApplication::translate("robot_settings", "Dialog", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("robot_settings", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("robot_settings", "Number of robots", Q_NULLPTR));
        textEdit_2->setHtml(QApplication::translate("robot_settings", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("robot_settings", "Starting angle", Q_NULLPTR));
        textEdit_3->setHtml(QApplication::translate("robot_settings", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("robot_settings", "Diameter of the robots (0,360)", Q_NULLPTR));
        textEdit_4->setHtml(QApplication::translate("robot_settings", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        textEdit_5->setHtml(QApplication::translate("robot_settings", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("robot_settings", "Starting position X|Y", Q_NULLPTR));
        label_5->setText(QApplication::translate("robot_settings", "Default is 0", Q_NULLPTR));
        pushButton->setText(QApplication::translate("robot_settings", "Save", Q_NULLPTR));
        checkBox->setText(QApplication::translate("robot_settings", "Random", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("robot_settings", "Cancel", Q_NULLPTR));
        label_6->setText(QApplication::translate("robot_settings", "Number of robots", Q_NULLPTR));
        textEdit_6->setHtml(QApplication::translate("robot_settings", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class robot_settings: public Ui_robot_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOT_SETTINGS_H
