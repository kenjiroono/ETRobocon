/******************************************************************************
 *  TurnWalker.h 
 *  ターン走行をする
 *****************************************************************************/

#ifndef EV3_APP_TurnWalker_H_
#define EV3_APP_TurnWalker_H_

#include "Walker.h"
#include "SimpleTimer.h"

class TurnWalker {
public:
    TurnWalker(Walker* walker, SimpleTimer* timer, int speed, int time);
    void run();

private:
    Walker* mWalker;
    SimpleTimer* mSimpleTimer;

    int walk_speed = 30;
    int setting_time;

    void execTurn();
    void execGoStraight();
};

#endif  // EV3_APP_TurnWalker_H_
