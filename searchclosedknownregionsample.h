#ifndef SEARCHCLOSEDKNOWNREGIONSAMPLE_H
#define SEARCHCLOSEDKNOWNREGIONSAMPLE_H


#include "basicimageprocessing.h"
#include "sampleandgather_config.h"


namespace FanWU {


namespace SampleAndGather {


struct DeltaXYandStep{

    double delta_x;
    double delta_y;
    double search_step;
};

struct CandidateForeAndBackGroundForOnePixel{
    cv::Point current_pixel;
    std::vector<cv::Point> foreground_points;
    std::vector<cv::Point> background_points;
};


class SearchClosedKnownRegionSample: public BasicImageProcessing
{
public:
    SearchClosedKnownRegionSample();
    virtual ~SearchClosedKnownRegionSample() = default;

private:
    std::vector<cv::Point> m_unknown_region_point;

    int calculBeginAngleForEachPixel(cv::Point pixel);
    bool ifPixelOutOfImage(int x,int y);
    void parserUnknownPointInVector();
    void parserToFindKnownPointAllDirection(CandidateForeAndBackGroundForOnePixel& candidate_fb,int initial_angle);
    bool parserToFindKnownPointOneDirection(cv::Point current_pixel,DeltaXYandStep delta_xy_step);





};

}

}

#endif // SEARCHCLOSEDKNOWNREGIONSAMPLE_H
