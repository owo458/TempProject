#include "cameraposeestimation.h"
#include "ui_cameraposeestimation.h"
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include "captureimg.h"

using namespace cv;
using namespace std;

extern float a;
extern string str1;
extern string str2;
extern string str3;

extern Mat CameraPoseCapture_1;
extern Mat CameraPoseCapture_2;

vector<cv::Point2f> get2DPointsinChessboard(Mat InputImg, float *avgCellPixelSize, float *Gap_Y,float *Gap_X,Point2i ChessboardSize)
{

    printf("ChessboardSize                       : (%dx%d)\n", ChessboardSize.x,ChessboardSize.y);
    Mat grayImg;
    cvtColor(InputImg, grayImg, COLOR_RGB2GRAY);

    vector<cv::Point2f> allCorner_pts;
    vector<cv::Point2f> chessboardCorner_pts;
    cv::findChessboardCorners(grayImg, cv::Size(ChessboardSize.x - 1, ChessboardSize.y - 1), allCorner_pts);
    //cout << "CornerPoint1 : " << allCorner_pts <<endl;

    cv::TermCriteria criteria(TermCriteria::EPS + TermCriteria::COUNT,100,0.001);
    // findChessboardCorners에서 찾은 allCorner_pts에 저장된 픽셀들이 가리키는 위치를 더 정확하게 보정해주는 함수
    cv::cornerSubPix(grayImg, allCorner_pts, cv::Size(11, 11), cv::Size(-1, -1), criteria);
    //cout << "CornerPoint2 : " << allCorner_pts <<endl;

    vector<float> AllcellSize;

    for (int i = 0; i < (int)allCorner_pts.size(); i++)
    {
        // corner draw
        circle(InputImg, allCorner_pts[i], 1, Scalar(255, 0, 0), 5);
        //printf("Cell[%d] : (%f,%f)\n",i,allCorner_pts[i].x,allCorner_pts[i].y);
        //가로 길이 collect
        if (i % (ChessboardSize.x - 1) != 0)
        {
            //printf("Cell_Size_x[%d - %d] : %f\n",i,i-1,allCorner_pts[i].x-allCorner_pts[i-1].x);
            AllcellSize.push_back(abs(allCorner_pts[i].x - allCorner_pts[i - 1].x));
        }

        //세로 길이 collect
        if ((i >= (ChessboardSize.x - 1)))
        {
            //printf("Cell_Size_y[%d - %d] : %f\n",i,i-(ChessboardSize.x-1),allCorner_pts[i].y-allCorner_pts[i-(ChessboardSize.x-1)].y);
            AllcellSize.push_back(abs(allCorner_pts[i].y - allCorner_pts[i - (ChessboardSize.x-1)].y));
        }
    }



    //printf("AllcellSizeCount : %d\n",(int)AllcellSize.size());

    float cnt = 0;

    for (int i = 0; i < (int)AllcellSize.size(); i++)
    {
        cnt += AllcellSize[i];
        //cout << "AllcellSize : " << AllcellSize[i] << endl;

    }
    *avgCellPixelSize = cnt / AllcellSize.size();
    printf("avgCellPixelSize                     : %f [pixel]\n", *avgCellPixelSize);

    printf("ImageCenterPoint                     : (%lf, %lf)\n", (float)InputImg.cols / 2, (float)InputImg.rows / 2);
    circle(InputImg, Point(InputImg.cols / 2, InputImg.rows / 2), 1, Scalar(0, 0, 255), 5);
    putText(InputImg, "ImageCenter", Point((InputImg.cols / 2) +10, (InputImg.rows / 2) + 20), cv::FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 255), 2);

    chessboardCorner_pts.push_back(allCorner_pts[0]);
    chessboardCorner_pts.push_back(allCorner_pts[ChessboardSize.x-2]);
    chessboardCorner_pts.push_back(allCorner_pts[(ChessboardSize.x-1)*(ChessboardSize.y-2)]);
    chessboardCorner_pts.push_back(allCorner_pts[(ChessboardSize.x-1)*(ChessboardSize.y-1)-1]);

    // float x1 = allCorner_pts[9].x;
    // float y1 = allCorner_pts[9].y;

    // float x2 = allCorner_pts[80].x;
    // float y2 = allCorner_pts[80].y;

    // float x3 = allCorner_pts[0].x;
    // float y3 = allCorner_pts[0].y;

    // float x4 = allCorner_pts[89].x;
    // float y4 = allCorner_pts[89].y;

    float x1 = chessboardCorner_pts[0].x;
    float y1 = chessboardCorner_pts[0].y;

    float x2 = chessboardCorner_pts[3].x;
    float y2 = chessboardCorner_pts[3].y;

    float x3 = chessboardCorner_pts[1].x;
    float y3 = chessboardCorner_pts[1].y;

    float x4 = chessboardCorner_pts[2].x;
    float y4 = chessboardCorner_pts[2].y;

    drawMarker(InputImg,Point2f(x1,y1),Scalar(0,0,255),1,20,3);
    putText(InputImg, "Point[0]", Point(x1 + 10, y1 - 10), cv::FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 2);
    drawMarker(InputImg,Point2f(x2,y2),Scalar(0,0,255),1,20,3);
    putText(InputImg, "Point[1]", Point(x3 + 10, y3 - 10), cv::FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 2);
    drawMarker(InputImg,Point2f(x3,y3),Scalar(0,0,255),1,20,3);
    putText(InputImg, "Point[2]", Point(x4 + 10, y4 - 10), cv::FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 2);
    drawMarker(InputImg,Point2f(x4,y4),Scalar(0,0,255),1,20,3);
    putText(InputImg, "Point[3]", Point(x2 + 10, y2 - 10), cv::FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 2);

    // cout  << "x1,y1 : " << x1 <<","<< y1 << endl;
    // cout  << "x2,y2 : " << x2 <<","<< y2 << endl;
    // cout  << "x3,y3 : " << x3 <<","<< y3 << endl;
    // cout  << "x4,y4 : " << x4 <<","<< y4 << endl;

    float cross_x = (((((x1*y2)-(y1*x2))*(x3-x4))-((x1-x2)*((x3*y4)-(y3*x4)))) / (((x1-x2)*(y3-y4))-((y1-y2)*(x3-x4))));
    float cross_y = (((((x1*y2)-(y1*x2))*(y3-y4))-((y1-y2)*((x3*y4)-(y3*x4)))) / (((x1-x2)*(y3-y4))-((y1-y2)*(x3-x4))));

    // cout  << "cross_x : " << cross_x << endl;
    // cout  << "cross_y : " << cross_y << endl;

    //cross_y -=*avgCellPixelSize; //Camera height만큼 빼준다.
    circle(InputImg, Point(cross_x, cross_y), 1, Scalar(0, 255, 0), 5);

    //putText(InputImg, "CameraHeightPoint", Point(cross_x + 10, cross_y - 10), cv::FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 2);
    //printf("CameraHeightPoint                    : (%f,%f)\n",cross_x,cross_y);

    putText(InputImg, "ChessboardCenter", Point(cross_x + 10, cross_y - 10), cv::FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 2);
    printf("ChessboardCenterPoint                : (%f, %f)\n",cross_x,cross_y);


    *Gap_Y = cross_y - InputImg.rows / 2;
    // Gap의 값이 '+' => Tilt = - => camera가 아래를 보고 있다.
    // Gap의 값이 '-' => Tilt = + => camera가 위쪽을 보고 있다.
    // printf("ImageCenter_y - CameraHeightPoint_y  : %lf [pixel]\n", *Gap_Y);

    *Gap_X = cross_x - InputImg.cols/2;

    // Gap_X의 값이 '+' => camera가 Target Point를 바라보고 왼쪽으로 치우쳐 있다.
    // Gap_X의 값이 '-' => camera가 Target Point를 바라보고 오른쪽으로 치우쳐 있다.
    // printf("ImageCenter_x - CameraHeightPoint_x  : %lf [pixel]\n",*Gap_X);

    if (chessboardCorner_pts[0].x > chessboardCorner_pts[3].x)
    {
        Point2f tmp = Point2f(0,0);
        tmp = chessboardCorner_pts[0];
        chessboardCorner_pts[0] = chessboardCorner_pts[3];
        chessboardCorner_pts[3] = tmp;
    }

    if (chessboardCorner_pts[2].x > chessboardCorner_pts[1].x)
    {
        Point2f tmp = Point2f(0,0);
        tmp = chessboardCorner_pts[2];
        chessboardCorner_pts[2] = chessboardCorner_pts[1];
        chessboardCorner_pts[1] = tmp;
    }

    printf("2D Point[LeftTop]                    : (%lf, %lf) \n", chessboardCorner_pts[0].x, chessboardCorner_pts[0].y);
    printf("2D Point[RightTop]                   : (%lf, %lf) \n", chessboardCorner_pts[1].x, chessboardCorner_pts[1].y);
    printf("2D Point[LeftBottom]                 : (%lf, %lf) \n", chessboardCorner_pts[2].x, chessboardCorner_pts[2].y);
    printf("2D Point[RightBottom]                : (%lf, %lf) \n", chessboardCorner_pts[3].x, chessboardCorner_pts[3].y);

    return chessboardCorner_pts;
}

