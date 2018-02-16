#include "searchclosedknownregionsample.h"
#include "basicfunction.h"
#include "math.h"

namespace FanWU
{

namespace SampleAndGather
{


SearchClosedKnownRegionSample::SearchClosedKnownRegionSample()
{

}

 int SearchClosedKnownRegionSample::calculBeginAngleForEachPixel(cv::Point pixel)
 {
     return (pixel.x+pixel.y)*c_random_angle_findknown_region % c_angle_findknown_region;
 }


 bool SearchClosedKnownRegionSample::ifPixelOutOfImage(int x, int y)
 {
     return (x<0 || x>m_grayimage.cols || y<0 || y>m_grayimage.rows)? true:false;

 }

 void SearchClosedKnownRegionSample::parserUnknownPointInVector()
 {
     // vector.at is more efficient than iterator
     for(int i = 0; i< m_unknown_region_point.size();i++)
     {
         CandidateForeAndBackGroundForOnePixel candidate_fb;

     }


 }

 void SearchClosedKnownRegionSample::parserToFindKnownPointAllDirection(int initial_angle)
 {

     CandidateForeAndBackGroundForOnePixel candidate_fb;
     for(int i = 0; i < c_num_most_gathersample;i++)
     {
         double current_angle = (initial_angle+i*c_angle_findknown_region/180)*3.1415926;
         double delta_x = std::sin(current_angle);
         double delta_y = std::cos(current_angle);
         double search_step = std::min(1/delta_x+1e-10,1/delta_y+1e-10);
         parserToFindKnownPointOneDirection(candidate_fb,DeltaXYandStep{delta_x,delta_y,search_step});


     }

 }


 void  SearchClosedKnownRegionSample::parserToFindKnownPointOneDirection(CandidateForeAndBackGroundForOnePixel& candidate_fb,DeltaXYandStep delta_xy_step)
 {
     bool has_find_foreground =false;
     bool has_find_background =false;
     for(int t = 0; ;t+=search_step)
     {
         int next_pixel_x = (int)(current_pixel.x+delta_xy_step.search_step*delta_xy_step.delta_x+0.5);
         int next_pixel_y = (int)(current_pixel.y+delta_xy_step.search_step*delta_xy_step.delta_y+0.5);
         if (ifPixelOutOfImage(next_pixel_x,next_pixel_y))
             return;
         if(IS_FOREGROUMD(readGrayFromPixel(next_pixel_y,next_pixel_x)) && (!has_find_foreground) )
         {
             candidate_fb.foreground_points.push_back(cv::Point(next_pixel_x,next_pixel_y));
             has_find_foreground = true;
         }
         if(IS_BACKGROUND(readGrayFromPixel(next_pixel_y,next_pixel_x)))
         {
             candidate_fb.background_points.push_back(cv::Point(next_pixel_x,next_pixel_y));
             has_find_background = true;

         }
         if(has_find_background && has_find_foreground)
             return ;
     }
 }



 }

}

