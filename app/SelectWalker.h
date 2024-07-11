/******************************************************************************
 *  SelectWalker.h
 *  複数の走行モードを切り替えて走行する
 *****************************************************************************/

#ifndef EV3_APP_SELECTWALKER_H_
#define EV3_APP_SELECTWALKER_H_

#include "Starter.h"
#include "ColorMonitor.h"

#include "LineTracer.h"
#include "TimerWalker.h"
#include "TurnWalker.h"

class SelectWalker {
public:
    SelectWalker(LineTracer* lineTracer,
                TimerWalker* timerWalker,
                TurnWalker* turnWalker,
                const Starter* starter,
                ColorMonitor* colorMonitor,
                Walker* walker,
                SimpleTimer* timer,
                PidControl* pidControl);

    void run();

private:
    enum State {
        UNDEFINED,
        WAITING_FOR_START,
        LINE_TRACING,
        TIMER_WALKING,
        TURN_WALKING,
        STOPED
    };

    State mState;
    colorid_t colorid;
    
    int walk_speed = 85;

    LineTracer* mLineTracer;
    TimerWalker* mTimerWalker;
    TurnWalker* mTurnWalker;

    const Starter* mStarter;
    Walker* mWalker;
    SimpleTimer* mSimpleTimer;
    ColorMonitor* mColorMonitor;
    PidControl* mPidControl;

    void execUndefined();
    void execWaitingForStart();

    void checkColor();
    void changeMode();

};

#endif  // EV3_APP_SELECTWALKER_H_
