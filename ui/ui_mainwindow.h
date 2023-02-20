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
    QLabel *label;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 550);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushbtn_intrinsic = new QPushButton(centralWidget);
        pushbtn_intrinsic->setObjectName(QStringLiteral("pushbtn_intrinsic"));
        pushbtn_intrinsic->setGeometry(QRect(30, 450, 450, 70));
        pushbtn_extrinsic = new QPushButton(centralWidget);
        pushbtn_extrinsic->setObjectName(QStringLiteral("pushbtn_extrinsic"));
        pushbtn_extrinsic->setGeometry(QRect(520, 450, 450, 70));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 60, 871, 341));
        label->setStyleSheet(QLatin1String("\n"
"image: url(:/image/image/Logo.png);"));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushbtn_intrinsic->setText(QApplication::translate("MainWindow", "Intrinsic Calibration", 0));
        pushbtn_extrinsic->setText(QApplication::translate("MainWindow", "Extrinsic Calibration", 0));
#ifndef QT_NO_WHATSTHIS
        label->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/image/image/Logo.png\"/></p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
