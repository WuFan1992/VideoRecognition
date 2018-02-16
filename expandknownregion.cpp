#include "expandknownregion.h"
#include "sharedmatting_config.h"
#include "basicfunction.h"

#include <opencv2/imgproc/imgproc.hpp>

#include <QDebug>


namespace FanWU {

namespace MattingSpace {

        ExpandKnownRegion::ExpandKnownRegion(cv::Mat trimap, cv::Mat original_colormap):BasicImageProcessing(original_colormap,trimap)
            ,m_afterexpand_pptrimap(trimap)
        {
            //assert(m_pptrimap.channels() == 1);
            SizeInformation<int> img_size = getImageHeightAndWidth();
            for(int i=0; i<img_size.image_height;i++)
            {

                for(int j = 0; j<img_size.image_width;j++)
                {   
                 if(IS_UNKNOWNREGION(readGrayFromPixel(i,j)))
                 {
                    for(int expand_step = 0; expand_step < c_expansion_length;expand_step++)
                    {
                        FourVertices four_vertices = findFourVertices(cv::Point(j,i),expand_step,img_size);
                        compareVerticalAndHorizontal(cv::Point(j,i),four_vertices);
                    }
                 }
            }
        }
        }

        void ExpandKnownRegion::showBeforeAfterExpandPptrimap()
        {
            cv::imshow("Before Expand",m_grayimage);
            cv::imshow("After Expand",m_afterexpand_pptrimap);
            cv::waitKey(0);
        }


        double ExpandKnownRegion::pixelDistance(cv::Point p, cv::Point q) const
        {
            return sqrt(double((p.x-q.x)*(p.x-q.x)+ (p.y-q.y)*(p.y-q.y)));
        }

       double ExpandKnownRegion::colorDistance(cv::Scalar p, cv::Scalar q)const
       {
           return sqrt((p.val[0]-q.val[0])*(p.val[0]-q.val[0]) + (p.val[1]-q.val[1])*(p.val[1]-q.val[1]) + (p.val[2]-q.val[2])*(p.val[2]-q.val[2]));
       }

        bool ExpandKnownRegion::ifPixelDistanceLessThanThreshold(cv::Point center_unknown_pixel,cv::Point tocompare_pixel)const
        {
           return  (pixelDistance(center_unknown_pixel,tocompare_pixel)<c_threshold_pixeldistance)? true:false;
        }

        bool ExpandKnownRegion::ifColorDistanceLessThanThreshold(cv::Point center_unknown_pixel, cv::Point tocompare_pixel)
        {
            return (colorDistance(readBGRFromPixel(center_unknown_pixel.y,center_unknown_pixel.x),
                                  readBGRFromPixel(tocompare_pixel.y,tocompare_pixel.x))<c_threshold_colordistance)? true:false;
        }

        FourVertices ExpandKnownRegion::findFourVertices(cv::Point current_pixel, int expand_step, SizeInformation<int>& trimap_size) const
        {

            return FourVertices{cv::Point(std::max(0,current_pixel.x - expand_step),
                                          std::max(0,current_pixel.y - expand_step)),
                        cv::Point(std::min(current_pixel.x + expand_step,trimap_size.image_width-1),
                                  std::max(0,current_pixel.y - expand_step)),
                        cv::Point(std::max(0,current_pixel.x - expand_step),
                                  std::min(current_pixel.y + expand_step,trimap_size.image_height-1)),
                        cv::Point(std::min(current_pixel.x + expand_step,trimap_size.image_width-1),
                                  std::min(current_pixel.y + expand_step,trimap_size.image_height-1))};
        }

        void ExpandKnownRegion::compareVerticalOneLine(cv::Point center_unknown_pixel,int y_top,int y_low,int const_x)
        {
            for(int y = y_top; y<= y_low;y++)
            {
                if(IS_KNOWREGION(readGrayFromPixel(y,const_x)))
                    if((ifPixelDistanceLessThanThreshold(center_unknown_pixel,cv::Point(const_x,y))) && (ifColorDistanceLessThanThreshold(center_unknown_pixel,cv::Point(const_x,y))))
                        m_afterexpand_pptrimap.at<uchar>(center_unknown_pixel.y,center_unknown_pixel.x) = m_afterexpand_pptrimap.at<uchar>(y,const_x);
                    else
                          continue;

                else
                      continue;
            }
        }

        void ExpandKnownRegion::compareHorizontalOneLine(cv::Point center_unknown_pixel,int x_left,int x_right,int const_y)
        {
            for(int x = x_left; x<=x_right ;x++)
            {
                  if(IS_KNOWREGION(readGrayFromPixel(const_y,x)))
                      if(ifPixelDistanceLessThanThreshold(center_unknown_pixel,cv::Point(x,const_y)) && ifColorDistanceLessThanThreshold(center_unknown_pixel,cv::Point(x,const_y)))
                          m_afterexpand_pptrimap.at<uchar>(center_unknown_pixel.y,center_unknown_pixel.x) = m_afterexpand_pptrimap.at<uchar>(const_y,x);
                      else
                          continue;
                  else
                      continue;
            }
        }

        void ExpandKnownRegion::compareVerticalAndHorizontal(cv::Point center_unknown_pixel, FourVertices& four_vertices)
        {
            compareVerticalOneLine(center_unknown_pixel,four_vertices.point_top_left.y,four_vertices.point_low_left.y,four_vertices.point_top_left.x);
            compareVerticalOneLine(center_unknown_pixel,four_vertices.point_top_right.y,four_vertices.point_low_right.y,four_vertices.point_top_right.x);
            compareHorizontalOneLine(center_unknown_pixel,four_vertices.point_top_left.x,four_vertices.point_top_right.x,four_vertices.point_top_left.y);
            compareHorizontalOneLine(center_unknown_pixel,four_vertices.point_low_left.x,four_vertices.point_low_right.x,four_vertices.point_low_left.y);
        }

}

}
