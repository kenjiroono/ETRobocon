/******************************************************************************
 *  ColorMonitor.cpp 
 *  カラーセンサーで読み取る値に関連する
 *****************************************************************************/

#ifndef EV3_UNIT_COLORMONITOR_H_
#define EV3_UNIT_COLORMONITOR_H_

#include "ColorSensor.h"
#include "RGBtoHSV.h"

class ColorMonitor {
public:
    ColorMonitor(const ev3api::ColorSensor& colorSensor);
    // ~ColorMonitor();
    
    colorid_t getColorid();
    double getBrightness();

private:
    const ev3api::ColorSensor& mColorSensor;

    HSV* getHSV();
};

#endif  // EV3_UNIT_COLORMONITOR_H_