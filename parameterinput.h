#ifndef ParameterInput_H
#define ParameterInput_H

#include "captureimg.h"

#include <QWidget>
#include <QString>
#include <QDoubleValidator>

namespace Ui {
class ParameterInput;
}

class ParameterInput : public QWidget
{
    Q_OBJECT

public:
    explicit ParameterInput(QWidget *parent = nullptr);
    ~ParameterInput();


//    const float carWidth = 0.f;
//    const float camHeight = 0.f;
//    const float camToBumper = 0.f;
//    const float camInstallLoc = 0.f;

private slots:
    void on_pushbtn_prev_mesure_clicked();
    void on_pushbtn_next_mesure_clicked();

    void on_lineEdit_carWidth_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_camHeight_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_camToBumper_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_camInstallLoc_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::ParameterInput *ui;

    //숫자만 - 소숫점 표시
    QDoubleValidator *doubleValidator=new QDoubleValidator(0,9999.00,2); //최소수,최대수,소수점 뒤 갯수


    CaptureImg *third_dialog;
};

#endif // ParameterInput_H
