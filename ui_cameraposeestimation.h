/********************************************************************************
** Form generated from reading UI file 'cameraposeestimation.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERAPOSEESTIMATION_H
#define UI_CAMERAPOSEESTIMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CameraPoseEstimation
{
public:
    QLabel *ReProjectionImg;
    QLabel *PointImg;
    QLabel *label_14;
    QLabel *label_15;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QTextEdit *R_Matrix_text;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QTextEdit *T_Matrix_text;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QLabel *label_11;
    QTextEdit *meanPixelError_x_text;
    QLabel *label_12;
    QTextEdit *meanPixelError_y_text;
    QLabel *label_13;
    QTextEdit *normPixelError_text;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QLabel *label_8;
    QTextEdit *X_text;
    QLabel *label_9;
    QTextEdit *Y_text;
    QLabel *label_10;
    QTextEdit *Z_text;
    QWidget *layoutWidget_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QLabel *TILT_label;
    QTextEdit *TILT_text;
    QLabel *TILT_label_2;
    QTextEdit *PAN_text;
    QLabel *TILT_label_3;
    QTextEdit *ROLL_text;
    QPushButton *ExportButton;

    void setupUi(QWidget *CameraPoseEstimation)
    {
        if (CameraPoseEstimation->objectName().isEmpty())
            CameraPoseEstimation->setObjectName(QStringLiteral("CameraPoseEstimation"));
        CameraPoseEstimation->resize(1000, 880);
        ReProjectionImg = new QLabel(CameraPoseEstimation);
        ReProjectionImg->setObjectName(QStringLiteral("ReProjectionImg"));
        ReProjectionImg->setGeometry(QRect(50, 450, 640, 360));
        ReProjectionImg->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        PointImg = new QLabel(CameraPoseEstimation);
        PointImg->setObjectName(QStringLiteral("PointImg"));
        PointImg->setGeometry(QRect(50, 50, 640, 360));
        PointImg->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        label_14 = new QLabel(CameraPoseEstimation);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(50, 20, 256, 19));
        label_15 = new QLabel(CameraPoseEstimation);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(50, 420, 256, 19));
        splitter = new QSplitter(CameraPoseEstimation);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(710, 20, 258, 791));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        R_Matrix_text = new QTextEdit(layoutWidget);
        R_Matrix_text->setObjectName(QStringLiteral("R_Matrix_text"));

        verticalLayout->addWidget(R_Matrix_text);

        splitter->addWidget(layoutWidget);
        layoutWidget_2 = new QWidget(splitter);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        T_Matrix_text = new QTextEdit(layoutWidget_2);
        T_Matrix_text->setObjectName(QStringLiteral("T_Matrix_text"));

        verticalLayout_2->addWidget(T_Matrix_text);

        splitter->addWidget(layoutWidget_2);
        layoutWidget_3 = new QWidget(splitter);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        verticalLayout_5 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_5->addWidget(label_5);

        label_11 = new QLabel(layoutWidget_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_5->addWidget(label_11);

        meanPixelError_x_text = new QTextEdit(layoutWidget_3);
        meanPixelError_x_text->setObjectName(QStringLiteral("meanPixelError_x_text"));

        verticalLayout_5->addWidget(meanPixelError_x_text);

        label_12 = new QLabel(layoutWidget_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_5->addWidget(label_12);

        meanPixelError_y_text = new QTextEdit(layoutWidget_3);
        meanPixelError_y_text->setObjectName(QStringLiteral("meanPixelError_y_text"));

        verticalLayout_5->addWidget(meanPixelError_y_text);

        label_13 = new QLabel(layoutWidget_3);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_5->addWidget(label_13);

        normPixelError_text = new QTextEdit(layoutWidget_3);
        normPixelError_text->setObjectName(QStringLiteral("normPixelError_text"));

        verticalLayout_5->addWidget(normPixelError_text);

        splitter->addWidget(layoutWidget_3);
        layoutWidget_4 = new QWidget(splitter);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_4->addWidget(label_6);

        label_8 = new QLabel(layoutWidget_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_4->addWidget(label_8);

        X_text = new QTextEdit(layoutWidget_4);
        X_text->setObjectName(QStringLiteral("X_text"));

        verticalLayout_4->addWidget(X_text);

        label_9 = new QLabel(layoutWidget_4);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_4->addWidget(label_9);

        Y_text = new QTextEdit(layoutWidget_4);
        Y_text->setObjectName(QStringLiteral("Y_text"));

        verticalLayout_4->addWidget(Y_text);

        label_10 = new QLabel(layoutWidget_4);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_4->addWidget(label_10);

        Z_text = new QTextEdit(layoutWidget_4);
        Z_text->setObjectName(QStringLiteral("Z_text"));

        verticalLayout_4->addWidget(Z_text);

        splitter->addWidget(layoutWidget_4);
        layoutWidget_5 = new QWidget(splitter);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_5);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_5);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_3->addWidget(label_7);

        TILT_label = new QLabel(layoutWidget_5);
        TILT_label->setObjectName(QStringLiteral("TILT_label"));

        verticalLayout_3->addWidget(TILT_label);

        TILT_text = new QTextEdit(layoutWidget_5);
        TILT_text->setObjectName(QStringLiteral("TILT_text"));

        verticalLayout_3->addWidget(TILT_text);

        TILT_label_2 = new QLabel(layoutWidget_5);
        TILT_label_2->setObjectName(QStringLiteral("TILT_label_2"));

        verticalLayout_3->addWidget(TILT_label_2);

        PAN_text = new QTextEdit(layoutWidget_5);
        PAN_text->setObjectName(QStringLiteral("PAN_text"));

        verticalLayout_3->addWidget(PAN_text);

        TILT_label_3 = new QLabel(layoutWidget_5);
        TILT_label_3->setObjectName(QStringLiteral("TILT_label_3"));

        verticalLayout_3->addWidget(TILT_label_3);

        ROLL_text = new QTextEdit(layoutWidget_5);
        ROLL_text->setObjectName(QStringLiteral("ROLL_text"));

        verticalLayout_3->addWidget(ROLL_text);

        splitter->addWidget(layoutWidget_5);
        ExportButton = new QPushButton(splitter);
        ExportButton->setObjectName(QStringLiteral("ExportButton"));
        splitter->addWidget(ExportButton);

        retranslateUi(CameraPoseEstimation);

        QMetaObject::connectSlotsByName(CameraPoseEstimation);
    } // setupUi

    void retranslateUi(QWidget *CameraPoseEstimation)
    {
        CameraPoseEstimation->setWindowTitle(QApplication::translate("CameraPoseEstimation", "Camera Pose Estimation", 0));
        ReProjectionImg->setText(QString());
        PointImg->setText(QString());
        label_14->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:12pt;\">Detected Point Image</span></p></body></html>", 0));
        label_15->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:12pt;\">Reprojection Point Image</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:12pt;\">Rotation Matrix</span></p></body></html>", 0));
        R_Matrix_text->setHtml(QApplication::translate("CameraPoseEstimation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        label_4->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:12pt;\">Translation Matrix</span></p></body></html>", 0));
        T_Matrix_text->setHtml(QApplication::translate("CameraPoseEstimation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        label_5->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:12pt;\">Reprojection Error</span></p></body></html>", 0));
        label_11->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:10pt;\">meanPixelError_x</span></p></body></html>", 0));
        meanPixelError_x_text->setHtml(QApplication::translate("CameraPoseEstimation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        label_12->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:10pt;\">meanPixelError_y</span></p></body></html>", 0));
        meanPixelError_y_text->setHtml(QApplication::translate("CameraPoseEstimation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        label_13->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:10pt;\">normPixelError</span></p></body></html>", 0));
        normPixelError_text->setHtml(QApplication::translate("CameraPoseEstimation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        label_6->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:12pt;\">Camera Position</span></p></body></html>", 0));
        label_8->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:10pt;\">X</span></p></body></html>", 0));
        X_text->setHtml(QApplication::translate("CameraPoseEstimation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        label_9->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:10pt;\">Y</span></p></body></html>", 0));
        Y_text->setHtml(QApplication::translate("CameraPoseEstimation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        label_10->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:10pt;\">Z</span></p></body></html>", 0));
        Z_text->setHtml(QApplication::translate("CameraPoseEstimation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        label_7->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:12pt;\">Camera Pose</span></p></body></html>", 0));
        TILT_label->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:10pt;\">TILT(Pitch)</span></p></body></html>", 0));
        TILT_text->setHtml(QApplication::translate("CameraPoseEstimation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        TILT_label_2->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:10pt;\">PAN(yaw)</span></p></body></html>", 0));
        PAN_text->setHtml(QApplication::translate("CameraPoseEstimation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        TILT_label_3->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:10pt;\">ROLL</span></p></body></html>", 0));
        ROLL_text->setHtml(QApplication::translate("CameraPoseEstimation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        ExportButton->setText(QApplication::translate("CameraPoseEstimation", "Export", 0));
    } // retranslateUi

};

namespace Ui {
    class CameraPoseEstimation: public Ui_CameraPoseEstimation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAPOSEESTIMATION_H
