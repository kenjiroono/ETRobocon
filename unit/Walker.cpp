/******************************************************************************
 *  Walker.cpp (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/25
 *  Implementation of the Class Walker
 *  Author: Kazuhiro.Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#include "Walker.h"

// 定数宣言
const int Walker::LOW    = 30;    // 低速
const int Walker::NORMAL = 50;    // 通常
const int Walker::HIGH   = 70;    // 高速

const int Walker::RIGHT  = 0;     // 左方向
const int Walker::LEFT   = 1;     // 右方向

/**
 * コンストラクタ
 * @param leftWheel  左モータ
 * @param rightWheel 右モータ
 */
Walker::Walker(ev3api::Motor& leftWheel, ev3api::Motor& rightWheel)
    : mLeftWheel(leftWheel),
      mRightWheel(rightWheel),
      mPower(LOW),
      mMove(RIGHT) {
}

/**
 * 走行する
 * @param left_power  左モータ値
 * @param right_power 右モータ値
 */
void Walker::run(int left_power, int right_power) {
    
    mRightWheel.setPWM(right_power);
    mLeftWheel.setPWM(left_power);
}

/**
 * 走行に必要なものをリセットする
 */
void Walker::init() {
    // モータをリセットする
    mLeftWheel.reset();
    mRightWheel.reset();
}

/**
 * PWM値を設定する
 * @param power モーターに与えるパワー
 * @param move    動きの対応番号（0: 左方向, 1: 右方向, 2: 直進, 3: 左旋回）
 */
void Walker::setCommand(int power, int move) {
    mPower = power;
    mMove  = move;
}