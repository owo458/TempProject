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
#include <QtWidgets/QFrame>
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
    QPushButton *pushButton_Prev;
    QPushButton *pushButton_Next;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QPushButton *pushButton_ChessboardPointSizeDescription;
    QFrame *line_7;
    QLineEdit *lineEdit_ChessboardCellSize;
    QLabel *label_9;
    QLineEdit *lineEdit_FileName;
    QPushButton *pushButton_Load;
    QLabel *label_7;
    QLineEdit *lineEdit_CarWidth;
    QLineEdit *lineEdit_CameraToBumper;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *lineEdit_CarHeight;
    QLabel *label_3;
    QLabel *label_10;
    QLineEdit *lineEdit_CameraNumber;
    QFrame *line_4;
    QLabel *label_6;
    QFrame *line_3;
    QPushButton *pushButton_CameraInstallDescription;
    QLineEdit *lineEdit_CameraInstallPosition;
    QFrame *line_2;
    QFrame *line_6;
    QFrame *line;
    QFrame *line_5;
    QLabel *label_8;
    QLineEdit *lineEdit_CarToChessboard_1;
    QLineEdit *lineEdit_CarToChessboard_2;
    QLineEdit *lineEdit_ChessboardSizeX;
    QLineEdit *lineEdit_ChessboardSizeY;
    QFrame *line_8;
    QLabel *Background;
    QLabel *image_1;
    QLabel *image_2;

    void setupUi(QWidget *ParameterInput)
    {
        if (ParameterInput->objectName().isEmpty())
            ParameterInput->setObjectName(QStringLiteral("ParameterInput"));
        ParameterInput->resize(1000, 550);
        pushButton_Prev = new QPushButton(ParameterInput);
        pushButton_Prev->setObjectName(QStringLiteral("pushButton_Prev"));
        pushButton_Prev->setGeometry(QRect(30, 450, 450, 70));
        pushButton_Next = new QPushButton(ParameterInput);
        pushButton_Next->setObjectName(QStringLiteral("pushButton_Next"));
        pushButton_Next->setGeometry(QRect(520, 450, 450, 70));
        layoutWidget = new QWidget(ParameterInput);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 10, 451, 421));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 14, 0, 2, 1);

        pushButton_ChessboardPointSizeDescription = new QPushButton(layoutWidget);
        pushButton_ChessboardPointSizeDescription->setObjectName(QStringLiteral("pushButton_ChessboardPointSizeDescription"));

        gridLayout->addWidget(pushButton_ChessboardPointSizeDescription, 14, 1, 1, 2);

        line_7 = new QFrame(layoutWidget);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_7, 3, 0, 1, 3);

        lineEdit_ChessboardCellSize = new QLineEdit(layoutWidget);
        lineEdit_ChessboardCellSize->setObjectName(QStringLiteral("lineEdit_ChessboardCellSize"));
        lineEdit_ChessboardCellSize->setPlaceholderText(QStringLiteral("Cell size (mm)"));

        gridLayout->addWidget(lineEdit_ChessboardCellSize, 12, 1, 1, 2);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 0, 0, 1, 1);

        lineEdit_FileName = new QLineEdit(layoutWidget);
        lineEdit_FileName->setObjectName(QStringLiteral("lineEdit_FileName"));
        lineEdit_FileName->setMinimumSize(QSize(119, 23));
        lineEdit_FileName->setPlaceholderText(QStringLiteral("Text file path"));

        gridLayout->addWidget(lineEdit_FileName, 10, 1, 1, 2);

        pushButton_Load = new QPushButton(layoutWidget);
        pushButton_Load->setObjectName(QStringLiteral("pushButton_Load"));

        gridLayout->addWidget(pushButton_Load, 9, 1, 1, 2);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 9, 0, 2, 1);

        lineEdit_CarWidth = new QLineEdit(layoutWidget);
        lineEdit_CarWidth->setObjectName(QStringLiteral("lineEdit_CarWidth"));
        lineEdit_CarWidth->setPlaceholderText(QStringLiteral("Wheel to wheel (m)"));
        lineEdit_CarWidth->setClearButtonEnabled(false);

        gridLayout->addWidget(lineEdit_CarWidth, 0, 1, 1, 2);

        lineEdit_CameraToBumper = new QLineEdit(layoutWidget);
        lineEdit_CameraToBumper->setObjectName(QStringLiteral("lineEdit_CameraToBumper"));
        lineEdit_CameraToBumper->setPlaceholderText(QStringLiteral("Cam to bumper (m)"));

        gridLayout->addWidget(lineEdit_CameraToBumper, 4, 1, 1, 2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 12, 0, 1, 1);

        lineEdit_CarHeight = new QLineEdit(layoutWidget);
        lineEdit_CarHeight->setObjectName(QStringLiteral("lineEdit_CarHeight"));
        lineEdit_CarHeight->setPlaceholderText(QStringLiteral("Bottom to top (m)"));

        gridLayout->addWidget(lineEdit_CarHeight, 2, 1, 1, 2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 19, 0, 1, 1);

        lineEdit_CameraNumber = new QLineEdit(layoutWidget);
        lineEdit_CameraNumber->setObjectName(QStringLiteral("lineEdit_CameraNumber"));
        lineEdit_CameraNumber->setPlaceholderText(QStringLiteral("default(0)"));

        gridLayout->addWidget(lineEdit_CameraNumber, 19, 1, 1, 2);

        line_4 = new QFrame(layoutWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 13, 0, 1, 3);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 6, 0, 2, 1);

        line_3 = new QFrame(layoutWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 11, 0, 1, 3);

        pushButton_CameraInstallDescription = new QPushButton(layoutWidget);
        pushButton_CameraInstallDescription->setObjectName(QStringLiteral("pushButton_CameraInstallDescription"));

        gridLayout->addWidget(pushButton_CameraInstallDescription, 6, 1, 1, 2);

        lineEdit_CameraInstallPosition = new QLineEdit(layoutWidget);
        lineEdit_CameraInstallPosition->setObjectName(QStringLiteral("lineEdit_CameraInstallPosition"));
        lineEdit_CameraInstallPosition->setPlaceholderText(QStringLiteral("Position (mm)"));

        gridLayout->addWidget(lineEdit_CameraInstallPosition, 7, 1, 1, 2);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 8, 0, 1, 3);

        line_6 = new QFrame(layoutWidget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_6, 18, 0, 1, 3);

        line = new QFrame(layoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 5, 0, 1, 3);

        line_5 = new QFrame(layoutWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_5, 16, 0, 1, 3);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 17, 0, 1, 1);

        lineEdit_CarToChessboard_1 = new QLineEdit(layoutWidget);
        lineEdit_CarToChessboard_1->setObjectName(QStringLiteral("lineEdit_CarToChessboard_1"));
        lineEdit_CarToChessboard_1->setPlaceholderText(QStringLiteral("Cam to target_1(m)"));

        gridLayout->addWidget(lineEdit_CarToChessboard_1, 17, 1, 1, 1);

        lineEdit_CarToChessboard_2 = new QLineEdit(layoutWidget);
        lineEdit_CarToChessboard_2->setObjectName(QStringLiteral("lineEdit_CarToChessboard_2"));
        lineEdit_CarToChessboard_2->setPlaceholderText(QStringLiteral("Cam to target_2(m)"));

        gridLayout->addWidget(lineEdit_CarToChessboard_2, 17, 2, 1, 1);

        lineEdit_ChessboardSizeX = new QLineEdit(layoutWidget);
        lineEdit_ChessboardSizeX->setObjectName(QStringLiteral("lineEdit_ChessboardSizeX"));
        lineEdit_ChessboardSizeX->setPlaceholderText(QStringLiteral("X"));

        gridLayout->addWidget(lineEdit_ChessboardSizeX, 15, 1, 1, 1);

        lineEdit_ChessboardSizeY = new QLineEdit(layoutWidget);
        lineEdit_ChessboardSizeY->setObjectName(QStringLiteral("lineEdit_ChessboardSizeY"));
        lineEdit_ChessboardSizeY->setPlaceholderText(QStringLiteral("Y"));

        gridLayout->addWidget(lineEdit_ChessboardSizeY, 15, 2, 1, 1);

        line_8 = new QFrame(layoutWidget);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_8, 1, 0, 1, 3);

        Background = new QLabel(ParameterInput);
        Background->setObjectName(QStringLiteral("Background"));
        Background->setGeometry(QRect(19, 9, 951, 431));
        Background->setStyleSheet(QStringLiteral("background-color: rgb(239, 235, 231);"));
        image_1 = new QLabel(ParameterInput);
        image_1->setObjectName(QStringLiteral("image_1"));
        image_1->setEnabled(true);
        image_1->setGeometry(QRect(520, 20, 450, 240));
        image_1->setStyleSheet(QStringLiteral(""));
        image_2 = new QLabel(ParameterInput);
        image_2->setObjectName(QStringLiteral("image_2"));
        image_2->setGeometry(QRect(520, 269, 450, 173));
        image_2->setStyleSheet(QStringLiteral(""));
        Background->raise();
        pushButton_Prev->raise();
        pushButton_Next->raise();
        layoutWidget->raise();
        image_1->raise();
        image_2->raise();
        QWidget::setTabOrder(lineEdit_CarWidth, lineEdit_CarHeight);
        QWidget::setTabOrder(lineEdit_CarHeight, lineEdit_CameraToBumper);
        QWidget::setTabOrder(lineEdit_CameraToBumper, lineEdit_ChessboardCellSize);
        QWidget::setTabOrder(lineEdit_ChessboardCellSize, pushButton_Prev);
        QWidget::setTabOrder(pushButton_Prev, pushButton_Next);
        QWidget::setTabOrder(pushButton_Next, pushButton_Load);

        retranslateUi(ParameterInput);

        QMetaObject::connectSlotsByName(ParameterInput);
    } // setupUi

    void retranslateUi(QWidget *ParameterInput)
    {
        ParameterInput->setWindowTitle(QApplication::translate("ParameterInput", "ParameterInput", 0));
        pushButton_Prev->setText(QApplication::translate("ParameterInput", "< Prev", 0));
        pushButton_Next->setText(QApplication::translate("ParameterInput", "Next >", 0));
        label_5->setText(QApplication::translate("ParameterInput", "Chessboard Point Size", 0));
        pushButton_ChessboardPointSizeDescription->setText(QApplication::translate("ParameterInput", "Description", 0));
        lineEdit_ChessboardCellSize->setText(QString());
        label_9->setText(QApplication::translate("ParameterInput", "Car width                            (m)", 0));
#ifndef QT_NO_TOOLTIP
        lineEdit_FileName->setToolTip(QApplication::translate("ParameterInput", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        lineEdit_FileName->setText(QString());
        pushButton_Load->setText(QApplication::translate("ParameterInput", "Load", 0));
        label_7->setText(QApplication::translate("ParameterInput", "Instrinsic Parameter", 0));
        lineEdit_CarWidth->setText(QString());
        lineEdit_CameraToBumper->setText(QString());
        label_2->setText(QApplication::translate("ParameterInput", "Camera Height                   (m)", 0));
        label_4->setText(QApplication::translate("ParameterInput", "Chessboard Cell Size       (mm)", 0));
        lineEdit_CarHeight->setText(QString());
        label_3->setText(QApplication::translate("ParameterInput", "Camera to bumper             (m)", 0));
        label_10->setText(QApplication::translate("ParameterInput", "CameraNumber                  (m)", 0));
        lineEdit_CameraNumber->setText(QString());
        label_6->setText(QApplication::translate("ParameterInput", "Camera Install Position    (mm)", 0));
        pushButton_CameraInstallDescription->setText(QApplication::translate("ParameterInput", "Description", 0));
        lineEdit_CameraInstallPosition->setText(QString());
        label_8->setText(QApplication::translate("ParameterInput", "Chessboard Distance         (m)", 0));
        lineEdit_CarToChessboard_1->setText(QString());
        lineEdit_CarToChessboard_2->setText(QString());
        lineEdit_ChessboardSizeX->setText(QString());
        lineEdit_ChessboardSizeY->setText(QString());
        Background->setText(QString());
        image_1->setText(QString());
        image_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ParameterInput: public Ui_ParameterInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETERINPUT_H
