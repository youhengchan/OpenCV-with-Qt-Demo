#-------------------------------------------------
#
# Project created by QtCreator 2015-02-08T14:07:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenCV
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
        magnifierfilter.cpp \
        magnifierwidget.cpp \
        openCVQtConnecter.cpp \
        wsmatrix.cpp

HEADERS  += dialog.h \
    magnifierfilter.h \
    magnifierwidget.h \
    openCVQtConnecter.h \
    wsmatrix.h

FORMS    += dialog.ui

INCLUDEPATH += Q:\openCV\build\install\include\opencv2
INCLUDEPATH += Q:\openCV\build\install\include

LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_aruco412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_bgsegm412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_bioinspired412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_calib3d412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_ccalib412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_core412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_datasets412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_dnn412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_dnn_objdetect412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_dpm412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_face412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_features2d412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_flann412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_fuzzy412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_gapi412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_hfs412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_highgui412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_imgcodecs412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_imgproc412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_img_hash412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_line_descriptor412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_ml412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_objdetect412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_optflow412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_phase_unwrapping412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_photo412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_plot412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_quality412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_reg412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_rgbd412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_saliency412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_shape412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_stereo412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_stitching412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_structured_light412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_superres412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_surface_matching412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_text412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_tracking412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_video412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_videoio412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_videostab412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_xfeatures2d412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_ximgproc412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_xobjdetect412d.lib
LIBS += Q:\openCV\build\install\x64\vc15\lib\opencv_xphoto412d.lib
