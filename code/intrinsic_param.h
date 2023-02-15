#ifndef INTRINSIC_PARAM_H
#define INTRINSIC_PARAM_H

#include <QDialog>
#include <QImage>
#include <QFileDialog>
#include <QMessageBox>


namespace Ui {
class intrinsic_param;
}

class intrinsic_param : public QDialog
{
    Q_OBJECT

public:
    explicit intrinsic_param(QWidget *parent = 0);
    ~intrinsic_param();


private slots:
    void on_pushButton_VideoLoad_clicked();
    void on_pushButton_SavePath_clicked();
    void on_textBrowser_VideoPath_textChanged();
    void on_textBrowser_SavePath_textChanged();
    void on_textEdit_ChessHorizontal_textChanged();
    void on_textEdit_ChessVertical_textChanged();
    void on_pushButton_Start_clicked();

    void on_pushButton_exit_clicked();
void closeEvent (QCloseEvent *event);
    void on_textEdit_FPS_textChanged();

private:
    Ui::intrinsic_param *ui;
    int m_startCheck[5]={0, 0, 0, 0, 0}; // video, save, w, h, fps
    int m_chess_pattern[2]={0,0};
    QString m_path[2];
    int m_fps;
};

#endif // INTRINSIC_PARAM_H