vector<cv::Point3f> get3DPointsinChessboard(Mat rawImg, float distance, vector<Point2f> corner2DImgPoint, float avgCellSize, float Gap_Y,float Gap_X,float CellSize)
{
    float PixelPerMilliMeter = CellSize / avgCellSize;
    printf("PixelPerMilliMeter                   : %f [mm]\n", PixelPerMilliMeter);

    /*************************************************************
    World좌표는 Camera광축이 시작되는 지점을 0,0,0으로 설정
    좌표계의 경우 광축방향을 Y, 좌우 방향을 X, 위아래 방향을 Z로 설정하였음.
    Y축은 광축방향이 +
    X축은 우측방향이 +
    Z축은 하늘방향이 +
    *************************************************************/

    vector<cv::Point3f> corner_pts3D;

    /* Sample/sample1, sample2로 하였을 때 */
    // 카메라가 땅에 닿아있는 부분을 원점으로 하였을 때
    corner_pts3D.push_back(Point3f(-280.0,distance,700.0+65.0));
    corner_pts3D.push_back(Point3f(280.0,distance,700.0+65.0));
    corner_pts3D.push_back(Point3f(-280.0,distance,70.0+65.0));
    corner_pts3D.push_back(Point3f(280.0,distance,70.0+65.0));

    /**************************************************/
    printf("3D Point[LeftTop]                    : (%f[mm], %f[mm], %f[mm]) \n", corner_pts3D[0].x, corner_pts3D[0].y, corner_pts3D[0].z);
    printf("3D Point[RightTop]                   : (%f[mm], %f[mm], %f[mm]) \n", corner_pts3D[1].x, corner_pts3D[1].y, corner_pts3D[1].z);
    printf("3D Point[LeftBottom]                 : (%f[mm], %f[mm], %f[mm]) \n", corner_pts3D[2].x, corner_pts3D[2].y, corner_pts3D[2].z);
    printf("3D Point[RightBottom]                : (%f[mm], %f[mm], %f[mm]) \n", corner_pts3D[3].x, corner_pts3D[3].y, corner_pts3D[3].z);

    return corner_pts3D;
}

