#ifndef CHECKCAMERAINSTALLATION_H
#define CHECKCAMERAINSTALLATION_H

#include "opencv4/opencv2/opencv.hpp"
#include "opencv4/opencv2/imgproc/imgproc.hpp"
#include "opencv4/opencv2/highgui/highgui.hpp"
#include "parameterinput.h"

using namespace std;

extern double g_CameraInstallPosition;

class checkCameraInstallation
{

public:
    checkCameraInstallation(cv::Mat input_img, float *value_roll_inPixel);


private:
    bool doFindChessboard = true;

    int img_search_x;

    int img_center_x;
    int img_center_y;

    float checkAngle(float rx, float ry)
    {
        return atan2(abs(rx), abs(ry))* 180 / M_PI;

    }

    float checkHorizontal(cv::Mat binary_img, vector<cv::Point> *corners, int img_search_x, int img_center_y, int roi_w, int roi_h, cv::Mat input_img)
    {

      float rtn_check = 99.f;

      int half_w = roi_w/2;
      int half_h = roi_h/2;

      int point = 0;
      int point_x = img_search_x-half_w;

      for (int i = 0; i < 3; i++)
      {
        for (int j = img_center_y-half_h; j < img_center_y+half_h; j++)
        {
          if (   (int)binary_img.at<uchar>(j-2, point_x) != (int)binary_img.at<uchar>(j+2, point_x) )
          {
              corners->push_back(cv::Point((int)point_x, (int)j));
              point++;
              break;
          }
        }
        point_x += half_w;
      }


      if (point == 3)
      {
        rtn_check = checkAngle(corners->at(0).y-corners->at(2).y, corners->at(0).x-corners->at(2).x);
      }

      return rtn_check;

    }

    float checkVertical(cv::Mat binary_img, vector<cv::Point> *corners, int img_search_x, int img_center_y, int roi_w, int roi_h, cv::Mat input_img)
    {
      int point = 0;
      float rtn_check = 99.f;

      int half_w = roi_w/2;
      int half_h = roi_h/2;

      int point_y = img_center_y-half_h;

      for (int i = 0; i < 3; i++)
      {
        for (int j = img_search_x-half_w; j < img_search_x+half_w; j++)
        {
          if (   (int)binary_img.at<uchar>(point_y, j-2) != (int)binary_img.at<uchar>(point_y, j+2) )
          {
              corners->push_back(cv::Point((int)j, (int)point_y));
              point++;
              break;
          }
        }
        point_y += half_h;
      }


      if (point == 3)
      {
        rtn_check = checkAngle(corners->at(2).x-corners->at(0).x, corners->at(2).y-corners->at(0).y);
      }

      return rtn_check;
    }

    void drawGrid(cv::Mat input_img)
    {
      cv::line(input_img, cv::Point(img_center_x, 0), cv::Point(img_center_x, input_img.rows), cv::Scalar(200, 200, 0), 2);
      cv::line(input_img, cv::Point(0, img_center_y), cv::Point(input_img.cols, img_center_y), cv::Scalar(0, 200, 200), 2);
    }

    void checkCameraCalboardCenter(cv::Mat input_img, float *value_roll_inPixel)
    {
        cv::Mat gray_img, binary_img;

        int thr = 120;
        cv::cvtColor(input_img, gray_img, cv::COLOR_BGR2GRAY);
        cv::threshold(gray_img, binary_img, thr, 255, cv::THRESH_BINARY);

        vector<cv::Point> corners_v, corners_h;
        int h_roi_w, h_roi_h, v_roi_w, v_roi_h;
        h_roi_w = binary_img.cols/5;
        h_roi_h = binary_img.rows/20;
        v_roi_w = binary_img.cols/20;
        v_roi_h = binary_img.rows/5;

        float check_h = checkHorizontal(binary_img, &corners_h, img_search_x, img_center_y, h_roi_w, h_roi_h, input_img);
        float check_v = checkVertical(binary_img, &corners_v, img_search_x, img_center_y, v_roi_w, v_roi_h, input_img);

        if (0)
        {
            cv::line(input_img, cv::Point(img_search_x-(h_roi_w/2), img_center_y-(h_roi_h/2)), cv::Point(img_search_x+(h_roi_w/2), img_center_y-(h_roi_h/2)), cv::Scalar(255,255,255),2);
            cv::line(input_img, cv::Point(img_search_x-(h_roi_w/2), img_center_y+(h_roi_h/2)), cv::Point(img_search_x+(h_roi_w/2), img_center_y+(h_roi_h/2)), cv::Scalar(255,255,255),2);
            cv::line(input_img, cv::Point(img_search_x-(v_roi_w/2), img_center_y-(v_roi_h/2)), cv::Point(img_search_x-(v_roi_w/2), img_center_y+(v_roi_h/2)), cv::Scalar(255,255,255),2);
            cv::line(input_img, cv::Point(img_search_x+(v_roi_w/2), img_center_y-(v_roi_h/2)), cv::Point(img_search_x+(v_roi_w/2), img_center_y+(v_roi_h/2)), cv::Scalar(255,255,255),2);
        }
        cv::Scalar lineColor_v, lineColor_h;

        if (check_v != 99)
        {
            lineColor_v = cv::Scalar(0, 255, 0);
            cv::line(input_img, cv::Point((corners_v.at(0).x-1), corners_v.at(0).y), cv::Point(corners_v.at(2).x, corners_v.at(2).y), lineColor_v, 8);
        }

        if (check_h != 99)
        {
            lineColor_h = cv::Scalar(255, 25, 0);
            cv::line(input_img, cv::Point((corners_h.at(0).x-1), corners_h.at(0).y), cv::Point(corners_h.at(2).x, corners_h.at(2).y), lineColor_h, 8);
        }


        *value_roll_inPixel = check_v;
        corners_v.clear();

    }


};




#endif // CHECKCAMERAINSTALLATION_H
