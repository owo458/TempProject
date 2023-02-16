#include "intrinsic_param_calculate.h"

intrinsic_param_calculate::intrinsic_param_calculate()
{
    m_cameraMatrix=cv::Mat::zeros(3, 3, CV_32F);
    std::cout <<std::setprecision(10);
}

int intrinsic_param_calculate::video2Mat(std::string path, int fps)
{
  cv::VideoCapture cap;
  cap.open(path);
  if (!cap.isOpened())
  {
    printf("Can't open the video");
    return -1;
  }
  cv::Mat img;
  int frame_num = 0;
  std::cout << "video_start : "<< path << std::endl;
  while (1)
  {
    cap >> img;

    if (img.empty())
    {
      std::cout << "empty image " << std::endl;
      break;
    }
    if (frame_num % int(30/fps) == 0)
    {
      m_img_size = img.size();
      cv::Mat mat_tmp;
      img.copyTo(mat_tmp);
      m_matImages.push_back(mat_tmp);
    }
    frame_num++;
  }
  std::cout << "video_end!" << std::endl;
  return 1;
}


int intrinsic_param_calculate::interCameraCalibration(int* chess_pattern)
{
  std::vector<cv::Point3f> objp;
  for (int i = 0; i < chess_pattern[1]; i++)
  {
    for (int j = 0; j < chess_pattern[0]; j++)
      objp.push_back(cv::Point3f(j, i, 0));
  }
  cv::Mat frame, gray;
  std::vector<cv::Point2f> corner_pts;
  bool success;
  for (uint i = 0; i < m_matImages.size(); i++)
  {
    frame = m_matImages[i].clone();
    cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
    success = cv::findChessboardCorners(gray, cv::Size(chess_pattern[0], chess_pattern[1]), corner_pts);
    if (success)
    {

      //cv::TermCriteria criteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 30, 0.001);
      cv::TermCriteria criteria(cv::TermCriteria::EPS + cv::TermCriteria::COUNT,100,0.001);

      cv::cornerSubPix(gray, corner_pts, cv::Size(11, 11), cv::Size(-1, -1), criteria);
      cv::drawChessboardCorners(frame, cv::Size(chess_pattern[0], chess_pattern[1]), corner_pts, success);
      m_objpoints.push_back(objp);
      m_imgpoints.push_back(corner_pts);
      //imshow("frame", frame);
      //cv::waitKey(100);
    }
    else
    {
      m_matImages.erase(m_matImages.begin() + i);
      i--;
    }
  }
  cv::destroyAllWindows();
  std::cout << "interCameraCalibration end!" << std::endl;
  return 1;
}

int intrinsic_param_calculate::autoCalibration(double& totalAvgErr){
    int check = 0;
    int reprojecterrorProcess = 0;
    int overlapRemoveProcess = 0;
    std::cout << "matImages : " << m_matImages.size() << std::endl;

    while (totalAvgErr > 0.3 && m_matImages.size() > 20)
    {
      cv::calibrateCamera(m_objpoints, m_imgpoints, m_img_size, m_cameraMatrix, m_distCoeffs, m_R, m_T, 0);
      reprojecterrorProcess = reprojeactionError(totalAvgErr);
      std::cout << "matImages(reprojecterror) : " << m_matImages.size() << std::endl;

      if (check == 0)
      {
        overlapRemoveProcess = overlapRemove();
        std::cout << "matImages(overlapRemove) : " << m_matImages.size() << std::endl;
        check++;
      }
    }
    std::cout << "autoCalibration end!" << std::endl;
    return reprojecterrorProcess + overlapRemoveProcess;
}