void print_matrix(cv::Mat Matrix, int rows, int columns)
{
    printf("======================================================================================\n");
    for (int row=0; row<rows; row++) {
        for (int column=0; column < columns; column++) {
            printf("%8.30f,\t", Matrix.at<double>(row,column));
        }
        printf("\n");
    }
    printf("======================================================================================\n\n");
}

String str_matrix(cv::Mat Matrix, int rows, int columns)
{
    String str;
    for (int row=0; row<rows; row++) {
        for (int column=0; column < columns; column++) {
            str+=to_string(Matrix.at<double>(row,column)) + "  ";
        }
        str+="\n";
    }

    return str;
}

void drawReprojectionPoint(Mat* image, Mat* R, Mat* T, Mat* cameraIntrinsicParameter, Mat* cameraDistortionCoefficient, float distance)
{
    vector<Point3f> ReprojectionAllPoint3D;
    vector<int> Layer;
    Layer.push_back(0);

    // for(float z = 0.0; z<=2.0*100*10; z+=500.0)
    // for(float z = 0.0; z<=12000; z+=11900.0)
    {
        for(float x = -(int)(distance/3000)*100.0*15; x<=(int)(distance/3000)*100.0*15; x+=500)
        {
            for(float y = distance-3000; y<=10*100.0*1500; y+=500)
            {
                ReprojectionAllPoint3D.push_back(Point3f(x,y,0));
            }
        }
        //cout << "OriOri.size() : " << ReprojectionAllPoint3D.size() <<endl;
        Layer.push_back(ReprojectionAllPoint3D.size());
    }

    //cout << "ReprojectionAllPoint3D : "<<ReprojectionAllPoint3D << endl;

    vector<Point2f> ReprojectionAllPoint2D;

    projectPoints(ReprojectionAllPoint3D, *R, *T, *cameraIntrinsicParameter, *cameraDistortionCoefficient, ReprojectionAllPoint2D);

    int k = 0;
    Scalar Colorman = Scalar(255,0,255);
    for(int i = 0; i <int(ReprojectionAllPoint2D.size()); i++)
    {
        circle(*image,ReprojectionAllPoint2D[i],2,Colorman,2);

        if ((Layer[k] <= i) && (i < Layer[k+1]-1))
        {
            circle(*image,ReprojectionAllPoint2D[i],2,Colorman,2);
        }
        else
        {
            k+=1;
            if (k%3==0)
            {
                Colorman = Scalar(255,0,255);
            }
            else if (k%3==1)
            {
                Colorman = Scalar(0,255,255);
            }
            else if (k%3==2)
            {
                Colorman = Scalar(255,255,0);
            }
        }
    }

}


