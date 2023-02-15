#ifndef INTRINSIC_PARAM_CALCULATE_H
#define INTRINSIC_PARAM_CALCULATE_H
#include <opencv2/opencv.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <iostream>
#include <fstream>




class intrinsic_param_calculate
{
public:
    intrinsic_param_calculate();
    int video2Mat(std::string path, int fps);
    int interCameraCalibration(int* chess_pattern);
    int autoCalibration(double& totalAvgErr);
    int reprojeactionError(double& totalAvgErr);
    double computeReprojectionErrors();
    int overlapRemove();
    int principalPointError();
    int saveResultsImg(std::string path);
    int reprojectionPattern(std::string path);
    int undistortTest(std::string path);
    int saveResultsTxt(std::string path);

private:
    cv::Mat m_cameraMatrix;
    cv::Mat m_distCoeffs;
    std::vector<cv::Mat> m_R, m_T;
    std::vector<cv::Mat> m_matImages;
    std::vector<std::vector<cv::Point3f>> m_objpoints;
    std::vector<std::vector<cv::Point2f>> m_imgpoints;
    std::vector<float> m_reprojErrs;
    cv::Size m_img_size;

};

#endif // INTRINSIC_PARAM_CALCULATE_H
