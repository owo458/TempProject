#include "checkcamerainstallation.h"

checkCameraInstallation::checkCameraInstallation(cv::Mat input_img, float *value_roll_inPixel)
{
//    cv::imshow("input", input_img);
    checkCameraInstallation::img_center_x = input_img.cols/2;
    checkCameraInstallation::img_center_y = input_img.rows/2;
//    checkCameraInstallation::value_roll_inPixel = *mesurement_height::value_roll_inPixel;

//    cout << img_center_x << endl;


    checkCameraInstallation::checkCameraCalboardCenter(input_img, value_roll_inPixel);

//    cout << "rtn_check : " << *value_roll_inPixel << endl;
    checkCameraInstallation::drawGrid(input_img);
//    *mesurement_height::value_roll_inPixel = checkCameraInstallation::value_roll_inPixel

}
