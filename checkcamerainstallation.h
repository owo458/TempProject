#ifndef CHECKCAMERAINSTALLATION_H
#define CHECKCAMERAINSTALLATION_H

#include "opencv4/opencv2/opencv.hpp"
#include "opencv4/opencv2/imgproc/imgproc.hpp"
#include "opencv4/opencv2/highgui/highgui.hpp"
#include "parameterinput.h"

using namespace std;


class checkCameraInstallation
{

public:
    checkCameraInstallation(cv::Mat input_img, float *value_roll_inPixel);

private:
    int img_center_x;
    int img_center_y;
//    float value_roll_inPixel;

    float checkAngle(float rx, float ry)
    {
        // cout << rx << endl;
        // cout << ry << endl;
        // cout << atan2(ry, rx) * 180 / M_PI << endl;
        // cout << pc_l << endl;
        // cout << pc_r << endl;

        return atan2(abs(rx), abs(ry))* 180 / M_PI;

    }

    float checkVertical(cv::Mat binary_img, vector<cv::Point> *corners, int img_center_x, int img_center_y, int roi_w, int roi_h, cv::Mat input_img)
    {
      // vector<Point> corners;
      int point = 0;
      // int total_points = 0;
      // int rtn_check = -1;
      float rtn_check = 99.f;

    //      cv::Mat roi_img;

      // left
      // x1 = img_center_x-half_w;
      // x2 = img_center_x;
      // x3 = img_center_x+half_w;

      int half_w = roi_w/2;
      int half_h = roi_h/2;

      int point_y = img_center_y-half_h;

      for (int i = 0; i < 3; i++)
      {
        for (int j = img_center_x-half_w; j < img_center_x+half_w; j++)
        {
          if (   (int)binary_img.at<uchar>(point_y, j-2) != (int)binary_img.at<uchar>(point_y, j+2) )
          {
    //              circle(input_img, Point(j, point_y), 1, Scalar(0,255,0), 1);
              corners->push_back(cv::Point((int)j, (int)point_y));
              point++;
              break;
          }
        }
        point_y += half_h;
      }



      if (point == 3)
      {
    //        cv::Scalar lineColor;
        // float a1 = checkAngle(corners->at(0).x-corners->at(1).x, corners->at(0).y-corners->at(1).y);
        // float a2 = checkAngle(corners->at(point-1).x-corners->at(1).x, corners->at(point-1).y-corners->at(1).y);
        // rtn_check = (a1+a2)/2;
        rtn_check = checkAngle(corners->at(2).x-corners->at(0).x, corners->at(2).y-corners->at(0).y);
//        cout << "rtn_check : " << rtn_check << endl;
        // float test = checkAngle((corners->at(0).x-1)-corners->at(1).x, corners->at(0).y-corners->at(1).y);
        // cout << "Vertical : " << a1 << " " << a2 << endl;
        // cout << "test : " << test << endl;


        // if (a1 == 0 && a2 == 0)
    //    if (rtn_check == 0)
    //    {
    //      lineColor = Scalar(0, 255, 0);
    //      rtn_check = 1;
    //    }
    //    else
    //    {
    //      lineColor = Scalar(200, 200, 0);
    //      rtn_check = 0;
    //    }

        // line(input_img, Point(corners->at(0).x, corners->at(0).y), Point(corners->at(1).x, corners->at(1).y), lineColor, 1);
        // line(input_img, Point(corners->at(1).x, corners->at(1).y), Point(corners->at(2).x, corners->at(2).y), lineColor, 1);
    //        line(input_img, Point(corners->at(0).x, corners->at(0).y), Point(corners->at(2).x, corners->at(2).y), lineColor, 1);


        // lineColor = Scalar(200, 0, 0);
        // line(input_img, Point((corners.at(0).x-1), corners.at(0).y), Point(corners.at(1).x, corners.at(1).y), lineColor, 2);

      }

    //      roi_img = input_img(Rect(Point(img_center_x-roi_w, img_center_y-roi_h), Point(img_center_x+roi_w, img_center_y+roi_h)));
    //      imshow("roi_img_h", roi_img);

      // corners.clear();
//      cout << "rtn_check : " << rtn_check << endl;
      return rtn_check;
    }

    void drawGrid(cv::Mat input_img)
    {
      // int x_mid, y_mid;
      // x_mid = (int)input_img.cols/2;
      // y_mid = (int)input_img.rows/2;
      cv::line(input_img, cv::Point(img_center_x, 0), cv::Point(img_center_x, input_img.rows), cv::Scalar(200, 200, 0), 2);
      cv::line(input_img, cv::Point(0, img_center_y), cv::Point(input_img.cols, img_center_y), cv::Scalar(0, 200, 200), 2);
    }

    void checkCameraCalboardCenter(cv::Mat input_img, float *value_roll_inPixel)
    {
    //        cv::putText(input_img, "camera check", cv::Point(100, 100), 3, 3, cv::Scalar(255));
        cv::Mat gray_img, binary_img;
    //        int img_center_x = input_img.cols/2 - (camera_location);
    //        int img_center_y = input_img.rows/2;
    //        int img_center_x = 1920/2;
    //        int img_center_y = 1080/2;

        int thr = 120;
        cv::cvtColor(input_img, gray_img, cv::COLOR_BGR2GRAY);
        cv::threshold(gray_img, binary_img, thr, 255, cv::THRESH_BINARY);

         // 가까운 이미지
    //    int check_h = checkHorizontal(binary_img, img_center_x, img_center_y, 300, 40, input_img);
        vector<cv::Point> corners_v;
        float check_v = checkVertical(binary_img, &corners_v, img_center_x, img_center_y, 40, 300, input_img);

        if (check_v == 99)
        {
            //fail
        }
        else
        {
            cv::Scalar lineColor;
            if (check_v == 0)
            {
                lineColor = cv::Scalar(0, 255, 0);
            }
            else
            {
                lineColor = cv::Scalar(180, 180, 0);
            }

            cv::line(input_img, cv::Point((corners_v.at(0).x-1), corners_v.at(0).y), cv::Point(corners_v.at(2).x, corners_v.at(2).y), lineColor, 8);
        }


        *value_roll_inPixel = check_v;
        corners_v.clear();

    //        cv::imshow("binary_img", binary_img);

//        cout << value_roll_inPixel << endl;

    }


};




#endif // CHECKCAMERAINSTALLATION_H
