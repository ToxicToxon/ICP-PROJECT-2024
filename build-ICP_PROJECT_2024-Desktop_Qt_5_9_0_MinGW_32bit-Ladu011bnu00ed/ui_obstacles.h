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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_obstacles
{
public:
    QLabel *label;
    QTextEdit *textEdit;
    QLabel *label_2;
    QTextEdit *textEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *obstacles)
    {
        if (obstacles->objectName().isEmpty())
            obstacles->setObjectName(QStringLiteral("obstacles"));
        obstacles->resize(270, 453);
        label = new QLabel(obstacles);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 20, 121, 16));
        textEdit = new QTextEdit(obstacles);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 10, 101, 31));
        label_2 = new QLabel(obstacles);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 60, 101, 16));
        textEdit_2 = new QTextEdit(obstacles);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(20, 50, 101, 31));
        pushButton = new QPushButton(obstacles);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(170, 410, 80, 24));
        pushButton_2 = new QPushButton(obstacles);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 410, 80, 24));

        retranslateUi(obstacles);
        QObject::connect(pushButton_2, SIGNAL(clicked()), obstacles, SLOT(reject()));

        QMetaObject::connectSlotsByName(obstacles);
    } // setupUi

    void retranslateUi(QDialog *obstacles)
    {
        obstacles->setWindowTitle(QApplication::translate("obstacles", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("obstacles", "Number of obstacles", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("obstacles", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("obstacles", "Length", Q_NULLPTR));
        textEdit_2->setHtml(QApplication::translate("obstacles", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("obstacles", "Save", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("obstacles", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class obstacles: public Ui_obstacles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBSTACLES_H
