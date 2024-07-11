/******************************************************************************
 *  TurnWalker.cpp
 *  ターン走行をする
 *****************************************************************************/

#include "TurnWalker.h"

/**
 * コンストラクタ
 * @param walker          走行
 * @param timer           タイマ
 * @param speed           走行速度
 * @param time            タイマー値
 */
TurnWalker::TurnWalker(Walker* walker, SimpleTimer* timer, int speed, int time)
    : mWalker(walker),
      mSimpleTimer(timer){
    walk_speed = speed;
    setting_time = time;
    mSimpleTimer->setTime(setting_time * 1000);
    mSimpleTimer->start();
}

/**
 * 旋回して直進する
 */
void TurnWalker::run() {
    if (mSimpleTimer->isTimedOut()){
        execGoStraight();
    }
    else{
        execTurn();
    }
}

/**
 * 旋回する
 */
void TurnWalker::execTurn() {
    mWalker->run(0, 30);
}

/**
 * 直進する
 */
void TurnWalker::execGoStraight() {
    mWalker->run(walk_speed, walk_speed);
}
