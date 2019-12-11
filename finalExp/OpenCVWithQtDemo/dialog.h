#ifndef DIALOG_H
#define DIALOG_H

// for debugging
#define DEBUG

#include <QDialog>
#include <QFileDialog>
#include <opencv.hpp>
#include "magnifierwidget.h"


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    // open the img
    void on_pushButton_clicked();

    // flip the img horizontally
    void on_pushButton_2_clicked();

    // img enhancement in HSV space
    void on_pushButton_3_clicked();

    // img enhancement - mid filter in rgb space
    void on_pushButton_4_clicked();

    // img enhancement - histogram equalization
    void on_pushButton_5_clicked();

    // img segmentation - region growing
    void on_pushButton_6_clicked();

    // zooming the img
    void self_def_horizentalSlider_value_changed();

    // rotate the img
    void self_def_horizentalSlider_2_value_changed();

    // if or not open local zooming
    void self_def_checkBox_checked();


private:
    Ui::Dialog *ui;
    cv::Mat image;
    bool LocalZoomOpened;
    // magnify glass
    namespace_wslibs::namespace_wsbaswidgets::MagnifierWidget magnifyGlass;
};

#endif // DIALOG_H
