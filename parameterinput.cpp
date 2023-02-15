#include "parameterinput.h"
#include "ui_parameterinput.h"

using namespace cv;
using namespace std;

bool checked = false;

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

void ParameterInput::on_pushButton_Prev_clicked()
{
    this->close();
}

double g_CarWidth = 0;
double g_CarHeight = 0;
double g_CameraToBumper = 0;
double g_CameraInstallPosition = 0;
float g_ChessboardCellSize = 70;
int g_ChessboardSizeX = 10;
int g_ChessboardSizeY = 11;
float g_CarToChessboard_1 = 4.483;
float g_CarToChessboard_2 = 0;
string IntrinsicParameterPath;

void ParameterInput::on_pushButton_Next_clicked()
{
    this->third_dialog = new CaptureImg();
    this->third_dialog->show();
}

void ParameterInput::on_lineEdit_CarWidth_cursorPositionChanged(int arg1, int arg2)
{
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_CarWidth->setValidator(doubleValidator);
    g_CarWidth = ui->lineEdit_CarWidth->text().toDouble();
}


void ParameterInput::on_lineEdit_CarHeight_cursorPositionChanged(int arg1, int arg2)
{
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_CarHeight->setValidator(doubleValidator);
    g_CarHeight = ui->lineEdit_CarHeight->text().toDouble();
}

void ParameterInput::on_lineEdit_CameraToBumper_cursorPositionChanged(int arg1, int arg2)
{
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_CameraToBumper->setValidator(doubleValidator);
    g_CameraToBumper = ui->lineEdit_CameraToBumper->text().toDouble();
}

void ParameterInput::on_lineEdit_CameraInstallPosition_cursorPositionChanged(int arg1, int arg2)
{
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_CameraInstallPosition->setValidator(doubleValidator);
    g_CameraInstallPosition = ui->lineEdit_CameraInstallPosition->text().toDouble();
}

void ParameterInput::on_lineEdit_ChessboardCellSize_cursorPositionChanged(int arg1, int arg2)
{
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_ChessboardCellSize->setValidator(doubleValidator);
    g_ChessboardCellSize = ui->lineEdit_ChessboardCellSize->text().toFloat();
}

void ParameterInput::on_lineEdit_ChessboardSizeX_cursorPositionChanged(int arg1, int arg2)
{
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_ChessboardSizeX->setValidator(doubleValidator);
    g_ChessboardSizeX = ui->lineEdit_ChessboardSizeX->text().toInt();
}

void ParameterInput::on_lineEdit_ChessboardSizeY_cursorPositionChanged(int arg1, int arg2)
{
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_ChessboardSizeY->setValidator(doubleValidator);
    g_ChessboardSizeY = ui->lineEdit_ChessboardSizeY->text().toInt();
}

void ParameterInput::on_lineEdit_CarToChessboard_1_cursorPositionChanged(int arg1, int arg2)
{
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_CarToChessboard_1->setValidator(doubleValidator);
    g_CarToChessboard_1 = ui->lineEdit_CarToChessboard_1->text().toFloat();
}

void ParameterInput::on_lineEdit_CarToChessboard_2_cursorPositionChanged(int arg1, int arg2)
{
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_CarToChessboard_2->setValidator(doubleValidator);
    g_CarToChessboard_2 = ui->lineEdit_CarToChessboard_2->text().toDouble();
}

void ParameterInput::on_pushButton_Description_clicked()
{

    if (checked == false)
    {
        Mat DescriptionImg = imread("./CameraInstallPositionDescriptionImage.png");
        cv::resize(DescriptionImg,DescriptionImg,Size(500,250));
        cvtColor(DescriptionImg,DescriptionImg,COLOR_BGR2RGB);

        QImage qt_DescriptionImg;
        qt_DescriptionImg = QImage((const unsigned char*) (DescriptionImg.data), DescriptionImg.cols, DescriptionImg.rows, QImage::Format_RGB888);
        ui->PointImg->setPixmap(QPixmap::fromImage(qt_DescriptionImg));
        checked=true;
    }
    else
    {
        //Mat TestImg = Mat::zeros(1000,1000,CV_32SC1);
        Mat TestImg(Size(1000,1000),CV_8UC3,Scalar(239, 235, 231));
        QImage qt_TestImg;
        qt_TestImg = QImage((const unsigned char*) (TestImg.data), TestImg.cols, TestImg.rows, QImage::Format_RGB888);
        ui->PointImg->setPixmap(QPixmap::fromImage(qt_TestImg));
        checked=false;
    }

}

void ParameterInput::on_pushButton_Load_clicked()
{
    QString Qfilename = QFileDialog::getOpenFileName(this,"파일선택","./","Files(*.txt)");
    ui->lineEdit_FileName->setText(Qfilename);
    IntrinsicParameterPath = Qfilename.toStdString();
}

