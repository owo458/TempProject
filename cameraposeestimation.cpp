#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <QMessageBox>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
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

vector<cv::Point2f> get2DPointsinChessboard(Mat InputImg, float *avgCellPixelSize, float *Gap_Y,float *Gap_X,Point2i ChessboardSize, bool * foundchessboard)
{
    Mat grayImg;
    if (InputImg.empty() == 0)
    {
        cvtColor(InputImg, grayImg, COLOR_RGB2GRAY);
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("IMAGE Error     ");
        msgBox.setText("     InputImg Empty     ");
        msgBox.exec();
    }

    vector<cv::Point2f> allCorner_pts;
    vector<cv::Point2f> chessboardCorner_pts;
    *foundchessboard = cv::findChessboardCorners(grayImg, cv::Size(ChessboardSize.x - 1, ChessboardSize.y - 1), allCorner_pts);

    if(*foundchessboard == true)
    {
        cv::TermCriteria criteria(TermCriteria::EPS + TermCriteria::COUNT,100,0.001);

        // findChessboardCorners에서 찾은 allCorner_pts에 저장된 픽셀들이 가리키는 위치를 더 정확하게 보정해주는 함수
        cv::cornerSubPix(grayImg, allCorner_pts, cv::Size(11, 11), cv::Size(-1, -1), criteria);

        vector<float> AllcellSize;

        for (int i = 0; i < (int)allCorner_pts.size(); i++)
        {
            // corner draw
            circle(InputImg, allCorner_pts[i], 1, Scalar(255, 0, 0), 5);

              //가로 길이 collect
            if (i % (ChessboardSize.x - 1) != 0)
            {
                AllcellSize.push_back(abs(allCorner_pts[i].x - allCorner_pts[i - 1].x));
            }

              //세로 길이 collect
            if ((i >= (ChessboardSize.x - 1)))
            {
                AllcellSize.push_back(abs(allCorner_pts[i].y - allCorner_pts[i - (ChessboardSize.x-1)].y));
            }
        }

        float cnt = 0;

        for (int i = 0; i < (int)AllcellSize.size(); i++)
        {
            cnt += AllcellSize[i];
        }
        *avgCellPixelSize = cnt / AllcellSize.size();
        circle(InputImg, Point(InputImg.cols / 2, InputImg.rows / 2), 1, Scalar(0, 0, 255), 5);
        putText(InputImg, "ImageCenter", Point((InputImg.cols / 2) +10, (InputImg.rows / 2) + 20), cv::FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 255), 2);

        chessboardCorner_pts.push_back(allCorner_pts[0]);
        chessboardCorner_pts.push_back(allCorner_pts[ChessboardSize.x-2]);
        chessboardCorner_pts.push_back(allCorner_pts[(ChessboardSize.x-1)*(ChessboardSize.y-2)]);
        chessboardCorner_pts.push_back(allCorner_pts[(ChessboardSize.x-1)*(ChessboardSize.y-1)-1]);

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

        float cross_x = (((((x1*y2)-(y1*x2))*(x3-x4))-((x1-x2)*((x3*y4)-(y3*x4)))) / (((x1-x2)*(y3-y4))-((y1-y2)*(x3-x4))));
        float cross_y = (((((x1*y2)-(y1*x2))*(y3-y4))-((y1-y2)*((x3*y4)-(y3*x4)))) / (((x1-x2)*(y3-y4))-((y1-y2)*(x3-x4))));

        circle(InputImg, Point(cross_x, cross_y), 1, Scalar(0, 255, 0), 5);
        putText(InputImg, "ChessboardCenter", Point(cross_x + 10, cross_y - 10), cv::FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 2);


        *Gap_Y = cross_y - InputImg.rows / 2;
        *Gap_X = cross_x - InputImg.cols/2;

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
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Chessboard Error     ");
        msgBox.setText("Not Detection ChessBoard     ");
        msgBox.exec();
    }
    return chessboardCorner_pts;
}

