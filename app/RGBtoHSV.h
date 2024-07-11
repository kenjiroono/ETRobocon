
#include "ColorSensor.h"
#include "HSV.h"
#include <algorithm>

class RGBtoHSV {
public:
    RGBtoHSV(rgb_raw_t rgb);
    ~RGBtoHSV();

    HSV *mHSV;
};