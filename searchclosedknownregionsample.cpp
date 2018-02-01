#include "searchclosedknownregionsample.h"

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




 }

}

