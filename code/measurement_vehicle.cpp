#include "measurement_vehicle.h"
#include "ui_measurement_vehicle.h"

Measurement_vehicle::Measurement_vehicle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Measurement_vehicle)
{
    ui->setupUi(this);
}

Measurement_vehicle::~Measurement_vehicle()
{
    delete ui;
}

void Measurement_vehicle::on_pushbtn_prev_mesure_clicked()
{
    this->close();
}

void Measurement_vehicle::on_pushbtn_next_mesure_clicked()
{
    this->close();
    this->third_dialog = new mesurement_height();
    this->third_dialog->show();
}


//void Measurement_vehicle::on_textEdit_camInstalled_textChanged()
//{
//    cameraInstalledLocataion = ui->textEdit_camInstalled->toPlainText().toFloat();
//    cout << cameraInstalledLocataion << endl;
//}
