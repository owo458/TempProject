#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pixmap("./Logo.png");
    QPixmap fitpixmap=pixmap.scaled(500, 250, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
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
