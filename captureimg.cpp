#include "captureimg.h"
#include "ui_captureimg.h"
#include <stdio.h>
#include <QMessageBox>

#include "checkcamerainstallation.h"

using namespace cv;
using namespace std;

Mat CameraPoseCapture_1;
Mat CameraPoseCapture_2;
bool foundchessboard = false;

CaptureImg::CaptureImg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CaptureImg)
{
    ui->setupUi(this);

    timer = new QTimer(this);

    cap.open(0);

    if(!cap.isOpened())
    {
        cout << "camera is not open" << endl;
    }
    else
    {
        cout << "camera is open" << endl;
    }

    connect(timer, &QTimer::timeout, this, &CaptureImg::update_window);
            timer->start(20);
}

CaptureImg::~CaptureImg()
{
    disconnect(timer, &QTimer::timeout, this, &CaptureImg::update_window);
    cap.release();
    delete ui;
}

void CaptureImg::update_window()
{
    cap >> frame;
    cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);

    frame.copyTo(image_input);
    checkCameraInstallation(CaptureImg::image_input, &value_roll_inPixel);

    if (value_roll_inPixel != 99)
    {
        ui->textEdit_value->setText(QString::number(value_roll_inPixel));
    }
    else
    {
        ui->textEdit_value->setText("err");
    }

    cv::resize(image_input, frame_display, cv::Size(960, 540));

    qt_image = QImage((const unsigned char*) (frame_display.data), frame_display.cols, frame_display.rows, QImage::Format_RGB888);
    ui->label_image->setPixmap(QPixmap::fromImage(qt_image));

    qt_image_mini_1 = QImage((const unsigned char*) (CaptureImg::frame_display_mini_1.data), MINI_IMG_W, MINI_IMG_H, QImage::Format_RGB888);
    ui->label_image_mini_1->setPixmap(QPixmap::fromImage(qt_image_mini_1));

    qt_image_mini_2 = QImage((const unsigned char*) (CaptureImg::frame_display_mini_2.data), MINI_IMG_W, MINI_IMG_H, QImage::Format_RGB888);
    ui->label_image_mini_2->setPixmap(QPixmap::fromImage(qt_image_mini_2));

}

void CaptureImg::on_pushButton_capture_1_clicked(bool capture_checked_1)
{
    foundchessboard = false;
    CaptureImg::frame.copyTo(CaptureImg::tmpFrame_1);
    CaptureImg::findChessboard(tmpFrame_1, checker_size, &corners_1,&foundchessboard);
    if (foundchessboard == true)
    {
        CaptureImg::roll_by_checkered(tmpFrame_1, checker_size, corners_1, &value_roll_1);
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Chessboard Error     ");
        msgBox.setText("Not Detection ChessBoard     ");
        msgBox.exec();
    }
    ui->textEdit_value_roll_1->setText(QString::number(value_roll_1));
    cv::resize(tmpFrame_1, frame_display_mini_1, cv::Size(MINI_IMG_W, MINI_IMG_H));

    CameraPoseCapture_1 = frame;

}

void CaptureImg::on_pushButton_capture_2_clicked(bool capture_checked_2)
{
    foundchessboard = false;
    CaptureImg::frame.copyTo(CaptureImg::tmpFrame_2);
    CaptureImg::findChessboard(tmpFrame_2, checker_size, &corners_2,&foundchessboard);
    if (foundchessboard == true)
    {
        CaptureImg::roll_by_checkered(tmpFrame_1, checker_size, corners_1, &value_roll_2);
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Chessboard Error     ");
        msgBox.setText("Not Detection ChessBoard     ");
        msgBox.exec();
    }

    ui->textEdit_value_roll_2->setText(QString::number(value_roll_2));
    cv::resize(tmpFrame_2, frame_display_mini_2, cv::Size(MINI_IMG_W, MINI_IMG_H));
}

void CaptureImg::on_pushButton_2_clicked()
{
    this->close();
    this->fore_dialog = new CameraPoseEstimation();
    this->fore_dialog->show();
}

void CaptureImg::on_pushButton_3_clicked()
{
    if (tmpFrame_1.empty() == 0 && tmpFrame_2.empty() == 0 && foundchessboard == true)
    {
        CaptureImg::tilt_by_checkered(tmpFrame_1, tmpFrame_2, checker_size, corners_1, corners_2, &value_tilt);
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error     ");
        msgBox.setText("Capture Image is Empty or Not Detection Chessboard     ");
        msgBox.exec();
    }
    ui->textEdit_value_tilt->setText(QString::number(value_tilt));

}
