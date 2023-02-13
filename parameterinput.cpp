#include "parameterinput.h"
#include "ui_parameterinput.h"


#include <stdio.h>
#include <string>
#include <glob.h>


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

string str1;
string str2;
string str3;

void ParameterInput::on_pushbtn_next_mesure_clicked()
{
    this->close();

    QString S1,S2,S3;

    S1 = ui->CarWidth->toPlainText();
    S2 = ui->CameraHeight->toPlainText();
    S3 = ui->CameraToBumper->toPlainText();

//    cout << ui->lineEdit_carWidth << endl;

    str1 = S1.toStdString();
    str2 = S2.toStdString();
    str3 = S3.toStdString();

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

void ParameterInput::on_lineEdit_camHeight_cursorPositionChanged(int arg1, int arg2)
{
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_camHeight->setValidator(doubleValidator);
}

void ParameterInput::on_lineEdit_camToBumper_cursorPositionChanged(int arg1, int arg2)
{
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_camToBumper->setValidator(doubleValidator);
}

void ParameterInput::on_lineEdit_camInstallLoc_cursorPositionChanged(int arg1, int arg2)
{
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_camInstallLoc->setValidator(doubleValidator);
}
