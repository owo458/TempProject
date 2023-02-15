/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushbtn_intrinsic;
    QPushButton *pushbtn_extrinsic;
    QLabel *LogoImg;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1005, 518);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushbtn_intrinsic = new QPushButton(centralWidget);
        pushbtn_intrinsic->setObjectName(QStringLiteral("pushbtn_intrinsic"));
        pushbtn_intrinsic->setGeometry(QRect(30, 300, 450, 150));
        pushbtn_extrinsic = new QPushButton(centralWidget);
        pushbtn_extrinsic->setObjectName(QStringLiteral("pushbtn_extrinsic"));
        pushbtn_extrinsic->setGeometry(QRect(520, 300, 450, 150));
        LogoImg = new QLabel(centralWidget);
        LogoImg->setObjectName(QStringLiteral("LogoImg"));
        LogoImg->setGeometry(QRect(290, 30, 480, 250));
        LogoImg->setStyleSheet(QStringLiteral(""));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1005, 20));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushbtn_intrinsic->setText(QApplication::translate("MainWindow", "Intrinsic Calibration", 0));
        pushbtn_extrinsic->setText(QApplication::translate("MainWindow", "Extrinsic Calibration", 0));
        LogoImg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
