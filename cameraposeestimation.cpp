#include "cameraposeestimation.h"
#include "ui_cameraposeestimation.h"

CameraPoseEstimation::CameraPoseEstimation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CameraPoseEstimation)
{
    ui->setupUi(this);
}

CameraPoseEstimation::~CameraPoseEstimation()
{
    delete ui;
}
