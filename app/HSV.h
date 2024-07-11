/******************************************************************************
 *  HSV.h
 *  HSV色空間のパラメータ保持クラス
 *****************************************************************************/

class HSV {
public:
    HSV(double hue, double saturation, double value);
    ~HSV();
    
    double const H; // 色相
    const double S; // 彩度
    const double V; // 明度
};