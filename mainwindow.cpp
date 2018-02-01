#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "sharedmatting.h"
#include <opencv2/imgproc/imgproc.hpp>


namespace FanWU {



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

   cv::Mat color_img = cv::imread("/home/fanwu/Downloads/image/troll.png");
   cv::Mat tri_img = cv::imread("/home/fanwu/Downloads/image/Trimap2/troll.png");
   cv::cvtColor(tri_img,tri_img,CV_BGR2GRAY);

   MattingSpace::SharedMatting shared_matting(tri_img,color_img);
   shared_matting.m_expandregion.showBeforeAfterExpandPptrimap();
}

MainWindow::~MainWindow()
{

}

}
