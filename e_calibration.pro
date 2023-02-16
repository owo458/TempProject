#-------------------------------------------------
#
# Project created by QtCreator 2023-01-12T08:50:01
#
#-------------------------------------------------
QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = e_calibration
TEMPLATE = app

INCLUDEPATH +=  /usr/local/include/opencv4/
LIBS += -L/usr/local/lib/ -lopencv_gapi -lopencv_stitching -lopencv_alphamat -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dnn_objdetect -lopencv_dnn_superres -lopencv_dpm -lopencv_highgui -lopencv_face -lopencv_freetype -lopencv_fuzzy -lopencv_hfs -lopencv_img_hash -lopencv_intensity_transform -lopencv_line_descriptor -lopencv_quality -lopencv_rapid -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_superres -lopencv_optflow -lopencv_surface_matching -lopencv_tracking -lopencv_datasets -lopencv_text -lopencv_dnn -lopencv_plot -lopencv_videostab -lopencv_videoio -lopencv_xfeatures2d -lopencv_shape -lopencv_ml -lopencv_ximgproc -lopencv_video -lopencv_xobjdetect -lopencv_objdetect -lopencv_calib3d -lopencv_imgcodecs -lopencv_features2d -lopencv_flann -lopencv_xphoto -lopencv_photo -lopencv_imgproc -lopencv_core

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        code/main.cpp \
        code/mainwindow.cpp \
    code/checkcamerainstallation.cpp \
    code/cameraposeestimation.cpp \
    code/captureimg.cpp \
    code/parameterinput.cpp \
    code/intrinsic_param.cpp \
    code/intrinsic_param_calculate.cpp




HEADERS += \
        code/mainwindow.h \
    code/checkcamerainstallation.h \
    code/cameraposeestimation.h \
    code/parameterinput.h \
    code/captureimg.h \
    code/intrinsic_param.h \
    code/intrinsic_param_calculate.h


FORMS += \
        ui/mainwindow.ui \
    ui/cameraposeestimation.ui \
    ui/captureimg.ui \
    ui/parameterinput.ui \
    ui/intrinsic_param.ui

UI_DIR = "ui/"

RCC_DIR = "build\RCCFiles"
MOC_DIR = "build\MOCFiles"
OBJECTS_DIR = "build\ObjFiles"

#CONFIG(debug, debug|release) {
#    DESTDIR = build/debug
#} else {
#    DESTDIR = build/release
#}


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

