#include "basicimageprocessing.h"
#include "sharedmatting_config.h"

namespace FanWU
{
BasicImageProcessing::BasicImageProcessing(cv::Mat colorimage,cv::Mat grayimage):
    m_colorimage(colorimage)
   ,m_grayimage(grayimage.clone())
{

}

cv::Scalar BasicImageProcessing::readBGRFromPixel(int num_row, int num_col)
{
    uchar *data = m_colorimage.ptr<uchar>(num_row);
        return cv::Scalar(data[num_col*c_images_channels],
                data[num_col*c_images_channels+1],
                data[num_col*c_images_channels+2]);
}

uchar BasicImageProcessing::readGrayFromPixel(int num_row, int num_col)
{
    uchar *data = m_grayimage.ptr<uchar>(num_row);
    return data[num_col];
}

SizeInformation<int> BasicImageProcessing::getImageHeightAndWidth() const
{
    //int img_color_height = m_colorimage.rows;
    //int img_color_width =  m_colorimage.cols * m_colorimage.channels();
    int img_color_height = m_grayimage.rows;
    int img_color_width =  m_grayimage.cols;
    /*
    if(m_colorimage.isContinuous())
    {
       img_color_height*=img_color_width;
       img_color_width = 1;
    }
    */
    return SizeInformation<int>{img_color_width,img_color_height};
}

}

