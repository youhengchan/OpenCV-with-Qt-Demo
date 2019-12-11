#include "dialog.h"
#include "ui_dialog.h"
#include <QString>
#include <QMessageBox>
#include "openCVQtConnecter.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("OpenCV with Qt Demo");
    this->setStyleSheet("background-color:#99CCFF;");

    ui->horizontalSlider->setMinimum(50);
    ui->horizontalSlider->setMaximum(200);
    ui->horizontalSlider->setValue(100);

    ui->horizontalSlider_2->setMinimum(0);
    ui->horizontalSlider_2->setMaximum(360);
    ui->horizontalSlider_2->setValue(180);

    // on_horizentalSlider_value_changed() is called when all the value of the Qslider is changed
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(self_def_horizentalSlider_value_changed()));
    connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)), this, SLOT(self_def_horizentalSlider_2_value_changed()));

    connect(ui->checkBox, SIGNAL(stateChanged(int)), this, SLOT(self_def_checkBox_checked()));
    this->LocalZoomOpened = false;  // initally disable the local zooming function

    // Hide the question mark
    Qt::WindowFlags flags= this->windowFlags();
    setWindowFlags(flags&~Qt::WindowContextHelpButtonHint);

    // Initilize welcome pics
    this->image = cv::imread("./welcomeImg/guide.bmp");
    if (this->image.empty()) {
        std :: cout << "Open Welcome pics error" << std :: endl;
    }
    LabelDisplayMat(ui->label, image);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QString fileName;

    fileName = QFileDialog::getOpenFileName(this, "Open Image", ".", "Image Files(*.png *.jpg *.jpeg)");

    if (!fileName.isEmpty()){

        this->image = cv::imread(fileName.toLatin1().data());
        LabelDisplayMat(ui->label, image);

    }

}

void Dialog::on_pushButton_2_clicked()
{
    if (!image.empty()){

        cv::flip(image, image, 1);
        LabelDisplayMat(ui->label, image);

    } else {
        QMessageBox::warning(this, "No image found", "Please select an image first");
    }

}

void Dialog::on_pushButton_3_clicked()
{
    if (!image.empty()){

        image = hsvSpaceEnhancement(image);
        LabelDisplayMat(ui->label, image);

    } else {
        QMessageBox::warning(this, "No image found", "Please select an image first");
    }

}

void Dialog::on_pushButton_4_clicked()
{
    if (!image.empty()){

        image = midFilter(image);
        LabelDisplayMat(ui->label, image);

    } else {
        QMessageBox::warning(this, "No image found", "Please select an image first");
    }

}

void Dialog::on_pushButton_5_clicked()
{
    if (!image.empty()){

        image = histogramEqualization(image);
        LabelDisplayMat(ui->label, image);

    } else {
        QMessageBox::warning(this, "No image found", "Please select an image first");
    }

}

void Dialog::on_pushButton_6_clicked()
{
    if (!image.empty()){

        Mat dst = regionGrowingBasedSegmentation(image, 50);
        LabelDisplayMat(ui->label, dst);

    } else {
        QMessageBox::warning(this, "No image found", "Please select an image first");
    }

}

void Dialog::self_def_horizentalSlider_value_changed()
{

    if (!image.empty())
    {
        // set zooming factor
        double zoomFactor = double(ui->horizontalSlider->value()) / 100.0;

#ifdef DEBUG
        std :: cout << "zoomFactor = " << zoomFactor << std :: endl;
#endif

        Mat showImg;
        cv::resize(image, showImg, cv :: Size(), zoomFactor, zoomFactor, cv :: INTER_CUBIC);
        LabelDisplayMat(ui->label, showImg);
    }
}

void Dialog::self_def_horizentalSlider_2_value_changed()
{

    if (!image.empty())
    {
        int centreX = image.cols / 2;
        int centreY = image.rows / 2;

        Mat dst_img = getRotationMatrix2D(Point(centreX, centreY), (ui->horizontalSlider_2->value() - 180), 1.0);

        // Rotate the Img
        Mat rotated_img;
        warpAffine(image, rotated_img, dst_img, image.size());

        LabelDisplayMat(ui->label, rotated_img);
    }
}

void Dialog::self_def_checkBox_checked()
{
#ifdef DEBUG
        std :: cout << "RADIO BUTTON IS CHECKED(Before)" << std :: endl;
        std :: cout << "LocalZoomOpened = " << this->LocalZoomOpened << std :: endl;
#endif

        this->LocalZoomOpened = (this->LocalZoomOpened == true) ? false : true;

        if (this->LocalZoomOpened)
        {
             this->magnifyGlass.show();
        }
        else
        {
            this->magnifyGlass.hide();
        }
#ifdef DEBUG
        std :: cout << "RADIO BUTTON IS CHECKED(After)" << std :: endl;
        std :: cout << "LocalZoomOpened = " << this->LocalZoomOpened << std :: endl;
#endif

}
