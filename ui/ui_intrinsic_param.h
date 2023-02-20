/********************************************************************************
** Form generated from reading UI file 'intrinsic_param.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTRINSIC_PARAM_H
#define UI_INTRINSIC_PARAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_intrinsic_param
{
public:
    QPushButton *pushButton_VideoLoad;
    QPushButton *pushButton_exit;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_VideoPath;
    QTextBrowser *textBrowser_VideoPath;
    QLabel *label_SavePath;
    QTextBrowser *textBrowser_SavePath;
    QLabel *label_ChessBoard;
    QHBoxLayout *horizontalLayout_5;
    QTextEdit *textEdit_ChessHorizontal;
    QTextEdit *textEdit_ChessVertical;
    QLabel *label;
    QTextEdit *textEdit_FPS;
    QProgressBar *progressBar_calProcess;
    QLabel *label_PrincipalPointError;
    QTextBrowser *textBrowser_PrincipaPointError;
    QLabel *label_ReprojectError;
    QTextBrowser *textBrowser_ReprojectionError;
    QPushButton *pushButton_SavePath;
    QPushButton *pushButton_Start;
    QLabel *Label_inCalImg;

    void setupUi(QDialog *intrinsic_param)
    {
        if (intrinsic_param->objectName().isEmpty())
            intrinsic_param->setObjectName(QStringLiteral("intrinsic_param"));
        intrinsic_param->resize(892, 596);
        pushButton_VideoLoad = new QPushButton(intrinsic_param);
        pushButton_VideoLoad->setObjectName(QStringLiteral("pushButton_VideoLoad"));
        pushButton_VideoLoad->setGeometry(QRect(770, 20, 80, 30));
        pushButton_exit = new QPushButton(intrinsic_param);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(770, 260, 80, 30));
        formLayoutWidget = new QWidget(intrinsic_param);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(50, 20, 711, 271));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_VideoPath = new QLabel(formLayoutWidget);
        label_VideoPath->setObjectName(QStringLiteral("label_VideoPath"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_VideoPath);

        textBrowser_VideoPath = new QTextBrowser(formLayoutWidget);
        textBrowser_VideoPath->setObjectName(QStringLiteral("textBrowser_VideoPath"));
        textBrowser_VideoPath->setTabStopWidth(80);

        formLayout->setWidget(0, QFormLayout::FieldRole, textBrowser_VideoPath);

        label_SavePath = new QLabel(formLayoutWidget);
        label_SavePath->setObjectName(QStringLiteral("label_SavePath"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_SavePath);

        textBrowser_SavePath = new QTextBrowser(formLayoutWidget);
        textBrowser_SavePath->setObjectName(QStringLiteral("textBrowser_SavePath"));

        formLayout->setWidget(1, QFormLayout::FieldRole, textBrowser_SavePath);

        label_ChessBoard = new QLabel(formLayoutWidget);
        label_ChessBoard->setObjectName(QStringLiteral("label_ChessBoard"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_ChessBoard);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        textEdit_ChessHorizontal = new QTextEdit(formLayoutWidget);
        textEdit_ChessHorizontal->setObjectName(QStringLiteral("textEdit_ChessHorizontal"));
        textEdit_ChessHorizontal->setPlaceholderText(QStringLiteral("9"));

        horizontalLayout_5->addWidget(textEdit_ChessHorizontal);

        textEdit_ChessVertical = new QTextEdit(formLayoutWidget);
        textEdit_ChessVertical->setObjectName(QStringLiteral("textEdit_ChessVertical"));
        textEdit_ChessVertical->setPlaceholderText(QStringLiteral("10"));

        horizontalLayout_5->addWidget(textEdit_ChessVertical);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_5);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label);

        textEdit_FPS = new QTextEdit(formLayoutWidget);
        textEdit_FPS->setObjectName(QStringLiteral("textEdit_FPS"));
        textEdit_FPS->setPlaceholderText(QStringLiteral("3"));

        formLayout->setWidget(3, QFormLayout::FieldRole, textEdit_FPS);

        progressBar_calProcess = new QProgressBar(formLayoutWidget);
        progressBar_calProcess->setObjectName(QStringLiteral("progressBar_calProcess"));
        progressBar_calProcess->setMaximum(100);
        progressBar_calProcess->setValue(24);

        formLayout->setWidget(4, QFormLayout::FieldRole, progressBar_calProcess);

        label_PrincipalPointError = new QLabel(formLayoutWidget);
        label_PrincipalPointError->setObjectName(QStringLiteral("label_PrincipalPointError"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_PrincipalPointError);

        textBrowser_PrincipaPointError = new QTextBrowser(formLayoutWidget);
        textBrowser_PrincipaPointError->setObjectName(QStringLiteral("textBrowser_PrincipaPointError"));

        formLayout->setWidget(6, QFormLayout::FieldRole, textBrowser_PrincipaPointError);

        label_ReprojectError = new QLabel(formLayoutWidget);
        label_ReprojectError->setObjectName(QStringLiteral("label_ReprojectError"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_ReprojectError);

        textBrowser_ReprojectionError = new QTextBrowser(formLayoutWidget);
        textBrowser_ReprojectionError->setObjectName(QStringLiteral("textBrowser_ReprojectionError"));

        formLayout->setWidget(7, QFormLayout::FieldRole, textBrowser_ReprojectionError);

        pushButton_SavePath = new QPushButton(intrinsic_param);
        pushButton_SavePath->setObjectName(QStringLiteral("pushButton_SavePath"));
        pushButton_SavePath->setGeometry(QRect(770, 65, 80, 30));
        pushButton_Start = new QPushButton(intrinsic_param);
        pushButton_Start->setObjectName(QStringLiteral("pushButton_Start"));
        pushButton_Start->setGeometry(QRect(770, 140, 80, 101));
        Label_inCalImg = new QLabel(intrinsic_param);
        Label_inCalImg->setObjectName(QStringLiteral("Label_inCalImg"));
        Label_inCalImg->setGeometry(QRect(40, 330, 801, 241));

        retranslateUi(intrinsic_param);

        QMetaObject::connectSlotsByName(intrinsic_param);
    } // setupUi

    void retranslateUi(QDialog *intrinsic_param)
    {
        intrinsic_param->setWindowTitle(QApplication::translate("intrinsic_param", "Dialog", 0));
        pushButton_VideoLoad->setText(QApplication::translate("intrinsic_param", "load", 0));
        pushButton_exit->setText(QApplication::translate("intrinsic_param", "exit", 0));
        label_VideoPath->setText(QApplication::translate("intrinsic_param", "Video Path", 0));
        label_SavePath->setText(QApplication::translate("intrinsic_param", "Save Path", 0));
        label_ChessBoard->setText(QApplication::translate("intrinsic_param", "Chess Board Point [horizontal] [vertical]", 0));
        label->setText(QApplication::translate("intrinsic_param", "Frame per Second", 0));
        label_PrincipalPointError->setText(QApplication::translate("intrinsic_param", "Principal Point Error", 0));
        textBrowser_PrincipaPointError->setHtml(QApplication::translate("intrinsic_param", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        label_ReprojectError->setText(QApplication::translate("intrinsic_param", "Reprojection Error", 0));
        textBrowser_ReprojectionError->setHtml(QApplication::translate("intrinsic_param", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        pushButton_SavePath->setText(QApplication::translate("intrinsic_param", "select", 0));
        pushButton_Start->setText(QApplication::translate("intrinsic_param", "start", 0));
        Label_inCalImg->setText(QApplication::translate("intrinsic_param", "incalimg", 0));
    } // retranslateUi

};

namespace Ui {
    class intrinsic_param: public Ui_intrinsic_param {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTRINSIC_PARAM_H
