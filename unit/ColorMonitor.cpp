/******************************************************************************
 *  ColorMonitor.cpp 
 *  カラーセンサーで読み取る値に関連する
 *****************************************************************************/

#include "ColorMonitor.h"

/**
 * コンストラクタ
 * @param colorSensor      カラーセンサー
 */
ColorMonitor::ColorMonitor(const ev3api::ColorSensor& colorSensor)
    :mColorSensor(colorSensor){
}

/**
 * 色を取得する
 * @retval res  カラーの識別番号
 */
colorid_t ColorMonitor::getColorid(){
    HSV *hsv = getHSV();

    colorid_t res = COLOR_NONE;

    // 黒色
    if((hsv->V <= 35) && (hsv->S <= 40)){
        res = COLOR_BLACK;
    }
    // 赤色
    else if((hsv->S >= 60) && ((330 <= hsv->H && hsv->H <= 360) || (0 <= hsv->H && hsv->H <= 30))){
        res = COLOR_RED;
    }
    // 緑色
    else if((hsv->S >= 50) && (80 <= hsv->H && hsv->H <= 180)){
        res = COLOR_GREEN;
    }
    // 青色
    else if((hsv->S >= 60) && (190 <= hsv->H && hsv->H <= 280)){
        res = COLOR_BLUE;
    }

    //  LCDに出力する文字列を作成する
    // printf("%f,%f,%f\n", hsv->H, hsv->S, hsv->V);
    // printf("%f,%f,%f\n", hsv->V, hsv->S, hsv->H);

    return res;
}

/**
 * 明るさを取得する
 * @retval mColorSensor.getBrightness()  反射光の強さ
 */
double ColorMonitor::getBrightness(){
    return mColorSensor.getBrightness();
}

/**
 * HSV色空間を取得する
 * @retval rgbTo->mHSV  HSV色空間
 */
HSV* ColorMonitor::getHSV(){
    rgb_raw_t rgb;
    mColorSensor.getRawColor(rgb);
    RGBtoHSV *rgbTo = new RGBtoHSV(rgb);

    return rgbTo->mHSV;
}