void drawAxis(Mat image, Mat* R, Mat* T, Mat* cameraIntrinsicParameter, Mat* cameraDistortionCoefficient)
{

    vector<Point3f> OriginPoint;
    OriginPoint.push_back({0,0,0});
    vector<Point2f> reProjectionOriginPoint;
    projectPoints(OriginPoint, *R, *T, *cameraIntrinsicParameter, *cameraDistortionCoefficient,reProjectionOriginPoint);

    //cout << "reProjectionOriginPoint : " << reProjectionOriginPoint << endl;

    vector<Point3f> axis;
    axis.push_back({240,0,0});
    axis.push_back({0,240,0});
    axis.push_back({0,0,240});

    vector<Point2f> imgpts;
    projectPoints(axis, *R, *T, *cameraIntrinsicParameter, *cameraDistortionCoefficient, imgpts);

    line(image,reProjectionOriginPoint[0],imgpts[0],Scalar(255,0,0),5); // x : blue
    line(image,reProjectionOriginPoint[0],imgpts[1],Scalar(0,255,0),5); // y : Green
    line(image,reProjectionOriginPoint[0],imgpts[2],Scalar(0,0,255),5); // z : red

    // Mat resizeResult;
    // resize(image,resizeResult,Size(1920/2,1080/2));
    // imshow("draw axis",resizeResult);
    // imwrite("draw axis.png",resizeResult);
}
CameraPoseEstimation::CameraPoseEstimation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CameraPoseEstimation)
{
    ui->setupUi(this);

    cout << "Camera Off" << endl;
    float CarWidth = stof(str1);
    float CameraHeight = stof(str2);
    float CameraToBumper = stof(str3);
    cout << "CarWidth :" << CarWidth <<"m"<< endl;
    cout << "CameraHeight :" << CameraHeight <<"m"<< endl;
    cout << "CameraToBumper :" << CameraToBumper <<"m"<< endl;
    Mat rawImg = imread("/home/server/e_calibration/3m.png");
    //Mat rawImg = CameraPoseCapture_1;
    Mat PointDetectionImg;
    Mat resize_PointDetectionImg;

    rawImg.copyTo(PointDetectionImg);
    float avgCellPixelSizeInChessboard = 0.0;
    float CameraCenterAndChessboardCenterGap_y = 0.0;
    float CameraCenterAndChessboardCenterGap_x = 0.0;

    Point2i ChessboardSize = {10,11};
    vector<Point2f> corner2DImgPoint;
    vector<Point3f> corner3DImgPoint;

    double A_data[9] = {2019.9186,0.0,966.0247,0.0,2015.8610,538.6299,0.0,0.0,1.0}; //VFe34 Car - matlab
    Mat cameraIntrinsicParameter(3,3,CV_64FC1,A_data);
    double B_data[5] = {-0.449579,0.185105,0.000366,-0.000990,-0.077038};
    Mat cameraDistortionCoefficient(5,1,CV_64FC1,B_data);
    printf("%s[2D Point : PixelCoordinates]%s\n","\033[33m","\033[39m");
    printf("======================================================================================\n");
    corner2DImgPoint = get2DPointsinChessboard(PointDetectionImg, &avgCellPixelSizeInChessboard, &CameraCenterAndChessboardCenterGap_y,&CameraCenterAndChessboardCenterGap_x,ChessboardSize);
    circle(PointDetectionImg,Point2f(cameraIntrinsicParameter.at<double>(0,2),cameraIntrinsicParameter.at<double>(1,2)),1,Scalar(0,255,255),5);
    putText(PointDetectionImg, "PrincipalPoint", Point(cameraIntrinsicParameter.at<double>(0,2)+10,cameraIntrinsicParameter.at<double>(1,2)-10), cv::FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 255), 2);
    printf("======================================================================================\n\n");

    printf("%s[3D Point : WorldCoordinates]%s\n","\033[33m","\033[39m");
    printf("======================================================================================\n");
    float TargetDistance = 4483.0;
    float chessboardCellSize = 70.0;
    corner3DImgPoint = get3DPointsinChessboard(PointDetectionImg, TargetDistance, corner2DImgPoint, avgCellPixelSizeInChessboard, CameraCenterAndChessboardCenterGap_y,CameraCenterAndChessboardCenterGap_x,chessboardCellSize);
    printf("======================================================================================\n\n");

    /*************************/
    //Qimg_PointDetection
    //cv::imshow("test",tmpFrame_1);
    //cv::waitKey(0);
    cv::resize(PointDetectionImg,resize_PointDetectionImg,Size(PointDetectionImg.cols/3,PointDetectionImg.rows/3));
    cvtColor(resize_PointDetectionImg,resize_PointDetectionImg,COLOR_BGR2RGB);

    QImage qt_PointImg;
    qt_PointImg = QImage((const unsigned char*) (resize_PointDetectionImg.data), resize_PointDetectionImg.cols, resize_PointDetectionImg.rows, QImage::Format_RGB888);
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
    // double B_data[9] = {1.0        ,0.0       ,0.0,
    //     0.0,       0.0,        1.0,
    //     0.0,        1.0,        0.0};
    // Mat B(3, 3, CV_64FC1, B_data);
    // R = B;

    Rodrigues(rvec, R);
    R_inv = R.inv();
    T = tvec;


    QString QS_RMatrix = QString::fromStdString(str_matrix(R,3,3));
    ui->R_Matrix_text->setText(QS_RMatrix);

    QString QS_TMatrix = QString::fromStdString(str_matrix(T,3,1));
    ui->T_Matrix_text->setText(QS_TMatrix);

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
    //Qimg_DrawReprojectionImg
    Mat resize_ReprojectionImg;
    cv::resize(PointDetectionImg,resize_ReprojectionImg,Size(PointDetectionImg.cols/3,PointDetectionImg.rows/3));
    cvtColor(resize_ReprojectionImg,resize_ReprojectionImg,COLOR_BGR2RGB);

    QImage qt_ReprojectionImg;
    qt_ReprojectionImg = QImage((const unsigned char*) (resize_ReprojectionImg.data), resize_ReprojectionImg.cols, resize_ReprojectionImg.rows, QImage::Format_RGB888);
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
        // std::cout << "World point : " << corner3DImgPoint1[i] << " Image point : " << corner2DImgPoint1[i] << " Reprojection point : " << reProjectionPoint1[i] << std::endl;
        error_x = fabs(corner2DImgPoint[i].x - reProjectionPoint[i].x);
        xErrorSum += error_x;
        // printf("x[%d] pixel error : %lf\t",i,error_x);

        error_y = fabs(corner2DImgPoint[i].y - reProjectionPoint[i].y);
        yErrorSum += error_y;
        // printf("y[%d] pixel error : %lf\n\n",i,error_y);
    }

    normPixelError = norm(corner2DImgPoint, reProjectionPoint, NORM_L2) / (double)reProjectionPoint.size();



    printf("%s[World 3D Reprojection Error]%s\n","\033[33m","\033[39m");
    printf("======================================================================================\n");
    printf("meanPixelError_x : %lf\nmeanPixelError_y : %lf\nnormPixelError : %lf\n", xErrorSum / (double)reProjectionPoint.size(), yErrorSum / (double)reProjectionPoint.size(), normPixelError);
    printf("======================================================================================\n\n");

    //double ReprojectionParameter[3] = {xErrorSum / (double)reProjectionPoint.size(), yErrorSum / (double)reProjectionPoint.size(), normPixelError};
    //Mat ReprojectionMatrix(3, 1, CV_64FC1,ReprojectionParameter);


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

//    double CameraPoseParameter[3] = {tilt * 180 / CV_PI, pan * 180 / CV_PI, roll * 180 / CV_PI};
//    Mat CameraPoseMatrix(3, 1, CV_64FC1,CameraPoseParameter);
//    QString QS_CameraPoseMatrix = QString::fromStdString(str_matrix(CameraPoseMatrix,3,1));
//    ui->CameraPosition_text->setText(QS_CameraPoseMatrix);

}

CameraPoseEstimation::~CameraPoseEstimation()
{
    delete ui;
}
