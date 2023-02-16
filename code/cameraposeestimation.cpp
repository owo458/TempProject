#include "captureimg.h"
#include "cameraposeestimation.h"
#include "ui_cameraposeestimation.h"

#define CAMERA_LOCATION_X (0)

using namespace cv;
using namespace std;

extern double g_CarWidth;
extern double g_CarHeight;
extern double g_CameraToBumper;
extern double g_CameraInstallPosition;
extern float g_ChessboardCellSize;
extern int g_ChessboardSizeX;
extern int g_ChessboardSizeY;
extern float g_CarToChessboard_1;
extern float g_CarToChessboard_2;
extern string IntrinsicParameterPath;

string ExportText = "";

extern Mat CameraPoseCapture_1;


CameraPoseEstimation::CameraPoseEstimation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CameraPoseEstimation)
{
    ui->setupUi(this);

    ExportText += "[InputParameter]\n";
    ExportText += "======================================================================================\n";
    ExportText += "CarWidth : "+to_string(g_CarWidth) +" m\n";
    ExportText += "CarHeight : "+to_string(g_CarHeight) +" m\n";
    ExportText += "CameraToBumper : "+to_string(g_CameraToBumper) +" m\n";
    ExportText += "CameraInstallPosition : "+to_string(g_CameraInstallPosition) +" mm\n";
    ExportText += "ChessboardCellSize : "+to_string(g_ChessboardCellSize) +" mm\n";
    ExportText += "ChessboardSize : ["+to_string(g_ChessboardSizeX)+","+ to_string(g_ChessboardSizeY)+"]\n";
    ExportText += "CarToChessboardDistance : "+to_string(g_CarToChessboard_1) +" m\n";
    ExportText += "======================================================================================\n\n";

    Mat rawImg;
    if (CameraPoseCapture_1.empty())
    {
        rawImg = imread(":/image/image/3m_sample_image.png");
    }
    else
    {
        rawImg = CameraPoseCapture_1;
        cvtColor(rawImg,rawImg,COLOR_BGR2RGB);
    }
//    imshow("test",rawImg);
//    waitKey(0);
    Mat PointDetectionImg;
    Mat resize_PointDetectionImg;

    rawImg.copyTo(PointDetectionImg);
    float avgCellPixelSizeInChessboard = 0.0;
    float CameraCenterAndChessboardCenterGap_y = 0.0;
    float CameraCenterAndChessboardCenterGap_x = 0.0;
    bool foundchessboard =false;
    Point2i ChessboardSize = {g_ChessboardSizeX,g_ChessboardSizeY};
    vector<Point2f> corner2DImgPoint;
    vector<Point3f> corner3DImgPoint;

    double A_data[9]={2019.918599999999969440978020429611,    0.000000000000000000000000000000,       966.024700000000052568793762475252,
                      0.000000000000000000000000000000,       2015.861000000000103682396002113819,    538.629900000000020554580260068178,
                      0.000000000000000000000000000000,       0.000000000000000000000000000000,       1.000000000000000000000000000000};

    readText(A_data,"[CameraIntrinsicMatrix]",&IntrinsicParameterPath);

    double B_data[5]={-0.449579000000000006398437335520,      0.185104999999999991766586049380,       0.000366000000000000005884182031,       -0.000989999999999999994587662755,      -0.077037999999999995370814076523};
    readText(B_data,"[DistortionCoefficient]",&IntrinsicParameterPath);

    Mat cameraIntrinsicParameter(3,3,CV_64FC1,A_data);
    //cout << "cameraIntrinsicParameter : " << cameraIntrinsicParameter << endl;

    Mat cameraDistortionCoefficient(5,1,CV_64FC1,B_data);
    //cout << "cameraDistortionCoefficient : " << cameraDistortionCoefficient << endl;

    printf("%s[2D Point : PixelCoordinates]%s\n","\033[33m","\033[39m");
    printf("======================================================================================\n");
    corner2DImgPoint = get2DPointsinChessboard(PointDetectionImg, &avgCellPixelSizeInChessboard, &CameraCenterAndChessboardCenterGap_y,&CameraCenterAndChessboardCenterGap_x,ChessboardSize,&foundchessboard);
    if(foundchessboard == false)
    {
        return;
    }
    circle(PointDetectionImg,Point2f(cameraIntrinsicParameter.at<double>(0,2),cameraIntrinsicParameter.at<double>(1,2)),1,Scalar(0,255,255),5);
    putText(PointDetectionImg, "PrincipalPoint", Point(cameraIntrinsicParameter.at<double>(0,2)+10,cameraIntrinsicParameter.at<double>(1,2)-10), cv::FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 255), 2);
    printf("======================================================================================\n\n");

    printf("%s[3D Point : WorldCoordinates]%s\n","\033[33m","\033[39m");
    printf("======================================================================================\n");
    float TargetDistance = g_CarToChessboard_1*1000;
    corner3DImgPoint = get3DPointsinChessboard(TargetDistance,avgCellPixelSizeInChessboard, g_ChessboardCellSize);
    printf("======================================================================================\n\n");

    /*************************/
    cv::resize(PointDetectionImg,resize_PointDetectionImg,Size(PointDetectionImg.cols/3,PointDetectionImg.rows/3));
    cvtColor(resize_PointDetectionImg,resize_PointDetectionImg,COLOR_BGR2RGB);

    QImage qt_PointImg;
    qt_PointImg = QImage((const unsigned char*) (resize_PointDetectionImg.data), resize_PointDetectionImg.cols, resize_PointDetectionImg.rows, QImage::Format_RGB888);

    ui->PointImg->setScaledContents(true);
    ui->PointImg->setPixmap(QPixmap::fromImage(qt_PointImg));

    /*************************/

    // RTMatrix----------------------------------------------------------------------------------------------------------------------
    Mat R(3, 3, CV_64FC1);
    Mat R_inv(3,3,CV_64FC1);
    Mat T(3, 1, CV_64FC1);
    Mat rvec, tvec;

    /* Calculate R vector and T vector using 4 points(Word Point 4 point, Img Point 4 point) */
    solvePnP(corner3DImgPoint, corner2DImgPoint, cameraIntrinsicParameter, cameraDistortionCoefficient, rvec, tvec);

    /* Convert 3x1 R vector to 3x3 R vector */
    Rodrigues(rvec, R);
    R_inv = R.inv();
    T = tvec;

    QString QS_RMatrix = QString::fromStdString(str_matrix(R,3,3));
    ui->R_Matrix_text->setText(QS_RMatrix);
    saveText(&ExportText, R,R.rows,R.cols,"[Rotation Matrix]");
    saveText(&ExportText, R_inv,R_inv.rows,R_inv.cols,"[Rotation_inv Matrix]");

    QString QS_TMatrix = QString::fromStdString(str_matrix(T,3,1));
    ui->T_Matrix_text->setText(QS_TMatrix);
    saveText(&ExportText, T,T.rows,T.cols,"[Translation Matrix]");

     /* 앞에서 지정한 World좌표의 원점과 Camera의 World좌표변환을 위한 R|T 행렬*/
    printf("%s[Rotation Matrix]%s\n","\033[33m","\033[39m");
    print_matrix(R, R.rows, R.cols);
    printf("%s[Rotation_inv Matrix]%s\n","\033[33m","\033[39m");
    print_matrix(R_inv, R_inv.rows, R_inv.cols);
    printf("%s[Translation Matrix]%s\n","\033[33m","\033[39m");
    print_matrix(T, T.rows, T.cols);

    /* World Coordinator Origin Point Draw*/
    drawAxis(PointDetectionImg,&R,&T,&cameraIntrinsicParameter,&cameraDistortionCoefficient);

    /* ReprojectionPoint Draw*/
    drawReprojectionPoint(&PointDetectionImg,&R,&T,&cameraIntrinsicParameter,&cameraDistortionCoefficient,TargetDistance);

    /*************************/

    Mat resize_ReprojectionImg;
    cv::resize(PointDetectionImg,resize_ReprojectionImg,Size(PointDetectionImg.cols/3,PointDetectionImg.rows/3));
    cvtColor(resize_ReprojectionImg,resize_ReprojectionImg,COLOR_BGR2RGB);

    QImage qt_ReprojectionImg;
    qt_ReprojectionImg = QImage((const unsigned char*) (resize_ReprojectionImg.data), resize_ReprojectionImg.cols, resize_ReprojectionImg.rows, QImage::Format_RGB888);
    ui->ReProjectionImg->setScaledContents(true);
    ui->ReProjectionImg->setPixmap(QPixmap::fromImage(qt_ReprojectionImg));

    /*************************/

    /* Reprojection using R and T vector */

    vector<Point2f> reProjectionPoint;

    projectPoints(corner3DImgPoint, R, T, cameraIntrinsicParameter, cameraDistortionCoefficient, reProjectionPoint);

    double normPixelError = 0;
    double error_x = 0;
    double xErrorSum = 0;
    double yErrorSum = 0;
    double error_y = 0;

    for (int i = 0; i < (int)reProjectionPoint.size(); i++)
    {
        error_x = fabs(corner2DImgPoint[i].x - reProjectionPoint[i].x);
        xErrorSum += error_x;

        error_y = fabs(corner2DImgPoint[i].y - reProjectionPoint[i].y);
        yErrorSum += error_y;
    }

    normPixelError = norm(corner2DImgPoint, reProjectionPoint, NORM_L2) / (double)reProjectionPoint.size();



    printf("%s[World 3D Reprojection Error]%s\n","\033[33m","\033[39m");
    printf("======================================================================================\n");
    printf("meanPixelError_x : %lf\nmeanPixelError_y : %lf\nnormPixelError : %lf\n", xErrorSum / (double)reProjectionPoint.size(), yErrorSum / (double)reProjectionPoint.size(), normPixelError);
    printf("======================================================================================\n\n");

    double ReprojectionParameter[3] = {xErrorSum / (double)reProjectionPoint.size(), yErrorSum / (double)reProjectionPoint.size(), normPixelError};
    Mat ReprojectionMatrix(3, 1, CV_64FC1,ReprojectionParameter);
    vector<string> ReprojectionParameter_text = {"meanPixelError_x","meanPixelError_y","normPixelError"};
    saveText(&ExportText, ReprojectionMatrix,ReprojectionMatrix.rows,ReprojectionMatrix.cols,"[World 3D Reprojection Error]",ReprojectionParameter_text);


    QString QS_meanPixelError_x= QString::fromStdString(to_string(xErrorSum / (double)reProjectionPoint.size()));
    ui->meanPixelError_x_text->setText(QS_meanPixelError_x);

    QString QS_meanPixelError_y= QString::fromStdString(to_string(yErrorSum / (double)reProjectionPoint.size()));
    ui->meanPixelError_y_text->setText(QS_meanPixelError_y);

    QString QS_normPixelError= QString::fromStdString(to_string(normPixelError));
    ui->normPixelError_text->setText(QS_normPixelError);

    /* CameraWorldPoint */
    Mat CameraPoint = -R_inv * T;
    double *p = (double *)CameraPoint.data;

    printf("%s[CameraPointInWorld]%s\n","\033[33m","\033[39m");
    printf("======================================================================================\n");
    printf("X = %.5lf\nY = %.5lf\nZ = %.5lf\n", p[0], p[1], p[2]);
    printf("======================================================================================\n\n");

    QString QS_X= QString::fromStdString(to_string(p[0]));
    ui->X_text->setText(QS_X);

    QString QS_Y= QString::fromStdString(to_string(p[1]));
    ui->Y_text->setText(QS_Y);

    QString QS_Z= QString::fromStdString(to_string(p[2]));
    ui->Z_text->setText(QS_Z);

    vector<string> CameraPointInWorld_text = {"X","Y","Z"};
    saveText(&ExportText, CameraPoint,CameraPoint.rows,CameraPoint.cols,"[CameraPointInWorld]",CameraPointInWorld_text);

    /* CameraPoseEstimate */
    double unit_z[] = {0, 0, 1};
    Mat Zc(3, 1, CV_64FC1, unit_z);

    // world coordinate of optical axis
    Mat Zw = R_inv * Zc;
    double *zw = (double *)Zw.data;

    double pan = atan2(zw[1], zw[0]) - CV_PI / 2;

    double tilt = atan2(zw[2], sqrt(zw[0] * zw[0] + zw[1] * zw[1]));

    double unit_x[] = {1, 0, 0};

    Mat Xc(3, 1, CV_64FC1, unit_x);

    // world coordinate of camera X axis
    Mat Xw = R_inv * Xc;

    double *xw = (double *)Xw.data;

    double xpan[] = {cos(pan), sin(pan), 0};

    double roll = acos(xw[0] * xpan[0] + xw[1] * xpan[1] + xw[2] * xpan[2]); // inner product

    if (xw[2] < 0)
    {
        roll = -roll;
    }

    printf("%s[CameraPose]%s\n","\033[33m","\033[39m");
    printf("======================================================================================\n");
    printf("TILT = %.5lf deg \nYAW = %.5lf deg\nROLL = %.5lf deg\n", tilt * 180 / CV_PI, pan * 180 / CV_PI, roll * 180 / CV_PI);
    printf("======================================================================================\n\n");

    QString QS_TILT= QString::fromStdString(to_string(tilt * 180 / CV_PI));
    ui->TILT_text->setText(QS_TILT);

    QString QS_PAN= QString::fromStdString(to_string(pan * 180 / CV_PI));
    ui->PAN_text->setText(QS_PAN);

    QString QS_ROLL= QString::fromStdString(to_string(roll * 180 / CV_PI));
    ui->ROLL_text->setText(QS_ROLL);

    double CameraPoseParameter[3] = {tilt * 180 / CV_PI, pan * 180 / CV_PI, roll * 180 / CV_PI};
    Mat CameraPoseMatrix(3, 1, CV_64FC1,CameraPoseParameter);

    vector<string> CameraPoseParameter_text = {"Tilt(Pich)","Pan(yaw)","Roll"};
    saveText(&ExportText, CameraPoseMatrix,CameraPoseMatrix.rows,CameraPoseMatrix.cols,"[CameraPose]",CameraPoseParameter_text);
}

CameraPoseEstimation::~CameraPoseEstimation()
{
    delete ui;
}

void CameraPoseEstimation::on_ExportButton_clicked()
{
    std::ofstream file("./ExtrinsicParameter.txt");

    if (file.is_open())
    {
        file << ExportText;
        file.close();
    }

    QMessageBox msgBox;
    msgBox.setWindowTitle("Complete     ");
    msgBox.setText("Save ExtrinsicParameter.txt      ");
    msgBox.exec();
}
