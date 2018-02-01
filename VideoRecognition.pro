#-------------------------------------------------
#
# Project created by QtCreator 2018-01-25T12:07:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++14

TARGET = VideoRecognition
TEMPLATE = app


INCLUDEPATH += /usr/local/include/opencv

LIBS += -L/usr/local/lib -lopencv_shape -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_core

SOURCES += main.cpp\
        mainwindow.cpp \
    sharedmatting.cpp \
    basicfunction.cpp \
    sharedmatting_config.cpp \
    expandknownregion.cpp \
    basicimageprocessing.cpp

HEADERS  += mainwindow.h \
    sharedmatting.h \
    basicfunction.h \
    sharedmatting_config.h \
    expandknownregion.h \
    basicimageprocessing.h

FORMS    += mainwindow.ui
