/********************************************************************************
** Form generated from reading UI file 'CameraPossestimation.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERAPOSSESTIMATION_H
#define UI_CAMERAPOSSESTIMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mesurement_height
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_image;

    void setupUi(QWidget *mesurement_height)
    {
        if (mesurement_height->objectName().isEmpty())
            mesurement_height->setObjectName(QStringLiteral("mesurement_height"));
        mesurement_height->resize(1000, 710);
        pushButton = new QPushButton(mesurement_height);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 550, 450, 130));
        pushButton_2 = new QPushButton(mesurement_height);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(510, 550, 450, 130));
        label_image = new QLabel(mesurement_height);
        label_image->setObjectName(QStringLiteral("label_image"));
        label_image->setGeometry(QRect(20, 10, 960, 512));
        label_image->raise();
        pushButton->raise();
        pushButton_2->raise();

        retranslateUi(mesurement_height);

        QMetaObject::connectSlotsByName(mesurement_height);
    } // setupUi

    void retranslateUi(QWidget *mesurement_height)
    {
        mesurement_height->setWindowTitle(QApplication::translate("mesurement_height", "Form", 0));
        pushButton->setText(QApplication::translate("mesurement_height", "< Prev", 0));
        pushButton_2->setText(QApplication::translate("mesurement_height", "Next >", 0));
        label_image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mesurement_height: public Ui_mesurement_height {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAPOSSESTIMATION_H
