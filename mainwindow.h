#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "parameterinput.h"
#include "intrinsic_param.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushbtn_extrinsic_clicked();
    void on_pushbtn_intrinsic_clicked();

private:
    Ui::MainWindow *ui;

    ParameterInput *second_dialog;
    intrinsic_param *intrinsic_param_cal_dialog;
};

#endif // MAINWINDOW_H
