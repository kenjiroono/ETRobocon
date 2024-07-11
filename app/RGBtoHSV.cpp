#include "RGBtoHSV.h"

/**
 * コンストラクタ
 * @param rgb カラー
 */
RGBtoHSV::RGBtoHSV(rgb_raw_t rgb){
    double R = rgb.r;
    double G = rgb.g;
    double B = rgb.b;

	double maximum = std::max((std::max(R,G)),B);
	double minimun = std::min((std::min(R,G)),B);

    double hue = 0; //色相
    double saturation = 0;  //彩度
	double value = maximum/256*100;;   //明度
    
	if(maximum != minimun){
		if(maximum == R){
			hue = 60.0*(G-B)/(maximum-minimun) + 0;
		}
		else if(maximum == G){
			hue = 60.0*(B-R)/(maximum-minimun) + 120.0;
		} 
		else if(maximum == B){
			hue = 60.0*(R-G)/(maximum-minimun) + 240.0;
		} 

		if(hue > 360.0){
			hue = hue - 360.0;
		} 
		else if(hue < 0){
			hue = hue + 360.0;
		} 
		saturation = (maximum-minimun)/maximum*100.0;
	}

	mHSV = new HSV(hue, saturation, value);
}