/******************************************************************************
 *  TimerWalker.h (for LEGO Mindstorms EV3)
 *  Created on: 2015/02/07
 *  Implementation of the Class TimerWalker
 *  Author: Kenya Yabe
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#ifndef EV3_APP_TimerWalker_H_
#define EV3_APP_TimerWalker_H_

#include "Walker.h"
#include "SimpleTimer.h"

class TimerWalker {
public:
    TimerWalker(Walker* walker, SimpleTimer* timer, int speed, int time);

    int run();
private:
    Walker* mWalker;
    SimpleTimer* mSimpleTimer;

    int walk_speed = 30;
    int setting_time;

    void go_straight();
    void stop_walking();
};

#endif  // EV3_APP_TimerWalker_H_
