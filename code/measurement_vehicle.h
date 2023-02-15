#ifndef MEASUREMENT_VEHICLE_H
#define MEASUREMENT_VEHICLE_H

#include <QWidget>
#include <QString>
#include "mesurement_height.h"

namespace Ui {
class Measurement_vehicle;
}

class Measurement_vehicle : public QWidget
{
    Q_OBJECT

public:
    explicit Measurement_vehicle(QWidget *parent = nullptr);
    ~Measurement_vehicle();

private slots:
    void on_pushbtn_prev_mesure_clicked();
    void on_pushbtn_next_mesure_clicked();

private:
    Ui::Measurement_vehicle *ui;

    mesurement_height *third_dialog;

    float cameraInstalledLocataion;
};

#endif // MEASUREMENT_VEHICLE_H
