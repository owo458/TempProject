#include "checkcamerainstallation.h"

checkCameraInstallation::checkCameraInstallation(cv::Mat input_img, float *value_roll_inPixel)
{
    checkCameraInstallation::img_center_x = input_img.cols/2;
    checkCameraInstallation::img_center_y = input_img.rows/2;

//    cout << input_img.cols << endl;
//    cout << input_img.rows << endl;

    checkCameraInstallation::checkCameraCalboardCenter(input_img, value_roll_inPixel);

    checkCameraInstallation::drawGrid(input_img);


//    if (!tmpFrame_1.empty() && !tmpFrame_2.empty() && doFindChessboard)
//    {
//        tmpFrame_1.copyTo(capturedFrame_1);
//        tmpFrame_2.copyTo(capturedFrame_2);
//        doFindChessboard = false;

//        //계산~~~

//        // 끝나면 doFindChessboard = true
//    }

}

