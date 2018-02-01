#ifndef EXPANDKNOWNREGION
#define EXPANDKNOWNREGION

#include "basicimageprocessing.h"

#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>

namespace FanWU
{
   namespace MattingSpace
   {
   inline bool IS_FOREGROUMD(int x){return (x==0);}
   inline bool IS_BACKGROUND(int x){return (x==255);}
   inline bool IS_KNOWREGION(int x){return (IS_BACKGROUND(x)||IS_FOREGROUMD(x));}
   inline bool IS_UNKNOWNREGION(int x){return !IS_KNOWREGION(x);}

      struct FourVertices
      {
        cv::Point point_top_left;
        cv::Point point_top_right;
        cv::Point point_low_left;
        cv::Point point_low_right;
     };
     class ExpandKnownRegion : public BasicImageProcessing
     {   
      public:
          ExpandKnownRegion(cv::Mat trimap, cv::Mat original_colormap);
          virtual ~ExpandKnownRegion() = default;

          void showBeforeAfterExpandPptrimap();

      private:
          //cv::Mat m_pptrimap;
          cv::Mat m_afterexpand_pptrimap;

          double pixelDistance(cv::Point p, cv::Point q) const;
          double colorDistance(cv::Scalar p, cv::Scalar q) const;
          bool ifPixelDistanceLessThanThreshold(cv::Point center_unknown_pixel,cv::Point tocompare_pixel)const;
          bool ifColorDistanceLessThanThreshold(cv::Point center_unknown_pixel, cv::Point tocompare_pixel);
          FourVertices findFourVertices(cv::Point current_pixel,int expand_step, SizeInformation<int>& trimap_size) const;
          void compareVerticalAndHorizontal(cv::Point target_pixel,FourVertices& four_vertices);
          void compareVerticalOneLine(cv::Point center_unknown_pixel,int y_top,int y_low,int const_x);
          void compareHorizontalOneLine(cv::Point center_unknown_pixel,int x_left,int x_right,int const_y);


};
}
}






#endif // EXPANDKNOWNREGION