vector<cv::Point3f> get3DPointsinChessboard(float distance, float avgCellSize,float CellSize)
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

    for(float x = -(int)(distance/3000)*100.0*15; x<=(int)(distance/3000)*100.0*15; x+=500)
    {
        for(float y = distance-3000; y<=10*100.0*1500; y+=500)
        {
            ReprojectionAllPoint3D.push_back(Point3f(x,y,0));
        }
    }

    Layer.push_back(ReprojectionAllPoint3D.size());

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

    vector<Point3f> axis;
    axis.push_back({240,0,0});
    axis.push_back({0,240,0});
    axis.push_back({0,0,240});

    vector<Point2f> imgpts;
    projectPoints(axis, *R, *T, *cameraIntrinsicParameter, *cameraDistortionCoefficient, imgpts);

    line(image,reProjectionOriginPoint[0],imgpts[0],Scalar(255,0,0),5); // x : blue
    line(image,reProjectionOriginPoint[0],imgpts[1],Scalar(0,255,0),5); // y : Green
    line(image,reProjectionOriginPoint[0],imgpts[2],Scalar(0,0,255),5); // z : red

}

vector<string> split(string input, char delimiter)
{
    vector<string> result;
    stringstream ss(input);
    string tmp;

    while (getline(ss, tmp, delimiter)) result.push_back(tmp);

    return result;
}


void readText(double arr[],string str,string flePath)
{
    std::ifstream file(flePath);

    bool name = false;
    bool startPoint = false;

    int count = 0;

    if (file.is_open())
    {
        string line;

        while(getline(file, line))
        {
            if (line[0] == '=' && startPoint == false)
            {
                startPoint = true;
            }

            else if (line[0] == '=' && startPoint == true)
            {
                startPoint = false;
                name = false;
            }

            if (line == str)
            {
                name = true;
            }

            if (startPoint == true && name == true)
            {
                if(line[0]!='=')
                {
                    vector<string> result = split(line,' ');

                    for (int i = 0; i < int(result.size()); i++)
                    {
                        arr[count] = stod(result[i]);
                        count++;
                    }
                }

            }

        }
        file.close();
    }
}




void saveText(string *SaveText, cv::Mat Matrix, int rows, int columns, string MatrixName, vector<string> ParameterName = {"Null","Null","Null"})
{
    *SaveText += MatrixName;
    *SaveText += "\n======================================================================================\n";
    for(int row=0; row<rows; row++)
    {
        if (ParameterName[row] !="Null")
        {
            *SaveText += ParameterName[row];
            *SaveText += " = ";
        }
        for(int column=0; column< columns; column++)
        {
            *SaveText += to_string(Matrix.at<double>(row,column));
            *SaveText += " ";
        }
            *SaveText += "\n";
    }
    *SaveText += "======================================================================================\n\n";
}

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
        rawImg = imread("./3m.png");
    }
    else
    {
        rawImg = CameraPoseCapture_1;
    }

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

    readText(A_data,"[CameraIntrinsicMatrix]",IntrinsicParameterPath);

    double B_data[5]={-0.449579000000000006398437335520,      0.185104999999999991766586049380,       0.000366000000000000005884182031,       -0.000989999999999999994587662755,      -0.077037999999999995370814076523};
    readText(B_data,"[DistortionCoefficient]",IntrinsicParameterPath);

    Mat cameraIntrinsicParameter(3,3,CV_64FC1,A_data);
    //cout << "cameraIntrinsicParameter : " << cameraIntrinsicParameter << endl;

    Mat cameraDistortionCoefficient(5,1,CV_64FC1,B_data);
    //cout << "cameraDistortionCoefficient : " << cameraDistortionCoefficient << endl;

    printf("%s[2D Point : PixelCoordinates]%s\n","\033[33m","\033[39m");
    printf("======================================================================================\n");
    corner2DImgPoint = get2DPointsinChessboard(PointDetectionImg, &avgCellPixelSizeInChessboard, &CameraCenterAndChessboardCenterGap_y,&CameraCenterAndChessboardCenterGap_x,ChessboardSize,&foundchessboard);
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
