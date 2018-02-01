#ifndef SEARCHCLOSEDKNOWNREGIONSAMPLE_H
#define SEARCHCLOSEDKNOWNREGIONSAMPLE_H


#include "basicimageprocessing.h"
#include "sampleandgather_config.h"


namespace FanWU {


namespace SampleAndGather {



class SearchClosedKnownRegionSample: public BasicImageProcessing
{
public:
    SearchClosedKnownRegionSample();
    virtual ~SearchClosedKnownRegionSample() = default;

private:
    int calculBeginAngleForEachPixel(cv::Point pixel);





};

}

}

#endif // SEARCHCLOSEDKNOWNREGIONSAMPLE_H
