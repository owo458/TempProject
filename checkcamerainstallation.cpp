#include "checkcamerainstallation.h"

checkCameraInstallation::checkCameraInstallation(cv::Mat input_img, float *value_roll_inPixel)
{
    checkCameraInstallation::img_center_x = input_img.cols/2;
    checkCameraInstallation::img_center_y = input_img.rows/2;

//    cout << input_img.cols << endl;
//    cout << input_img.rows << endl;

    checkCameraInstallation::checkCameraCalboardCenter(input_img, value_roll_inPixel);

    checkCameraInstallation::drawGrid(input_img);

}

