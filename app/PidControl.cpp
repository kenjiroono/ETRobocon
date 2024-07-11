#include "PidControl.h"

PidControl::PidControl(ColorMonitor* colorMonitor)
    : mColorMonitor(colorMonitor){

}

/**
 * PID制御で左右のモータに与えるパワー差を返す
 * @retval turn 左右のパワー差
 */
double PidControl::calc_pid_value() {
    double DELTA_T = 0.004;
    
    mDiff[0] = mDiff[1];
    int bright = mColorMonitor->getBrightness();
    mDiff[1] = bright - target;
    mIntegral += (((double)mDiff[0]) + ((double)mDiff[1])) / 2.0 * DELTA_T;
    double p = kp * (double)mDiff[1];
    double i = ki * mIntegral;
    double d = kd * (((double)mDiff[1]) - ((double)mDiff[0])) / DELTA_T;
    double turn = p + i + d;
    return turn;
}