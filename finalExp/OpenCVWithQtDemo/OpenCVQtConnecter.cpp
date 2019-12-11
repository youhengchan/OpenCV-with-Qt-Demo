#include "openCVQtConnecter.h"
#include <vector>
#include <stack>

void LabelDisplayMat(QLabel *label, cv :: Mat &mat)
{
    cv::Mat Rgb(mat.size(), mat.type());
    QImage Img;
    if (mat.channels() == 3)
    {
        cv::cvtColor(mat, Rgb, cv::COLOR_BGR2RGB);
        Img = QImage((const uchar*)(Rgb.data), Rgb.cols, Rgb.rows, Rgb.cols * Rgb.channels(), QImage::Format_RGB888);
    }
    else
    {
        Img = QImage((const uchar*)(mat.data), mat.cols, mat.rows, mat.cols*mat.channels(), QImage::Format_Indexed8);
    }
    label->setPixmap(QPixmap::fromImage(Img));
    label->resize(Img.size());
    label->show();
}

// optimize saturation of the Img in hsv color space
Mat hsvSpaceEnhancement(const Mat & srcImage) {

    Mat srcHSV, sat, satAdj, Merge, imageAwb, dst;

    imageAwb = srcImage.clone();
    std :: vector<Mat> channels, channels1;
    double p1, p2, p3;
    cvtColor(imageAwb, srcHSV, COLOR_BGR2HSV);
    split(srcHSV, channels);
    split(srcHSV, channels1);
    sat = channels.at(1);
    Scalar m = mean(sat);
    if (m(0) <= 51.5)
    {
        p1 = -0.002714, p2 = 0.9498, p3 = -0.5073;
    } // High
    else if (m(0) > 38.5 && m(0) <= 89.5)
    {
        p1 = -0.001578, p2 = 0.6238, p3 = -0.1514;
    } // Medium
    else if (m(0) > 89.5 && m(0) <= 127.5)
    {
        p1 = -0.0006512, p2 = 0.2639, p3 = -0.9246;
    } // Low
    else
    {
        p1 = 0, p2 = 0, p3 = 0;
    }
    satAdj = sat;
    for (int i = 0; i < sat.rows; i++)
    {
        for (int j = 0; j < sat.cols; j++)
        {
            uchar val = sat.at<uchar>(i, j);
            satAdj.at<uchar>(i, j) = (val + p1
                * val * val + p2 * val + p3);
        }
    }
    channels1.at(1) = satAdj;
    merge(channels1, Merge);
    cvtColor(Merge, dst, COLOR_HSV2BGR);
    return dst;
}

// midFilter.cpp

static uchar returnMid(uchar n1, uchar n2, uchar n3, uchar n4, uchar n5,
    uchar n6, uchar n7, uchar n8, uchar n9) {
    uchar arr[9] = { n1, n2, n3, n4, n5, n6, n7, n8, n9 };
    // Shell sort
    for (int gap = 9 / 2; gap > 0; gap /= 2)
        for (int i = gap; i < 9; ++i)
            for (int j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap)
                swap(arr[j], arr[j + gap]);
    return arr[4];
}

Mat midFilter(const Mat &src) {
    Mat _dst(src.size(), src.type());
    for (int i = 0; i < src.rows; ++i)
        for (int j = 0; j < src.cols; ++j) {
            if ((i - 1) > 0 && (i + 1) < src.rows && (j - 1) > 0 && (j + 1) < src.cols) {
                _dst.at<Vec3b>(i, j)[0] = returnMid(src.at<Vec3b>(i, j)[0], src.at<Vec3b>(i + 1, j + 1)[0],
                    src.at<Vec3b>(i + 1, j)[0], src.at<Vec3b>(i, j + 1)[0], src.at<Vec3b>(i + 1, j - 1)[0],
                    src.at<Vec3b>(i - 1, j + 1)[0], src.at<Vec3b>(i - 1, j)[0], src.at<Vec3b>(i, j - 1)[0],
                    src.at<Vec3b>(i - 1, j - 1)[0]);
                _dst.at<Vec3b>(i, j)[1] = returnMid(src.at<Vec3b>(i, j)[1], src.at<Vec3b>(i + 1, j + 1)[1],
                    src.at<Vec3b>(i + 1, j)[1], src.at<Vec3b>(i, j + 1)[1], src.at<Vec3b>(i + 1, j - 1)[1],
                    src.at<Vec3b>(i - 1, j + 1)[1], src.at<Vec3b>(i - 1, j)[1], src.at<Vec3b>(i, j - 1)[1],
                    src.at<Vec3b>(i - 1, j - 1)[1]);
                _dst.at<Vec3b>(i, j)[2] = returnMid(src.at<Vec3b>(i, j)[2], src.at<Vec3b>(i + 1, j + 1)[2],
                    src.at<Vec3b>(i + 1, j)[2], src.at<Vec3b>(i, j + 1)[2], src.at<Vec3b>(i + 1, j - 1)[2],
                    src.at<Vec3b>(i - 1, j + 1)[2], src.at<Vec3b>(i - 1, j)[2], src.at<Vec3b>(i, j - 1)[2],
                    src.at<Vec3b>(i - 1, j - 1)[2]);
            }
            else
                _dst.at<Vec3b>(i, j) = src.at<Vec3b>(i, j);
        }
    return _dst;
}

