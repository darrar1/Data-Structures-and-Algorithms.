/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *quoteLabel;
    QPushButton *AnswerButton;
    QListWidget *listWidget;
    QPushButton *ForwardButton;
    QPushButton *HandleButton;
    QListWidget *IncomingCall;
    QLabel *label;
    QLabel *label_2;
    QPushButton *clearAllDoneButton;
    QPushButton *clearAllCancelButton;
    QPushButton *HandleButton2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(774, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        quoteLabel = new QLabel(centralwidget);
        quoteLabel->setObjectName("quoteLabel");
        quoteLabel->setGeometry(QRect(220, 470, 331, 91));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        quoteLabel->setFont(font);
        quoteLabel->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        quoteLabel->setWordWrap(true);
        AnswerButton = new QPushButton(centralwidget);
        AnswerButton->setObjectName("AnswerButton");
        AnswerButton->setGeometry(QRect(80, 350, 101, 51));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(390, 120, 371, 211));
        ForwardButton = new QPushButton(centralwidget);
        ForwardButton->setObjectName("ForwardButton");
        ForwardButton->setGeometry(QRect(210, 350, 101, 51));
        HandleButton = new QPushButton(centralwidget);
        HandleButton->setObjectName("HandleButton");
        HandleButton->setGeometry(QRect(460, 340, 101, 51));
        IncomingCall = new QListWidget(centralwidget);
        IncomingCall->setObjectName("IncomingCall");
        IncomingCall->setGeometry(QRect(10, 120, 371, 211));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 80, 291, 41));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        label->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(420, 70, 291, 41));
        label_2->setFont(font1);
        clearAllDoneButton = new QPushButton(centralwidget);
        clearAllDoneButton->setObjectName("clearAllDoneButton");
        clearAllDoneButton->setGeometry(QRect(410, 400, 151, 51));
        clearAllCancelButton = new QPushButton(centralwidget);
        clearAllCancelButton->setObjectName("clearAllCancelButton");
        clearAllCancelButton->setGeometry(QRect(590, 400, 151, 51));
        HandleButton2 = new QPushButton(centralwidget);
        HandleButton2->setObjectName("HandleButton2");
        HandleButton2->setGeometry(QRect(590, 340, 101, 51));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        quoteLabel->setText(QCoreApplication::translate("MainWindow", "QUOTE HERE", nullptr));
        AnswerButton->setText(QCoreApplication::translate("MainWindow", "Answer", nullptr));
        ForwardButton->setText(QCoreApplication::translate("MainWindow", "Forward", nullptr));
        HandleButton->setText(QCoreApplication::translate("MainWindow", "Mark as done", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Pending Calls:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "History Log:", nullptr));
        clearAllDoneButton->setText(QCoreApplication::translate("MainWindow", "Clear all done status", nullptr));
        clearAllCancelButton->setText(QCoreApplication::translate("MainWindow", "Clear all cancelled status", nullptr));
        HandleButton2->setText(QCoreApplication::translate("MainWindow", "Mark as cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
