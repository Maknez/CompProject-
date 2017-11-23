/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QToolButton *toolButton_1;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QToolButton *toolButton_7;
    QToolButton *toolButton_8;
    QToolButton *toolButton_9;
    QToolButton *toolButton_10;
    QToolButton *toolButton_11;
    QToolButton *toolButton_12;
    QToolButton *toolButton_13;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(677, 183);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        toolButton_1 = new QToolButton(centralWidget);
        toolButton_1->setObjectName(QStringLiteral("toolButton_1"));
        toolButton_1->setGeometry(QRect(20, 70, 71, 61));
        toolButton_2 = new QToolButton(centralWidget);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(60, 20, 71, 61));
        toolButton_3 = new QToolButton(centralWidget);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setGeometry(QRect(100, 70, 71, 61));
        toolButton_4 = new QToolButton(centralWidget);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setGeometry(QRect(140, 20, 71, 61));
        toolButton_5 = new QToolButton(centralWidget);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setGeometry(QRect(180, 70, 71, 61));
        toolButton_6 = new QToolButton(centralWidget);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setGeometry(QRect(260, 70, 71, 61));
        toolButton_7 = new QToolButton(centralWidget);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        toolButton_7->setGeometry(QRect(300, 20, 71, 61));
        toolButton_8 = new QToolButton(centralWidget);
        toolButton_8->setObjectName(QStringLiteral("toolButton_8"));
        toolButton_8->setGeometry(QRect(340, 70, 71, 61));
        toolButton_9 = new QToolButton(centralWidget);
        toolButton_9->setObjectName(QStringLiteral("toolButton_9"));
        toolButton_9->setGeometry(QRect(380, 20, 71, 61));
        toolButton_10 = new QToolButton(centralWidget);
        toolButton_10->setObjectName(QStringLiteral("toolButton_10"));
        toolButton_10->setGeometry(QRect(420, 70, 71, 61));
        toolButton_11 = new QToolButton(centralWidget);
        toolButton_11->setObjectName(QStringLiteral("toolButton_11"));
        toolButton_11->setGeometry(QRect(460, 20, 71, 61));
        toolButton_12 = new QToolButton(centralWidget);
        toolButton_12->setObjectName(QStringLiteral("toolButton_12"));
        toolButton_12->setGeometry(QRect(500, 70, 71, 61));
        toolButton_13 = new QToolButton(centralWidget);
        toolButton_13->setObjectName(QStringLiteral("toolButton_13"));
        toolButton_13->setGeometry(QRect(580, 70, 71, 61));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 677, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        toolButton_1->setText(QApplication::translate("MainWindow", "C", Q_NULLPTR));
        toolButton_2->setText(QApplication::translate("MainWindow", "CIS", Q_NULLPTR));
        toolButton_3->setText(QApplication::translate("MainWindow", "D", Q_NULLPTR));
        toolButton_4->setText(QApplication::translate("MainWindow", "DIS", Q_NULLPTR));
        toolButton_5->setText(QApplication::translate("MainWindow", "E", Q_NULLPTR));
        toolButton_6->setText(QApplication::translate("MainWindow", "F", Q_NULLPTR));
        toolButton_7->setText(QApplication::translate("MainWindow", "FIS", Q_NULLPTR));
        toolButton_8->setText(QApplication::translate("MainWindow", "G", Q_NULLPTR));
        toolButton_9->setText(QApplication::translate("MainWindow", "GIS", Q_NULLPTR));
        toolButton_10->setText(QApplication::translate("MainWindow", "A", Q_NULLPTR));
        toolButton_11->setText(QApplication::translate("MainWindow", "AIS", Q_NULLPTR));
        toolButton_12->setText(QApplication::translate("MainWindow", "H", Q_NULLPTR));
        toolButton_13->setText(QApplication::translate("MainWindow", "C", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
