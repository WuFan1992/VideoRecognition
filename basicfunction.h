#ifndef BASICFUNCTION
#define BASICFUNCTION
#include <opencv2/highgui.hpp>

namespace FanWU
{

    template<typename T>
    struct SizeInformation
    {
        T image_width;
        T image_height;
    };


    inline bool IS_FOREGROUMD(int x){return (x==0);}
    inline bool IS_BACKGROUND(int x){return (x==255);}
    inline bool IS_KNOWREGION(int x){return (IS_BACKGROUND(x)||IS_FOREGROUMD(x));}
    inline bool IS_UNKNOWNREGION(int x){return !IS_KNOWREGION(x);}







}



#endif // BASICFUNCTION

