/******************************************************************************
 *  LineTracer.cpp (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/26
 *  Implementation of the Class LineTracer
 *  Author: Kazuhiro Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#include "LineTracer.h"

/**
 * コンストラクタ
 * @param walker     走行
 * @param pidControl PID制御
 * @param speed      速度
 */
LineTracer::LineTracer(Walker* walker, PidControl* pidControl, int speed)
    : mWalker(walker),
      mPidControl(pidControl){
    pwm = speed;
    mWalker->init();
    mWalker->run(pwm, pwm);
}

/**
 * ライントレースする
 */
void LineTracer::run() {
    double turn = mPidControl->calc_pid_value();
    if(turn > pwm){
      turn = pwm;
    }
    else if(turn < 0 && (-1) * turn > pwm){
      turn = (-1) * pwm;
    }

    int pwm_l = pwm + turn;
    int pwm_r = pwm - turn;

    if(pwm == 10 && turn == 0.0){
      goStraightCount++;
    }

    if (goStraightCount > 100){
        pwm_l = pwm;
        pwm_r = pwm;
    }

    mWalker->run(pwm_l, pwm_r);
    // printf("%f,%d,%d\n", turn, pwm_r, pwm_l);
}