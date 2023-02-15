#include "checkcamerainstallation.h"


checkCameraInstallation::checkCameraInstallation(cv::Mat input_img, float *value_roll_inPixel)
{
    checkCameraInstallation::img_center_x = input_img.cols/2;
    checkCameraInstallation::img_center_y = input_img.rows/2;

    checkCameraInstallation::img_search_x = input_img.cols/2 - g_CameraInstallPosition;

    if (g_CameraInstallPosition != 0)
    {
        cv::line(input_img, cv::Point(img_search_x, 0), cv::Point(img_search_x, input_img.rows), cv::Scalar(200, 200, 200), 2);
    }

    checkCameraInstallation::checkCameraCalboardCenter(input_img, value_roll_inPixel);

    checkCameraInstallation::drawGrid(input_img);

}

