#include "parameterinput.h"
#include "ui_parameterinput.h"


#include <stdio.h>
#include <string>
#include <glob.h>
#include <QFileDialog>
#include <QDebug>

using namespace cv;
using namespace std;

ParameterInput::ParameterInput(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParameterInput)
{
    ui->setupUi(this);
}

ParameterInput::~ParameterInput()
{
    delete ui;
}

void ParameterInput::on_pushbtn_prev_mesure_clicked()
{
    this->close();
}

float g_CarWidth = 0;
float g_CarHeight = 0;
float g_CameraToBumper = 0;
float g_CameraInstallPosition = 0;


void ParameterInput::on_pushbtn_next_mesure_clicked()
{
    this->close();

//    QString S1,S2,S3;

//    S1 = ui->CarWidth->toPlainText();
//    S2 = ui->CameraHeight->toPlainText();
//    S3 = ui->CameraToBumper->toPlainText();

//    cout << ui->lineEdit_carWidth << endl;

//    str1 = S1.toStdString();
//    str2 = S2.toStdString();
//    str3 = S3.toStdString();

//    float a = stof(str1);
//    cout << "ParameterInput_CarWidth: "<< str1 << endl;
//    cout << "ParameterInput_CameraHeight: "<< str2 << endl;
//    cout << "ParameterInput_CameraToBumper: "<< str3 << endl;


    // change to get float directly
//    ParameterInput::carWidth = ui->lineEdit_carWidth->text().toFloat();
//    ParameterInput::camHeight = ui->lineEdit_camHeight->text().toFloat();
//    ParameterInput::camToBumper = ui->lineEdit_camToBumper->text().toFloat();
//    ParameterInput::camInstallLoc = ui->lineEdit_camInstallLoc->text().toFloat();
//    cout << carWidth << endl;


    this->third_dialog = new CaptureImg();
    this->third_dialog->show();
}

void ParameterInput::on_lineEdit_carWidth_cursorPositionChanged(int arg1, int arg2)
{
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_carWidth->setValidator(doubleValidator);
}


void ParameterInput::on_lineEdit_carHeight_cursorPositionChanged(int arg1, int arg2)
{
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_carWidth->setValidator(doubleValidator);
}

void ParameterInput::on_lineEdit_cameraTobumper_cursorPositionChanged(int arg1, int arg2)
{
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_carWidth->setValidator(doubleValidator);
}

void ParameterInput::on_lineEdit_cameraInstallPosition_cursorPositionChanged(int arg1, int arg2)
{
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_carWidth->setValidator(doubleValidator);
}

void ParameterInput::on_lineEdit_cellSize_cursorPositionChanged(int arg1, int arg2)
{
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_carWidth->setValidator(doubleValidator);
}

void ParameterInput::on_lineEdit_chessboardSizeX_cursorPositionChanged(int arg1, int arg2)
{
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_carWidth->setValidator(doubleValidator);
}

void ParameterInput::on_lineEdit_chessboardSizeY_cursorPositionChanged(int arg1, int arg2)
{
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_carWidth->setValidator(doubleValidator);
}

void ParameterInput::on_lineEdit_carTochessboard_1_cursorPositionChanged(int arg1, int arg2)
{
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_carWidth->setValidator(doubleValidator);
}

void ParameterInput::on_lineEdit_carTochessboard_2_cursorPositionChanged(int arg1, int arg2)
{
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_carWidth->setValidator(doubleValidator);
}


bool checked = false;
void ParameterInput::on_pushButton_clicked()
{

    if (checked == false)
    {
        Mat DescriptionImg = imread("/media/server/WORK/sh_git/TempProject/aaa.png");
        cv::resize(DescriptionImg,DescriptionImg,Size(500,250));
        cvtColor(DescriptionImg,DescriptionImg,COLOR_BGR2RGB);

        QImage qt_DescriptionImg;
        qt_DescriptionImg = QImage((const unsigned char*) (DescriptionImg.data), DescriptionImg.cols, DescriptionImg.rows, QImage::Format_RGB888);
        ui->PointImg->setPixmap(QPixmap::fromImage(qt_DescriptionImg));
        checked=true;
    }
    else
    {
        Mat TestImg = Mat::zeros(1000,1000,CV_32SC1);
        QImage qt_TestImg;
        qt_TestImg = QImage((const unsigned char*) (TestImg.data), TestImg.cols, TestImg.rows, QImage::Format_RGB888);
        ui->PointImg->setPixmap(QPixmap::fromImage(qt_TestImg));
        checked=false;
    }

}

void ParameterInput::on_pushButton_2_clicked()
{
    QString dir = QFileDialog::getOpenFileName(this,"파일선택","/","Files(*.*)");
    qDebug() << dir;
}