int intrinsic_param_calculate::reprojeactionError(double &totalAvgErr)
{

  totalAvgErr = computeReprojectionErrors();
  std::cout << "totalAvgErr : " << totalAvgErr << std::endl;

  for (uint i = 0; i < m_matImages.size(); i++)
  {
    if (m_reprojErrs[i] > totalAvgErr)
    {
      m_matImages.erase(m_matImages.begin() + i);
      m_objpoints.erase(m_objpoints.begin() + i);
      m_imgpoints.erase(m_imgpoints.begin() + i);
      m_reprojErrs.erase(m_reprojErrs.begin() + i);
      m_T.erase(m_T.begin() + i);
      m_R.erase(m_R.begin() + i);
      i--;
    }
  }
  std::cout << "reprojeactionError end!" << std::endl;
  return totalAvgErr;
}


double intrinsic_param_calculate::computeReprojectionErrors()
{

  std::vector<cv::Point2f> imagePoints2;
  int i, totalPoints = 0;
  double totalErr = 0, err;
  //std::vector<float>  perViewErrors;
  m_reprojErrs.resize(m_objpoints.size());

  for (i = 0; i < (int)m_objpoints.size(); i++)
  {
    projectPoints(cv::Mat(m_objpoints[i]), m_R[i], m_T[i],
                  m_cameraMatrix, m_distCoeffs, imagePoints2);
    err = cv::norm(cv::Mat(m_imgpoints[i]), cv::Mat(imagePoints2), cv::NORM_L2);
    int n = (int)m_objpoints[i].size();
    m_reprojErrs[i] = (float)std::sqrt(err * err / n);
    totalErr += err * err;
    totalPoints += n;
  }
  std::cout << "computeReprojectionErrors end!" << std::endl;
  return std::sqrt(totalErr / totalPoints);
}


int intrinsic_param_calculate::overlapRemove()
{

  double distance = 0.0;
  cv::Mat R_temp, T_temp;
  std::vector<cv::Mat> pose_temp;

  for (uint i = 0; i < m_matImages.size(); i++)
  {
    R_temp = m_R[i];
    T_temp = m_T[i];
    Rodrigues(T_temp, R_temp);
    cv::Mat R_inv = R_temp.inv();
    cv::Mat P = -R_inv * T_temp;
    // double *p = (double *)P.data;
    pose_temp.push_back(P);
  }

  for (uint i = 0; i < m_matImages.size(); i++)
  {
    for (uint j = i + 1; j < m_matImages.size(); j++)
    {

      double *p = (double *)pose_temp[i].data;
      double *p2 = (double *)pose_temp[j].data;
      uint remove = 0;
      distance = sqrt(pow(p[0] - p2[0], 2) + pow(p[1] - p2[1], 2) + pow(p[2] - p2[2], 2));
      if (distance < 1)
      {
        if (m_reprojErrs[i] > m_reprojErrs[j])
        {
          remove = i;
        }
        else
        {
          remove = j;
        }
        m_matImages.erase(m_matImages.begin() + remove);
        m_objpoints.erase(m_objpoints.begin() + remove);
        m_imgpoints.erase(m_imgpoints.begin() + remove);
        m_reprojErrs.erase(m_reprojErrs.begin() + remove);
        m_T.erase(m_T.begin() + remove);
        m_R.erase(m_R.begin() + remove);
        pose_temp.erase(pose_temp.begin() + remove);

        if (remove == i)
        {
          i--;
          break;
        }
        else
        {
          j--;
          continue;
        }
      }
    }
  }
  std::cout << "overlapRemove end!" << std::endl;
  return 1;
}


