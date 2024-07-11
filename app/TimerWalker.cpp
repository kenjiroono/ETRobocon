/******************************************************************************
 *  TimerWalker.cpp 
 *  タイマー秒数分走行する
 *****************************************************************************/

#include "TimerWalker.h"

/**
 * コンストラクタ
 * @param walker          走行
 * @param timer           タイマ
 * @param speed           走行速度
 * @param time            タイマー値
 */
TimerWalker::TimerWalker(Walker* walker, SimpleTimer* timer, int speed, int time)
    : mWalker(walker),
      mSimpleTimer(timer){
    walk_speed = speed;
    setting_time = time;
    mSimpleTimer->setTime(setting_time * 1000);
    mSimpleTimer->start();
}

/**
 * タイマーが停止するまで前進する
 * @retval walk_speed  走行速度
 */
int TimerWalker::run(){
    if (mSimpleTimer->isTimedOut()){
        stop_walking();
    }
    else{
        go_straight();
    }
    return walk_speed;
}

/**
 * 停止する
 */
void TimerWalker::stop_walking() {
    walk_speed = 0;
    mWalker->run(walk_speed, walk_speed);
}

/**
 * 前進する
 */
void TimerWalker::go_straight() {
    mWalker->run(walk_speed, walk_speed);
}