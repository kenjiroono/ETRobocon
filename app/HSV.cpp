/******************************************************************************
 *  HSV.cpp 
 *  HSV色空間のパラメータ保持クラス
 *****************************************************************************/
#include "HSV.h"

/**
 * コンストラクタ
 * @param hue        色相
 * @param saturation 彩度
 * @param value      明度
 */
HSV::HSV(double hue, double saturation, double value)
    :H(hue),
     S(saturation),
     V(value) {
}