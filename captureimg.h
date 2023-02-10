#ifndef CaptureImg_H
#define CaptureImg_H

#include <QWidget>
#include <QTimer>
#include <QString>

#include "opencv4/opencv2/opencv.hpp"
#include "opencv4/opencv2/imgproc/imgproc.hpp"
#include "opencv4/opencv2/highgui/highgui.hpp"

#include "cameraposeestimation.h"

#define MINI_IMG_W (384)
#define MINI_IMG_H (216)

using namespace std;

namespace Ui {
class CaptureImg;
}

class CaptureImg : public QWidget
{
    Q_OBJECT

public:
    explicit CaptureImg(QWidget *parent = nullptr);
    cv::Mat tmpFrame_1, tmpFrame_2;
    ~CaptureImg();

private slots:
    void update_window();

    void on_pushButton_2_clicked();

    void on_pushButton_capture_1_clicked(bool checked);

    void on_pushButton_capture_2_clicked(bool checked);

private:
    Ui::CaptureImg *ui;

    QTimer *timer;
    QImage qt_image;
    QImage qt_image_mini_1;
    QImage qt_image_mini_2;

    cv::VideoCapture cap;
    cv::Mat frame;
    cv::Mat image_input;


    cv::Mat frame_display, frame_display_mini_1, frame_display_mini_2;
    //cv::Mat tmpFrame_1, tmpFrame_2;

    CameraPoseEstimation *fore_dialog;

    /*@woneyy*/
    QString outText_roll;
    float value_roll_inPixel;

};

#endif // CaptureImg_H