Mat histogramEqualization(const Mat& src)
{
    std :: vector<Mat> bgr;
    split( src, bgr );

    Size src_s = src.size();

    //equalize image
    equalizeHist( bgr[0], bgr[0] );
    equalizeHist( bgr[1], bgr[1] );
    equalizeHist( bgr[2], bgr[2] );

    Mat equalizedImg;
    merge( bgr, equalizedImg);

    return equalizedImg;
}

static int rInt(int a, int b) {
    int temp = int(double(rand()) / RAND_MAX * (b - a) + a);
    return temp;
}

// th: threshold: determne when the connection of two neighbor pixel
Mat regionGrowingBasedSegmentation(const Mat& para_src, int th)
{
    Mat src_pre, src;
#ifdef DEBUG
    if(para_src.empty()) {
        std :: cout << "Para Error" << std :: endl;
        exit(-1);
    }
#endif // DEBUG
    src_pre = para_src.clone();
    // Convert the image to Gray
    cvtColor(src_pre, src, COLOR_BGR2GRAY);
    // Generate random 2 points
    int randX1 = rInt(src.rows/2, src.rows - 1);
    int randY1 = rInt(src.cols/2, src.cols - 1);
    int randX2 = rInt(10, src.rows / 2);
    int randY2 = rInt(10, src.cols / 2);


#ifdef DEBUG
    std :: cout << "src.rows = " << src.rows <<
        "\nsrc.cols = " << src.cols << std :: endl;
    std :: cout << "randX1 = " << randX1 << std :: endl
        << "randY1 = " << randY1 << std :: endl;
    std :: cout << "randX2 = " << randX2 << std :: endl
        << "randY2 = " << randY2 << std :: endl;
#endif // DEBUG


    Point2i pt;
    Point2i ptGrowing;						        // The point to grow
    int nGrowLable = 0;								// Check if it has been growed before
    int nSrcValue = 0;								// The growing point value
    int nCurValue = 0;								// The current pixel's value
    Mat matDst = Mat::zeros(src.size(), CV_8UC1);	// Create a new region filled with black
    // Set the growing direction
    int DIR[8][2] = { {-1,-1}, {0,-1}, {1,-1}, {1,0}, {1,1}, {0,1}, {-1,1}, {-1,0} };
    std :: stack<Point2i> vcGrowPt;						// Create a gorwing point stack


    for (int times = 0 ; times < 2 ; ++times) {
        if (times == 0) {
            pt = Point2i(randX1, randY1);
        }
        else {
            pt = Point2i(randX2, randY2);
        }
        vcGrowPt.push(pt);							// Push the growing point into the stack
        matDst.at<uchar>(pt.x, pt.y) = 255;				// Mark the growing point
        nSrcValue = src.at<uchar>(pt.x, pt.y);			// Update the growing point's gray scale value

        while (!vcGrowPt.empty())					// Determine when to end the process
        {
            pt = vcGrowPt.top();						// Get one growing point out
            vcGrowPt.pop();

            // Try to connect the 8 neighbor pixels
            for (int i = 0; i < 8; ++i)
            {
                // Set the next point to grow
                ptGrowing.x = pt.x + DIR[i][0];
                ptGrowing.y = pt.y + DIR[i][1];

                // Check the boundaries
                if (ptGrowing.x < 0 || ptGrowing.y < 0 ||
                    ptGrowing.x >(matDst.rows - 1) || (ptGrowing.y > matDst.cols - 1)) {
                    continue;
                }

                // Get the grayScale value of the current pixel
                nGrowLable = matDst.at<uchar>(ptGrowing.x, ptGrowing.y);

                // The pixels has not been accessed before
                if (nGrowLable == 0)
                {
                    nCurValue = src.at<uchar>(ptGrowing.x, ptGrowing.y);
                    if (abs(nSrcValue - nCurValue) < th)					// If the pixel grayscale value is close to threshold enough
                    {
                        matDst.at<uchar>(ptGrowing.x, ptGrowing.y) = 255;		// set the pixel's grayscale to 255
                        vcGrowPt.push(ptGrowing);					// Continue the BFS process
                    }
                }
            }
        }
    }
    return matDst;
}
