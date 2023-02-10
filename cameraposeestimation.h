#ifndef CAMERAPOSEESTIMATION_H
#define CAMERAPOSEESTIMATION_H

#include <QWidget>
#include <opencv2/opencv.hpp>

namespace Ui {
class CameraPoseEstimation;
}

class CameraPoseEstimation : public QWidget
{
    Q_OBJECT

public:
    explicit CameraPoseEstimation(QWidget *parent = 0);
    ~CameraPoseEstimation();

private:
    Ui::CameraPoseEstimation *ui;
};

#endif // CAMERAPOSEESTIMATION_H
