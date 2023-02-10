#include "parameterinput.h"
#include "ui_parameterinput.h"
#include <stdio.h>
#include <QString>
#include <string>
#include <glob.h>\


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

    str1 = S1.toStdString();
    str2 = S2.toStdString();
    str3 = S3.toStdString();

    //float a = stof(str1);
//    cout << "ParameterInput_CarWidth: "<< str1 << endl;
//    cout << "ParameterInput_CameraHeight: "<< str2 << endl;
//    cout << "ParameterInput_CameraToBumper: "<< str3 << endl;
    this->third_dialog = new CaptureImg();
    this->third_dialog->show();
}
