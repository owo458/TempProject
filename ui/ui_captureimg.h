/********************************************************************************
** Form generated from reading UI file 'captureimg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAPTUREIMG_H
#define UI_CAPTUREIMG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CaptureImg
{
public:
    QPushButton *pushButton_Prev;
    QPushButton *pushButton_Next;
    QLabel *label_CameraOutput;
    QTextEdit *textEdit_value;
    QPushButton *pushButton_capture_1;
    QPushButton *pushButton_capture_2;
    QLabel *label_Capture_1;
    QLabel *label_Capture_2;
    QTextEdit *textEdit_value_roll_1;
    QTextEdit *textEdit_value_tilt;
    QTextEdit *textEdit_value_roll_2;
    QLabel *label;
    QPushButton *pushButton_CalculationTilt;
    QPushButton *pushButton_clear_1;
    QPushButton *pushButton_clear_2;

    void setupUi(QWidget *CaptureImg)
    {
        if (CaptureImg->objectName().isEmpty())
            CaptureImg->setObjectName(QStringLiteral("CaptureImg"));
        CaptureImg->resize(1400, 710);
        pushButton_Prev = new QPushButton(CaptureImg);
        pushButton_Prev->setObjectName(QStringLiteral("pushButton_Prev"));
        pushButton_Prev->setGeometry(QRect(20, 550, 450, 130));
        pushButton_Next = new QPushButton(CaptureImg);
        pushButton_Next->setObjectName(QStringLiteral("pushButton_Next"));
        pushButton_Next->setGeometry(QRect(510, 550, 450, 130));
        label_CameraOutput = new QLabel(CaptureImg);
        label_CameraOutput->setObjectName(QStringLiteral("label_CameraOutput"));
        label_CameraOutput->setGeometry(QRect(20, 10, 960, 512));
        label_CameraOutput->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        textEdit_value = new QTextEdit(CaptureImg);
        textEdit_value->setObjectName(QStringLiteral("textEdit_value"));
        textEdit_value->setGeometry(QRect(880, 490, 101, 32));
        pushButton_capture_1 = new QPushButton(CaptureImg);
        pushButton_capture_1->setObjectName(QStringLiteral("pushButton_capture_1"));
        pushButton_capture_1->setGeometry(QRect(1010, 480, 171, 41));
        pushButton_capture_2 = new QPushButton(CaptureImg);
        pushButton_capture_2->setObjectName(QStringLiteral("pushButton_capture_2"));
        pushButton_capture_2->setGeometry(QRect(1200, 480, 171, 41));
        label_Capture_1 = new QLabel(CaptureImg);
        label_Capture_1->setObjectName(QStringLiteral("label_Capture_1"));
        label_Capture_1->setGeometry(QRect(1000, 10, 384, 216));
        label_Capture_1->setStyleSheet(QStringLiteral("background-color: rgb(0,0,0);"));
        label_Capture_2 = new QLabel(CaptureImg);
        label_Capture_2->setObjectName(QStringLiteral("label_Capture_2"));
        label_Capture_2->setGeometry(QRect(1000, 240, 384, 216));
        label_Capture_2->setStyleSheet(QStringLiteral("background-color: rgb(0,0,0);"));
        textEdit_value_roll_1 = new QTextEdit(CaptureImg);
        textEdit_value_roll_1->setObjectName(QStringLiteral("textEdit_value_roll_1"));
        textEdit_value_roll_1->setGeometry(QRect(1100, 590, 111, 31));
        textEdit_value_tilt = new QTextEdit(CaptureImg);
        textEdit_value_tilt->setObjectName(QStringLiteral("textEdit_value_tilt"));
        textEdit_value_tilt->setGeometry(QRect(1100, 640, 231, 31));
        textEdit_value_roll_2 = new QTextEdit(CaptureImg);
        textEdit_value_roll_2->setObjectName(QStringLiteral("textEdit_value_roll_2"));
        textEdit_value_roll_2->setGeometry(QRect(1220, 590, 111, 31));
        label = new QLabel(CaptureImg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(1050, 590, 59, 20));
        pushButton_CalculationTilt = new QPushButton(CaptureImg);
        pushButton_CalculationTilt->setObjectName(QStringLiteral("pushButton_CalculationTilt"));
        pushButton_CalculationTilt->setGeometry(QRect(1040, 640, 51, 31));
        pushButton_clear_1 = new QPushButton(CaptureImg);
        pushButton_clear_1->setObjectName(QStringLiteral("pushButton_clear_1"));
        pushButton_clear_1->setGeometry(QRect(1010, 530, 171, 23));
        pushButton_clear_2 = new QPushButton(CaptureImg);
        pushButton_clear_2->setObjectName(QStringLiteral("pushButton_clear_2"));
        pushButton_clear_2->setGeometry(QRect(1200, 530, 171, 23));
        label_CameraOutput->raise();
        pushButton_Prev->raise();
        pushButton_Next->raise();
        textEdit_value->raise();
        pushButton_capture_1->raise();
        pushButton_capture_2->raise();
        label_Capture_1->raise();
        label_Capture_2->raise();
        textEdit_value_roll_1->raise();
        textEdit_value_tilt->raise();
        textEdit_value_roll_2->raise();
        label->raise();
        pushButton_CalculationTilt->raise();
        pushButton_clear_1->raise();
        pushButton_clear_2->raise();

        retranslateUi(CaptureImg);

        QMetaObject::connectSlotsByName(CaptureImg);
    } // setupUi

    void retranslateUi(QWidget *CaptureImg)
    {
        CaptureImg->setWindowTitle(QApplication::translate("CaptureImg", "Capture Image", 0));
        pushButton_Prev->setText(QApplication::translate("CaptureImg", "< Prev", 0));
        pushButton_Next->setText(QApplication::translate("CaptureImg", "Next >", 0));
        label_CameraOutput->setText(QString());
        textEdit_value->setHtml(QApplication::translate("CaptureImg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">000</p></body></html>", 0));
        pushButton_capture_1->setText(QApplication::translate("CaptureImg", "capture_1", 0));
        pushButton_capture_2->setText(QApplication::translate("CaptureImg", "capture_2", 0));
        label_Capture_1->setText(QString());
        label_Capture_2->setText(QString());
        textEdit_value_roll_1->setHtml(QApplication::translate("CaptureImg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">000</p></body></html>", 0));
        textEdit_value_tilt->setHtml(QApplication::translate("CaptureImg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">000</p></body></html>", 0));
        textEdit_value_roll_2->setHtml(QApplication::translate("CaptureImg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">000</p></body></html>", 0));
        label->setText(QApplication::translate("CaptureImg", "Roll", 0));
        pushButton_CalculationTilt->setText(QApplication::translate("CaptureImg", "Tilt", 0));
        pushButton_clear_1->setText(QApplication::translate("CaptureImg", "Clear", 0));
        pushButton_clear_2->setText(QApplication::translate("CaptureImg", "Clear", 0));
    }
namespace Ui {
    class CaptureImg: public Ui_CaptureImg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAPTUREIMG_H
