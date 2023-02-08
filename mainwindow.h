#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "measurement_vehicle.h"

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

private:
    Ui::MainWindow *ui;

    Measurement_vehicle *second_dialog;
};

#endif // MAINWINDOW_H
