#ifndef MESUREMENT_HEIGHT_H
#define MESUREMENT_HEIGHT_H

#include <QWidget>
#include <QTimer>

#include "opencv4/opencv2/opencv.hpp"
#include "opencv4/opencv2/imgproc/imgproc.hpp"
#include "opencv4/opencv2/highgui/highgui.hpp"

using namespace std;

namespace Ui {
class mesurement_height;
}

class mesurement_height : public QWidget
{
    Q_OBJECT

public:
    explicit mesurement_height(QWidget *parent = nullptr);
    ~mesurement_height();

private slots:
    void update_window();

    void on_pushButton_2_clicked();

private:
    Ui::mesurement_height *ui;

    QTimer *timer;
    QImage qt_image;

    cv::VideoCapture cap;
    cv::Mat frame;
    cv::Mat resize_frame;

};

#endif // MESUREMENT_HEIGHT_H
