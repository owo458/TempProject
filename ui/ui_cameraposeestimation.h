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
    QLabel *label_PointImg;
    QLabel *label_ReprojectionImg;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_RotationMatrix;
    QTextEdit *R_Matrix_text;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_TranslationMatrix;
    QTextEdit *T_Matrix_text;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_ReprojectionError;
    QLabel *label_meanPixelError_x;
    QTextEdit *meanPixelError_x_text;
    QLabel *label_meanPixelError_y;
    QTextEdit *meanPixelError_y_text;
    QLabel *label_normPixelError;
    QTextEdit *normPixelError_text;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_CameraPosition;
    QLabel *label_X;
    QTextEdit *X_text;
    QLabel *label_Y;
    QTextEdit *Y_text;
    QLabel *label_Z;
    QTextEdit *Z_text;
    QWidget *layoutWidget_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_CameraPose;
    QLabel *label_Tilt;
    QTextEdit *TILT_text;
    QLabel *label_Pan;
    QTextEdit *PAN_text;
    QLabel *label_Roll;
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
        label_PointImg = new QLabel(CameraPoseEstimation);
        label_PointImg->setObjectName(QStringLiteral("label_PointImg"));
        label_PointImg->setGeometry(QRect(50, 20, 256, 19));
        label_ReprojectionImg = new QLabel(CameraPoseEstimation);
        label_ReprojectionImg->setObjectName(QStringLiteral("label_ReprojectionImg"));
        label_ReprojectionImg->setGeometry(QRect(50, 420, 256, 19));
        splitter = new QSplitter(CameraPoseEstimation);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(710, 20, 258, 791));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_RotationMatrix = new QLabel(layoutWidget);
        label_RotationMatrix->setObjectName(QStringLiteral("label_RotationMatrix"));

        verticalLayout->addWidget(label_RotationMatrix);

        R_Matrix_text = new QTextEdit(layoutWidget);
        R_Matrix_text->setObjectName(QStringLiteral("R_Matrix_text"));

        verticalLayout->addWidget(R_Matrix_text);

        splitter->addWidget(layoutWidget);
        layoutWidget_2 = new QWidget(splitter);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_TranslationMatrix = new QLabel(layoutWidget_2);
        label_TranslationMatrix->setObjectName(QStringLiteral("label_TranslationMatrix"));

        verticalLayout_2->addWidget(label_TranslationMatrix);

        T_Matrix_text = new QTextEdit(layoutWidget_2);
        T_Matrix_text->setObjectName(QStringLiteral("T_Matrix_text"));

        verticalLayout_2->addWidget(T_Matrix_text);

        splitter->addWidget(layoutWidget_2);
        layoutWidget_3 = new QWidget(splitter);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        verticalLayout_5 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_ReprojectionError = new QLabel(layoutWidget_3);
        label_ReprojectionError->setObjectName(QStringLiteral("label_ReprojectionError"));

        verticalLayout_5->addWidget(label_ReprojectionError);

        label_meanPixelError_x = new QLabel(layoutWidget_3);
        label_meanPixelError_x->setObjectName(QStringLiteral("label_meanPixelError_x"));

        verticalLayout_5->addWidget(label_meanPixelError_x);

        meanPixelError_x_text = new QTextEdit(layoutWidget_3);
        meanPixelError_x_text->setObjectName(QStringLiteral("meanPixelError_x_text"));

        verticalLayout_5->addWidget(meanPixelError_x_text);

        label_meanPixelError_y = new QLabel(layoutWidget_3);
        label_meanPixelError_y->setObjectName(QStringLiteral("label_meanPixelError_y"));

        verticalLayout_5->addWidget(label_meanPixelError_y);

        meanPixelError_y_text = new QTextEdit(layoutWidget_3);
        meanPixelError_y_text->setObjectName(QStringLiteral("meanPixelError_y_text"));

        verticalLayout_5->addWidget(meanPixelError_y_text);

        label_normPixelError = new QLabel(layoutWidget_3);
        label_normPixelError->setObjectName(QStringLiteral("label_normPixelError"));

        verticalLayout_5->addWidget(label_normPixelError);

        normPixelError_text = new QTextEdit(layoutWidget_3);
        normPixelError_text->setObjectName(QStringLiteral("normPixelError_text"));

        verticalLayout_5->addWidget(normPixelError_text);

        splitter->addWidget(layoutWidget_3);
        layoutWidget_4 = new QWidget(splitter);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_CameraPosition = new QLabel(layoutWidget_4);
        label_CameraPosition->setObjectName(QStringLiteral("label_CameraPosition"));

        verticalLayout_4->addWidget(label_CameraPosition);

        label_X = new QLabel(layoutWidget_4);
        label_X->setObjectName(QStringLiteral("label_X"));

        verticalLayout_4->addWidget(label_X);

        X_text = new QTextEdit(layoutWidget_4);
        X_text->setObjectName(QStringLiteral("X_text"));

        verticalLayout_4->addWidget(X_text);

        label_Y = new QLabel(layoutWidget_4);
        label_Y->setObjectName(QStringLiteral("label_Y"));

        verticalLayout_4->addWidget(label_Y);

        Y_text = new QTextEdit(layoutWidget_4);
        Y_text->setObjectName(QStringLiteral("Y_text"));

        verticalLayout_4->addWidget(Y_text);

        label_Z = new QLabel(layoutWidget_4);
        label_Z->setObjectName(QStringLiteral("label_Z"));

        verticalLayout_4->addWidget(label_Z);

        Z_text = new QTextEdit(layoutWidget_4);
        Z_text->setObjectName(QStringLiteral("Z_text"));

        verticalLayout_4->addWidget(Z_text);

        splitter->addWidget(layoutWidget_4);
        layoutWidget_5 = new QWidget(splitter);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_5);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_CameraPose = new QLabel(layoutWidget_5);
        label_CameraPose->setObjectName(QStringLiteral("label_CameraPose"));

        verticalLayout_3->addWidget(label_CameraPose);

        label_Tilt = new QLabel(layoutWidget_5);
        label_Tilt->setObjectName(QStringLiteral("label_Tilt"));

        verticalLayout_3->addWidget(label_Tilt);

        TILT_text = new QTextEdit(layoutWidget_5);
        TILT_text->setObjectName(QStringLiteral("TILT_text"));

        verticalLayout_3->addWidget(TILT_text);

        label_Pan = new QLabel(layoutWidget_5);
        label_Pan->setObjectName(QStringLiteral("label_Pan"));

        verticalLayout_3->addWidget(label_Pan);

        PAN_text = new QTextEdit(layoutWidget_5);
        PAN_text->setObjectName(QStringLiteral("PAN_text"));

        verticalLayout_3->addWidget(PAN_text);

        label_Roll = new QLabel(layoutWidget_5);
        label_Roll->setObjectName(QStringLiteral("label_Roll"));

        verticalLayout_3->addWidget(label_Roll);

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
        label_PointImg->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:12pt;\">Detected Point Image</span></p></body></html>", 0));
        label_ReprojectionImg->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:12pt;\">Reprojection Point Image</span></p></body></html>", 0));
        label_RotationMatrix->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:12pt;\">Rotation Matrix</span></p></body></html>", 0));
        R_Matrix_text->setHtml(QApplication::translate("CameraPoseEstimation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        label_TranslationMatrix->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:12pt;\">Translation Matrix</span></p></body></html>", 0));
        T_Matrix_text->setHtml(QApplication::translate("CameraPoseEstimation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        label_ReprojectionError->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:12pt;\">Reprojection Error</span></p></body></html>", 0));
        label_meanPixelError_x->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:10pt;\">meanPixelError_x</span></p></body></html>", 0));
        meanPixelError_x_text->setHtml(QApplication::translate("CameraPoseEstimation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        label_meanPixelError_y->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:10pt;\">meanPixelError_y</span></p></body></html>", 0));
        meanPixelError_y_text->setHtml(QApplication::translate("CameraPoseEstimation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        label_normPixelError->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:10pt;\">normPixelError</span></p></body></html>", 0));
        normPixelError_text->setHtml(QApplication::translate("CameraPoseEstimation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        label_CameraPosition->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:12pt;\">Camera Position</span></p></body></html>", 0));
        label_X->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:10pt;\">X(mm)</span></p></body></html>", 0));
        X_text->setHtml(QApplication::translate("CameraPoseEstimation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        label_Y->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:10pt;\">Y(mm)</span></p></body></html>", 0));
        Y_text->setHtml(QApplication::translate("CameraPoseEstimation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        label_Z->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:10pt;\">Z(mm)</span></p></body></html>", 0));
        Z_text->setHtml(QApplication::translate("CameraPoseEstimation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        label_CameraPose->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:12pt;\">Camera Pose</span></p></body></html>", 0));
        label_Tilt->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:10pt;\">TILT(Pitch)</span></p></body></html>", 0));
        TILT_text->setHtml(QApplication::translate("CameraPoseEstimation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        label_Pan->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:10pt;\">PAN(yaw)</span></p></body></html>", 0));
        PAN_text->setHtml(QApplication::translate("CameraPoseEstimation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        label_Roll->setText(QApplication::translate("CameraPoseEstimation", "<html><head/><body><p><span style=\" font-size:10pt;\">ROLL</span></p></body></html>", 0));
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