int intrinsic_param_calculate::reprojectionPattern(std::string path)
{
  int height = 500;
  int width = 300;
  cv::Mat viewer_img = cv::Mat::zeros(height, width, CV_32FC3);

  cv::line(viewer_img, cv::Point(0, 480), cv::Point(300, 480), cv::Scalar(255, 255, 255), 1, 8);   // 가로 0  (150, 480) == (0,0)
  cv::line(viewer_img, cv::Point(150, 0), cv::Point(150, 500), cv::Scalar(255, 255, 255), 1, 8);   // 세로 0
  cv::line(viewer_img, cv::Point(140, 80), cv::Point(160, 80), cv::Scalar(255, 255, 255), 1, 8);   // 가로 400
  cv::line(viewer_img, cv::Point(140, 180), cv::Point(160, 180), cv::Scalar(255, 255, 255), 1, 8); // 가로 300
  cv::line(viewer_img, cv::Point(140, 280), cv::Point(160, 280), cv::Scalar(255, 255, 255), 1, 8); // 가로 200
  cv::line(viewer_img, cv::Point(140, 380), cv::Point(160, 380), cv::Scalar(255, 255, 255), 1, 8); // 가로 100
  cv::line(viewer_img, cv::Point(100, 490), cv::Point(100, 470), cv::Scalar(255, 255, 255), 1, 8); // 세로 -100
  cv::line(viewer_img, cv::Point(200, 490), cv::Point(200, 470), cv::Scalar(255, 255, 255), 1, 8); // 세로 100
  cv::line(viewer_img, cv::Point(50, 490), cv::Point(50, 470), cv::Scalar(255, 255, 255), 1, 8);   // 세로 -200
  cv::line(viewer_img, cv::Point(250, 490), cv::Point(250, 470), cv::Scalar(255, 255, 255), 1, 8); // 세로 200

  cv::Mat R_temp, T_temp;
  for (uint i = 0; i < m_R.size(); i++)
  {
    R_temp = m_R[i];
    T_temp = m_T[i];
    Rodrigues(T_temp, R_temp);
    cv::Mat R_inv = R_temp.inv();
    cv::Mat P = -R_inv * T_temp;
    double *p = (double *)P.data;
    //printf("x=%lf  y=%lf  z=%lf\n", p[0], p[1], p[2]);

    if (fabs(((p[0] * 10) / 2)) > 150 || fabs((p[2] * 10)) > 480)
    {
      cv::circle(viewer_img, cv::Point(150 - ((i * 10) / 2), 490), 5, cv::Scalar(0, 0, 255), 1);
    }
    else
    {
      cv::circle(viewer_img, cv::Point(150 - ((p[0] * 10) / 2), 480 + (p[2] * 10)), 5, cv::Scalar(0, 255, 0), 1);
    }
  }
  std::cout << "end !" << std::endl;

  char buffer[256];
  sprintf(buffer, "%s/chess_pose.png", path.c_str());

  cv::imwrite(buffer, viewer_img);
  std::cout << "reprojectionPattern end!" << std::endl;
  return 1;
}


int intrinsic_param_calculate::principalPointError(){
    if (fabs((m_img_size.height / 2) - m_cameraMatrix.at<double>(1, 2)) > 30 || fabs((m_img_size.width / 2) - m_cameraMatrix.at<double>(0, 2)) > 30)
    {
      std::cout << "principalPointError cx error " << m_cameraMatrix.at<double>(0, 2) << std::endl;
      std::cout << "principalPointError cy error " << m_cameraMatrix.at<double>(1, 2) << std::endl;
      return -1;
    }
    return 1;
}

int intrinsic_param_calculate::undistortTest(std::string path)
{
  char buffer[256];
  for(uint i=0; i<m_matImages.size(); i++){
    cv::Mat frame = m_matImages[i].clone();
    cv::Mat temp = frame.clone();
    cv::Mat map1, map2;

    initUndistortRectifyMap(m_cameraMatrix, m_distCoeffs, cv::Mat(), m_cameraMatrix, m_matImages[i].size(), CV_32FC1, map1, map2);
    remap(frame, temp, map1, map2, cv::INTER_LINEAR);

    for(int k=0; k < m_matImages[i].size().height; k=10+k){
      cv::line(frame, cv::Point(0, k), cv::Point(1920, k), cv::Scalar(0, 255, 0), 1, 8);
      cv::line(temp, cv::Point(0, k), cv::Point(1920, k), cv::Scalar(0, 255, 0), 1, 8);
    }
    sprintf(buffer, "%s/distort_%03d.png", path.c_str(), i);
    cv::imwrite(buffer, frame);
    sprintf(buffer, "%s/undistort_%03d.png", path.c_str(), i);
    cv::imwrite(buffer, temp);
  }
  //cv::Size imageSize = cv::Size(1920, 1080);

  //imshow("org", frame);
  //imshow("Undistort", temp);
  std::cout << "undistortTest end!" << std::endl;
  return 1;
}

