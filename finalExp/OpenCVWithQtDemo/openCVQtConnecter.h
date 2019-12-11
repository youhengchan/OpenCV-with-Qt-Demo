#ifndef OPENCVQTCONNECTER_H
#define OPENCVQTCONNECTER_H

// for debug
#define DEBUG

#include "opencv.hpp"
#include "QLabel"
using namespace cv;

void LabelDisplayMat(QLabel *label, cv:: Mat &mat);
Mat hsvSpaceEnhancement(const Mat & srcImage);
Mat midFilter(const Mat &src);
Mat histogramEqualization(const Mat& src);
Mat regionGrowingBasedSegmentation(const Mat& para_src, int th);

#endif // OPENCVQTCONNECTER_H
