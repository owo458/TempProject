/********************************************************************************
** Form generated from reading UI file 'parameterinput.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETERINPUT_H
#define UI_PARAMETERINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParameterInput
{
public:
    QPushButton *pushbtn_prev_mesure;
    QPushButton *pushbtn_next_mesure;
    QLabel *PointImg;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLineEdit *lineEdit_CarWidth;
    QLineEdit *lineEdit_CameraToBumper;
    QLineEdit *lineEdit_CarToChessboard_1;
    QLineEdit *lineEdit_CarToChessboard_2;
    QLineEdit *lineEdit_ChessboardSizeX;
    QPushButton *pushButton;
    QLineEdit *lineEdit_CameraInstallPosition;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *lineEdit_CarHeight;
    QLabel *label_8;
    QLineEdit *lineEdit_ChessboardSizeY;
    QLabel *label_3;
    QLineEdit *lineEdit_ChessboardCellSize;
    QLabel *label_6;
    QLabel *label_9;
    QLineEdit *lineEdit_FileName;
    QPushButton *pushButton_2;
    QLabel *label_7;

    void setupUi(QWidget *ParameterInput)
    {
        if (ParameterInput->objectName().isEmpty())
            ParameterInput->setObjectName(QStringLiteral("ParameterInput"));
        ParameterInput->resize(1000, 519);
        pushbtn_prev_mesure = new QPushButton(ParameterInput);
        pushbtn_prev_mesure->setObjectName(QStringLiteral("pushbtn_prev_mesure"));
        pushbtn_prev_mesure->setGeometry(QRect(30, 300, 450, 150));
        pushbtn_next_mesure = new QPushButton(ParameterInput);
        pushbtn_next_mesure->setObjectName(QStringLiteral("pushbtn_next_mesure"));
        pushbtn_next_mesure->setGeometry(QRect(520, 300, 450, 150));
        PointImg = new QLabel(ParameterInput);
        PointImg->setObjectName(QStringLiteral("PointImg"));
        PointImg->setGeometry(QRect(510, 10, 480, 250));
        PointImg->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        layoutWidget = new QWidget(ParameterInput);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 10, 471, 257));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 7, 0, 1, 1);

        lineEdit_CarWidth = new QLineEdit(layoutWidget);
        lineEdit_CarWidth->setObjectName(QStringLiteral("lineEdit_CarWidth"));
        lineEdit_CarWidth->setPlaceholderText(QStringLiteral("Wheel to wheel (m)"));
        lineEdit_CarWidth->setClearButtonEnabled(false);

        gridLayout->addWidget(lineEdit_CarWidth, 0, 1, 1, 2);

        lineEdit_CameraToBumper = new QLineEdit(layoutWidget);
        lineEdit_CameraToBumper->setObjectName(QStringLiteral("lineEdit_CameraToBumper"));
        lineEdit_CameraToBumper->setPlaceholderText(QStringLiteral("Cam to bumper (m)"));

        gridLayout->addWidget(lineEdit_CameraToBumper, 2, 1, 1, 2);

        lineEdit_CarToChessboard_1 = new QLineEdit(layoutWidget);
        lineEdit_CarToChessboard_1->setObjectName(QStringLiteral("lineEdit_CarToChessboard_1"));
        lineEdit_CarToChessboard_1->setPlaceholderText(QStringLiteral("Cam to target_1 (m)"));

        gridLayout->addWidget(lineEdit_CarToChessboard_1, 8, 1, 1, 1);

        lineEdit_CarToChessboard_2 = new QLineEdit(layoutWidget);
        lineEdit_CarToChessboard_2->setObjectName(QStringLiteral("lineEdit_CarToChessboard_2"));
        lineEdit_CarToChessboard_2->setPlaceholderText(QStringLiteral("Cam to target_2(m)"));

        gridLayout->addWidget(lineEdit_CarToChessboard_2, 8, 2, 1, 1);

        lineEdit_ChessboardSizeX = new QLineEdit(layoutWidget);
        lineEdit_ChessboardSizeX->setObjectName(QStringLiteral("lineEdit_ChessboardSizeX"));
        lineEdit_ChessboardSizeX->setPlaceholderText(QStringLiteral("X"));

        gridLayout->addWidget(lineEdit_ChessboardSizeX, 7, 1, 1, 1);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 3, 2, 1, 1);

        lineEdit_CameraInstallPosition = new QLineEdit(layoutWidget);
        lineEdit_CameraInstallPosition->setObjectName(QStringLiteral("lineEdit_CameraInstallPosition"));
        lineEdit_CameraInstallPosition->setPlaceholderText(QStringLiteral("Position (mm)"));

        gridLayout->addWidget(lineEdit_CameraInstallPosition, 3, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 6, 0, 1, 1);

        lineEdit_CarHeight = new QLineEdit(layoutWidget);
        lineEdit_CarHeight->setObjectName(QStringLiteral("lineEdit_CarHeight"));
        lineEdit_CarHeight->setPlaceholderText(QStringLiteral("Bottom to top (m)"));

        gridLayout->addWidget(lineEdit_CarHeight, 1, 1, 1, 2);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 8, 0, 1, 1);

        lineEdit_ChessboardSizeY = new QLineEdit(layoutWidget);
        lineEdit_ChessboardSizeY->setObjectName(QStringLiteral("lineEdit_ChessboardSizeY"));
        lineEdit_ChessboardSizeY->setPlaceholderText(QStringLiteral("Y"));

        gridLayout->addWidget(lineEdit_ChessboardSizeY, 7, 2, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_ChessboardCellSize = new QLineEdit(layoutWidget);
        lineEdit_ChessboardCellSize->setObjectName(QStringLiteral("lineEdit_ChessboardCellSize"));
        lineEdit_ChessboardCellSize->setPlaceholderText(QStringLiteral("Cell size (mm)"));

        gridLayout->addWidget(lineEdit_ChessboardCellSize, 6, 1, 1, 2);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 0, 0, 1, 1);

        lineEdit_FileName = new QLineEdit(layoutWidget);
        lineEdit_FileName->setObjectName(QStringLiteral("lineEdit_FileName"));
        lineEdit_FileName->setMinimumSize(QSize(119, 23));
        lineEdit_FileName->setPlaceholderText(QStringLiteral("Txt path"));

        gridLayout->addWidget(lineEdit_FileName, 5, 1, 1, 2);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 4, 1, 1, 2);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 4, 0, 2, 1);

        QWidget::setTabOrder(lineEdit_CarWidth, lineEdit_CarHeight);
        QWidget::setTabOrder(lineEdit_CarHeight, lineEdit_CameraToBumper);
        QWidget::setTabOrder(lineEdit_CameraToBumper, lineEdit_CameraInstallPosition);
        QWidget::setTabOrder(lineEdit_CameraInstallPosition, lineEdit_ChessboardCellSize);
        QWidget::setTabOrder(lineEdit_ChessboardCellSize, lineEdit_ChessboardSizeX);
        QWidget::setTabOrder(lineEdit_ChessboardSizeX, lineEdit_ChessboardSizeY);
        QWidget::setTabOrder(lineEdit_ChessboardSizeY, lineEdit_CarToChessboard_1);
        QWidget::setTabOrder(lineEdit_CarToChessboard_1, lineEdit_CarToChessboard_2);
        QWidget::setTabOrder(lineEdit_CarToChessboard_2, pushbtn_prev_mesure);
        QWidget::setTabOrder(pushbtn_prev_mesure, pushbtn_next_mesure);
        QWidget::setTabOrder(pushbtn_next_mesure, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_2);

        retranslateUi(ParameterInput);

        QMetaObject::connectSlotsByName(ParameterInput);
    } // setupUi

    void retranslateUi(QWidget *ParameterInput)
    {
        ParameterInput->setWindowTitle(QApplication::translate("ParameterInput", "ParameterInput", 0));
        pushbtn_prev_mesure->setText(QApplication::translate("ParameterInput", "< Prev", 0));
        pushbtn_next_mesure->setText(QApplication::translate("ParameterInput", "Next >", 0));
        PointImg->setText(QString());
        label_5->setText(QApplication::translate("ParameterInput", "Chessboard Size", 0));
        lineEdit_CarWidth->setText(QString());
        lineEdit_CameraToBumper->setText(QString());
        lineEdit_CarToChessboard_1->setText(QString());
        lineEdit_CarToChessboard_2->setText(QString());
        lineEdit_ChessboardSizeX->setText(QString());
        pushButton->setText(QApplication::translate("ParameterInput", "Description", 0));
        lineEdit_CameraInstallPosition->setText(QString());
        label_2->setText(QApplication::translate("ParameterInput", "Camera Height                      (m)", 0));
        label_4->setText(QApplication::translate("ParameterInput", "Chessboard Cell Size          (mm)", 0));
        lineEdit_CarHeight->setText(QString());
        label_8->setText(QApplication::translate("ParameterInput", "Chessboard Distance            (m)", 0));
        lineEdit_ChessboardSizeY->setText(QString());
        label_3->setText(QApplication::translate("ParameterInput", "Camera to bumper                (m)", 0));
        lineEdit_ChessboardCellSize->setText(QString());
        label_6->setText(QApplication::translate("ParameterInput", "Camera Install Position       (mm)", 0));
        label_9->setText(QApplication::translate("ParameterInput", "Car width                               (m)", 0));
#ifndef QT_NO_TOOLTIP
        lineEdit_FileName->setToolTip(QApplication::translate("ParameterInput", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        lineEdit_FileName->setText(QString());
        pushButton_2->setText(QApplication::translate("ParameterInput", "Load", 0));
        label_7->setText(QApplication::translate("ParameterInput", "Instrinsic Parameter", 0));
    } // retranslateUi

};

namespace Ui {
    class ParameterInput: public Ui_ParameterInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETERINPUT_H
