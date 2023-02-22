#ifndef CAMERAPOSEESTIMATION_H
#define CAMERAPOSEESTIMATION_H

#include <QWidget>
#include <opencv2/opencv.hpp>
#include <QMessageBox>
#include <fstream>

using namespace std;
using namespace cv;

extern float g_ChessboardCellSize;
extern int g_ChessboardSizeX;
extern int g_ChessboardSizeY;

namespace Ui {
class CameraPoseEstimation;
}

class CameraPoseEstimation : public QWidget
{
    Q_OBJECT

public:
    explicit CameraPoseEstimation(QWidget *parent = 0);
    ~CameraPoseEstimation();

private slots:
    void on_ExportButton_clicked();

private:
    Ui::CameraPoseEstimation *ui;

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
        *foundchessboard = cv::findChessboardCorners(grayImg, cv::Size(ChessboardSize.x, ChessboardSize.y), allCorner_pts);
        if(*foundchessboard == true)
        {
            cv::TermCriteria criteria(TermCriteria::EPS + TermCriteria::COUNT,100,0.001);
            int win_size = int((allCorner_pts[2].x - allCorner_pts[1].x)/2);
            cout << "win_size:" << win_size << endl;
            // findChessboardCorners에서 찾은 allCorner_pts에 저장된 픽셀들이 가리키는 위치를 더 정확하게 보정해주는 함수
            cv::cornerSubPix(grayImg, allCorner_pts, cv::Size(win_size, win_size), cv::Size(-1, -1), criteria);

            vector<float> AllcellSize;

            for (int i = 0; i < (int)allCorner_pts.size(); i++)
            {
                // corner draw
                circle(InputImg, allCorner_pts[i], 1, Scalar(255, 0, 0), 5);

                  //가로 길이 collect
                if (i % (ChessboardSize.x) != 0)
                {
                    AllcellSize.push_back(abs(allCorner_pts[i].x - allCorner_pts[i - 1].x));
                }

                  //세로 길이 collect
                if ((i >= (ChessboardSize.x)))
                {
                    AllcellSize.push_back(abs(allCorner_pts[i].y - allCorner_pts[i - (ChessboardSize.x)].y));
                }
            }

            float cnt = 0;

            for (int i = 0; i < (int)AllcellSize.size(); i++)
            {
                cnt += AllcellSize[i];
            }
            *avgCellPixelSize = cnt / AllcellSize.size();
            cout << "avgCellPixelSize                     : "<< *avgCellPixelSize << "[pixel]\n";
            circle(InputImg, Point(InputImg.cols / 2, InputImg.rows / 2), 1, Scalar(0, 0, 255), 5);
            putText(InputImg, "ImageCenter", Point((InputImg.cols / 2) +10, (InputImg.rows / 2) + 20), cv::FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 255), 2);

            chessboardCorner_pts.push_back(allCorner_pts[0]);
            chessboardCorner_pts.push_back(allCorner_pts[ChessboardSize.x-1]);
            chessboardCorner_pts.push_back(allCorner_pts[(ChessboardSize.x)*(ChessboardSize.y-1)]);
            chessboardCorner_pts.push_back(allCorner_pts[(ChessboardSize.x)*(ChessboardSize.y)-1]);

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
            msgBox.setWindowTitle("CameraPoseEstimation Error     ");
            msgBox.setText("Not Detection ChessBoard     ");
            msgBox.exec();
            this->close();
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
        corner_pts3D.push_back(Point3f(-(g_ChessboardSizeX-1)/2*g_ChessboardCellSize,distance,(g_ChessboardSizeY)*g_ChessboardCellSize));
        corner_pts3D.push_back(Point3f((g_ChessboardSizeX-1)/2*g_ChessboardCellSize,distance,(g_ChessboardSizeY)*g_ChessboardCellSize));
        corner_pts3D.push_back(Point3f(-(g_ChessboardSizeX-1)/2*g_ChessboardCellSize,distance,g_ChessboardCellSize));
        corner_pts3D.push_back(Point3f((g_ChessboardSizeX-1)/2*g_ChessboardCellSize,distance,g_ChessboardCellSize));

//        cout << corner_pts3D[0].x <<","<< corner_pts3D[0].y <<","<< corner_pts3D[0].z << endl;
//        cout << corner_pts3D[1].x <<","<< corner_pts3D[1].y <<","<< corner_pts3D[1].z << endl;
//        cout << corner_pts3D[2].x <<","<< corner_pts3D[2].y <<","<< corner_pts3D[2].z << endl;
//        cout << corner_pts3D[3].x <<","<< corner_pts3D[3].y <<","<< corner_pts3D[3].z << endl;
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

        for(float x = -50*(int)(g_ChessboardCellSize/10)*3; x<=50*(int)(g_ChessboardCellSize/10)*3; x+=50*(int)(g_ChessboardCellSize/10)) // 5cm
        {
            for(float y = distance; y<=50*100.0*(int)(g_ChessboardCellSize/10)*4; y+=50*(int)(g_ChessboardCellSize/10))
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

    void drawAxis(Mat image, Mat* R, Mat* T, Mat* cameraIntrinsicParameter, Mat* cameraDistortionCoefficient,float distance)
    {
        cout << "distance :" << distance << endl;
        vector<Point3f> OriginPoint;
        OriginPoint.push_back({0,distance,0});
        vector<Point2f> reProjectionOriginPoint;
        projectPoints(OriginPoint, *R, *T, *cameraIntrinsicParameter, *cameraDistortionCoefficient,reProjectionOriginPoint);
//        circle(image,reProjectionOriginPoint[0],5,Scalar(255,0,255),5);
//        cout << "test : " << reProjectionOriginPoint[0] << endl;
        vector<Point3f> axis;
        axis.push_back({2*g_ChessboardCellSize,distance,0});
        axis.push_back({0,distance+2*g_ChessboardCellSize,0});
        axis.push_back({0,distance,2*g_ChessboardCellSize});

        vector<Point2f> imgpts;
        projectPoints(axis, *R, *T, *cameraIntrinsicParameter, *cameraDistortionCoefficient, imgpts);

        line(image,reProjectionOriginPoint[0],imgpts[0],Scalar(255,0,0),5); // x : blue
        line(image,reProjectionOriginPoint[0],imgpts[1],Scalar(0,255,0),5); // y : Green
        line(image,reProjectionOriginPoint[0],imgpts[2],Scalar(0,0,255),5); // z : red

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

    vector<string> split(string input, char delimiter)
    {
        vector<string> result;
        stringstream ss(input);
        string tmp;

        while (getline(ss, tmp, delimiter)) result.push_back(tmp);

        return result;
    }

    void readText(double arr[],string str,string *flePath)
    {
        std::ifstream file(*flePath);

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


};

#endif // CAMERAPOSEESTIMATION_H
