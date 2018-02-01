#ifndef BASICIMAGEPROCESSING_H
#define BASICIMAGEPROCESSING_H

#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include "basicfunction.h"

namespace FanWU {



class BasicImageProcessing
{
public:
    BasicImageProcessing(cv::Mat colorimage,cv::Mat grayimage);
    virtual ~BasicImageProcessing() = default;
public:
    cv::Mat m_colorimage;
    cv::Mat m_grayimage;
    cv::Scalar readBGRFromPixel(int num_row,int num_col);
    uchar readGrayFromPixel(int num_row,int num_col);
    SizeInformation<int> getImageHeightAndWidth() const;

};

}

#endif // BASICIMAGEPROCESSING_H
