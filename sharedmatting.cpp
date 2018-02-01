#include "sharedmatting.h"
#include "sharedmatting_config.h"
#include "assert.h"


namespace FanWU
{


namespace MattingSpace
{

SharedMatting::SharedMatting(cv::Mat trimap, cv::Mat original_colormap):
    m_pptrimap(trimap)
  ,m_originalcolor_img(original_colormap)
  ,m_expandregion(m_pptrimap,m_originalcolor_img)
{

}
 //, m_expandregion(trimap,original_colormap)


}


}

