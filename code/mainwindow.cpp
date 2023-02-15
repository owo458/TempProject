#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QString sModulePath = QCoreApplication::applicationDirPath();
//    sModulePath += "/image/Logo.png";
//    QPixmap pixmap(sModulePath);
//    cout << sModulePath.toStdString() << endl;
    QPixmap pixmap("./image/Logo.png");
    QPixmap fitpixmap=pixmap.scaled(700, 350, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->LogoImg->setPixmap(fitpixmap);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushbtn_extrinsic_clicked()
{
    this->second_dialog = new ParameterInput(this);
    this->second_dialog->show();
}
void MainWindow::on_pushbtn_intrinsic_clicked()
{
    this->intrinsic_param_cal_dialog = new intrinsic_param(this);
    this->intrinsic_param_cal_dialog->show();
    std::cout<<"show"<<std::endl;
}
