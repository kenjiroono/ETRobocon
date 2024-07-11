/******************************************************************************
 *  LineTracer.h (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/25
 *  Definition of the Class LineTracer
 *  Author: Kazuhiro Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#ifndef EV3_APP_LINETRACER_H_
#define EV3_APP_LINETRACER_H_

#include "Walker.h"
#include "PidControl.h"

class LineTracer {
public:
    static const double DELTA_T;
    LineTracer(Walker* walker, PidControl* pidControl, int speed);

    void run();

private:
    Walker* mWalker;
    PidControl* mPidControl;

    int pwm = 85;
    int goStraightCount = 0;
};

#endif  // EV3_APP_LINETRACER_H_
