#ifndef SHAREDMATTING
#define SHAREDMATTING

#include "expandknownregion.h"

#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>

namespace FanWU
{


namespace MattingSpace
{


class SharedMatting
{
   public:
    SharedMatting(cv::Mat trimap, cv::Mat original_colormap);
    virtual ~SharedMatting() = default;

private:
    cv::Mat m_pptrimap;
    cv::Mat m_originalcolor_img;
public:
    ExpandKnownRegion m_expandregion;

};

}

}


#endif // SHAREDMATTING

