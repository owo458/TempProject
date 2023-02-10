#ifndef ParameterInput_H
#define ParameterInput_H

#include <QWidget>
#include "captureimg.h"

namespace Ui {
class ParameterInput;
}

class ParameterInput : public QWidget
{
    Q_OBJECT

public:
    explicit ParameterInput(QWidget *parent = nullptr);
    ~ParameterInput();

private slots:
    void on_pushbtn_prev_mesure_clicked();
    void on_pushbtn_next_mesure_clicked();
private:
    Ui::ParameterInput *ui;

    CaptureImg *third_dialog;
};

#endif // ParameterInput_H
