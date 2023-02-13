#ifndef CaptureImg_H
#define CaptureImg_H

#include <QWidget>
#include <QTimer>
#include <QString>

#include "opencv4/opencv2/opencv.hpp"
#include "opencv4/opencv2/imgproc/imgproc.hpp"
#include "opencv4/opencv2/highgui/highgui.hpp"

//#include "parameterinput.h"

#include "cameraposeestimation.h"
//#include "checkcamerainstallation.h"

#define MINI_IMG_W (384)
#define MINI_IMG_H (216)

//#define CHECKER_COLS (8)
//#define CHECKER_ROWS (5)

#define CHECKER_COLS (10)
#define CHECKER_ROWS (7)

#define D_TWO_CHESSBOARD (3000) // 1000mm = 100cm = 1m
#define CHESSBOARD_W_MM (80)

#define CY (527)

using namespace std;

namespace Ui {
class CaptureImg;
}

class CaptureImg : public QWidget
{
    Q_OBJECT

public:
    explicit CaptureImg(QWidget *parent = nullptr);
//    cv::Mat tmpFrame_1, tmpFrame_2;
    ~CaptureImg();

private slots:
    void update_window();

    void on_pushButton_2_clicked();

    void on_pushButton_capture_1_clicked(bool checked);

    void on_pushButton_capture_2_clicked(bool checked);

    void on_pushButton_3_clicked();

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
    cv::Mat tmpFrame_1, tmpFrame_2;

    CameraPoseEstimation *fore_dialog;

//    QString outText_roll_inPixel, outText_roll, outText_tilt;
    float value_roll_inPixel;
    float value_roll_1, value_roll_2, value_tilt;

    vector<cv::Point2f> corners_1, corners_2;
    cv::Size checker_size = cv::Size(CHECKER_COLS-1, CHECKER_ROWS-1);


    void findChessboard(cv::Mat input_img, cv::Size checker_size, vector<cv::Point2f> *corners)
    {
      cv::Mat gray_img;
      cv::cvtColor(input_img, gray_img, cv::COLOR_BGR2GRAY);

      bool found = cv::findChessboardCorners(input_img, checker_size, *corners, cv::CALIB_CB_ADAPTIVE_THRESH + cv::CALIB_CB_NORMALIZE_IMAGE + cv::CALIB_CB_FAST_CHECK);
      if(found == true)
      {
        cv::cornerSubPix(gray_img, *corners, cv::Size(11, 11), cv::Size(-1, -1), cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::COUNT, 30, 0.1));
        cv::drawChessboardCorners(input_img, checker_size, *corners, found);
      }


    }

    float checkAngle(float rx, float ry)
    {
        return atan2(abs(rx), abs(ry))* 180 / M_PI;

    }

    void roll_by_checkered(cv::Mat capture_img_1, cv::Size inner_checker_size, vector<cv::Point2f> corners, float *value_roll)
    {
        // 가까운 이미지 기준 가로 선의 평행도
        // int idx_lefttop, idx_leftbottom, idx_righttop, idx_rightbottom = 0;
        // idx_lefttop = 0;
        // idx_righttop = inner_checker_size.width - 1;
        // idx_leftbottom = ((inner_checker_size.width) * (inner_checker_size.height - 1));
        // idx_rightbottom = ((inner_checker_size.width) * (inner_checker_size.height)) - 1;

        int idx_p_r = ((inner_checker_size.width) * ((int)inner_checker_size.height/2)) - 1;
        int idx_p_l = idx_p_r - inner_checker_size.width + 1;

        cv::Point2f p_l = corners.at(idx_p_l);
        cv::Point2f p_r = corners.at(idx_p_r);

        float ry = p_r.x - p_l.x;
        float rx = p_r.y - p_l.y;
//        float horizon_angle = checkAngle(rx, ry);
        *value_roll = checkAngle(rx, ry);
        cout << "roll : " << *value_roll << endl;

        circle(capture_img_1, corners[idx_p_l], 3, cv::Scalar(255,0,255), 5);
        circle(capture_img_1, corners[idx_p_r], 3, cv::Scalar(255,255,0), 5);

//        imshow("capture_img_1", capture_img_1);

    }

    float pixcel_per_mm_by_chessboard(vector<cv::Point2f>corners, cv::Size inner_checker_size, int chessboard_w_mm = 0)
    {
        float mm_in_one_pixcel;
        chessboard_w_mm = CHESSBOARD_W_MM;

        float mean = 0;
        int cnt = 0;
        for (int i = 1 ; i < (inner_checker_size.width * inner_checker_size.height); i ++)
        {
            int j = i - 1;

            mean += chessboard_w_mm/(corners[i].x - corners[j].x);
            cnt++;
        }

        mm_in_one_pixcel = mean/cnt;

        // cout << "1px = " << mean/cnt << endl;
        // cout << corners[1].x - corners[0].x << endl;

        return mm_in_one_pixcel;
    }

//    void tilt_by_checkered_cy(cv::Mat capture_img_1, cv::Size inner_checker_size, vector<cv::Point2f> corners_1)
//    {
//          // 이미지 한개를 이용하여 틸트 계산
//        // RX = 1 (정규이미지니까..)
//        // RY = cy - img_center_y

//        float rx = 1;
//        float ry = CY - (capture_img_1.cols/2);

//        float tilt = checkAngle(rx, ry);
//        cout << "tilt : " << tilt << endl;

//    }

    void tilt_by_checkered(cv::Mat capture_img_1, cv::Mat capture_img_2, cv::Size inner_checker_size, vector<cv::Point2f> corners_1, vector<cv::Point2f>corners_2, float *tilt)
    {
          // 이미지 두개를 이용하여 틸트 계산
        // RX = 두 체스보드 간 거리
        // RY = 이미지1과 이미지2의 같은 체스보드의 한 점의 Y 값의 차(높이)

        int idx_p_mid = (int)(inner_checker_size.width/2);

        float rx = D_TWO_CHESSBOARD;
        float ry = (corners_1[idx_p_mid].y - corners_2[idx_p_mid].y) * pixcel_per_mm_by_chessboard(corners_1, inner_checker_size);


        *tilt = checkAngle(ry, rx);
//        cout << "tilt : " << tilt << endl;

    }


};

#endif // CaptureImg_H