int intrinsic_param_calculate::saveResultsImg(std::string path){
  char buffer[256];
  for (uint i = 0; i < m_matImages.size(); i++)
  {
    sprintf(buffer, "%s/%03d.png", path.c_str(), i);
    cv::Mat frame = m_matImages[i];
    cv::imwrite(buffer, frame);
  }std::cout << "saveResultsImg end!" << std::endl;
  return 1;
}

int intrinsic_param_calculate::saveResultsTxt(std::string path){
    //char buffer[256];
    //sprintf(buffer, "%s/inParam.txt", path.c_str());

    std::string file_path= path + "/inParam.txt" ;
    std::ofstream writeFile(file_path.data());
    //writeFile<<std::fixed << setprecision(10) << std:: endl;
    writeFile.precision(10);
    writeFile << std::fixed;
    if( writeFile.is_open() ){
        writeFile << "[CameraIntrinsicMatrix]\n";
        writeFile << "======================================================================================\n";
        writeFile << m_cameraMatrix.at<double>(0, 0) << ", " << m_cameraMatrix.at<double>(0, 1) << ", " << m_cameraMatrix.at<double>(0, 2) << "\n";
        writeFile << m_cameraMatrix.at<double>(1, 0) << ", " << m_cameraMatrix.at<double>(1, 1) << ", " << m_cameraMatrix.at<double>(1, 2) << "\n";
        writeFile << m_cameraMatrix.at<double>(2, 0) << ", " << m_cameraMatrix.at<double>(2, 1) << ", " << m_cameraMatrix.at<double>(2, 2) << "\n";
        writeFile << "======================================================================================\n\n";

        writeFile << "[DistortionCoefficient]\n";
        writeFile << "======================================================================================\n";
        writeFile << m_distCoeffs.at<double>(0, 0) << ", " << m_distCoeffs.at<double>(0, 1) << ", " << m_distCoeffs.at<double>(0, 2) << ", "
                  << m_distCoeffs.at<double>(0, 3) << ", " << m_distCoeffs.at<double>(0, 4) << "\n";
        writeFile << "======================================================================================\n";

        std::cout << "[CameraIntrinsicMatrix]"<<std::endl;
        std::cout << "======================================================================================"<<std::endl;
        std::cout << m_cameraMatrix.at<double>(0, 0) << ", " << m_cameraMatrix.at<double>(0, 1) << ", " << m_cameraMatrix.at<double>(0, 2) << std::endl;
        std::cout << m_cameraMatrix.at<double>(1, 0) << ", " << m_cameraMatrix.at<double>(1, 1) << ", " << m_cameraMatrix.at<double>(1, 2) << std::endl;
        std::cout << m_cameraMatrix.at<double>(2, 0) << ", " << m_cameraMatrix.at<double>(2, 1) << ", " << m_cameraMatrix.at<double>(2, 2) << std::endl;
        std::cout << "======================================================================================"<<std::endl;
        std::cout << "[DistortionCoefficient]"<<std::endl;
        std::cout << "======================================================================================"<<std::endl;
        std::cout << m_distCoeffs.at<double>(0, 0) << ", " << m_distCoeffs.at<double>(0, 1) << ", " << m_distCoeffs.at<double>(0, 2) << ", "
                  << m_distCoeffs.at<double>(0, 3) << ", " << m_distCoeffs.at<double>(0, 4) << std::endl;
        std::cout << "======================================================================================"<<std::endl;

        writeFile.close();
    }
    return 1;
}


