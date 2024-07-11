/******************************************************************************
 *  SelectWalker.cpp
 *  複数の走行モードを切り替えて走行する
 *****************************************************************************/

#include <stdlib.h>

#include "SelectWalker.h"

/**
 * コンストラクタ
 * @param lineTracer      ライントレーサ
 * @param timerWalker     タイマーウォーカー
 * @param turnWalker      ターンウォーカー
 * @param starter         スタータ 
 * @param colorMonitor    カラーモニター 
 * @param walker          走行 
 * @param timer           タイマー 
 * @param pidControl      PID制御 
 */
SelectWalker::SelectWalker(LineTracer* lineTracer,
                           TimerWalker* timerWalker,
                           TurnWalker* turnWalker,
                           const Starter* starter,
                           ColorMonitor* colorMonitor,
                           Walker* walker,
                           SimpleTimer* timer,
                           PidControl* pidControl)
    : mLineTracer(lineTracer),
      mTimerWalker(timerWalker),
      mTurnWalker(turnWalker),
      mStarter(starter),
      mState(UNDEFINED),
      mColorMonitor(colorMonitor),
      mWalker(walker),
      mSimpleTimer(timer),
      mPidControl(pidControl){
    mWalker->init();
}

/**
 * 複数の走行方法を切り替える
 */
void SelectWalker::run() {
    checkColor();
    switch (mState) {
    case UNDEFINED:
        execUndefined();
        break;
    case WAITING_FOR_START:
        execWaitingForStart();
        break;
    case LINE_TRACING:
        mLineTracer->run();
        break;
    case TIMER_WALKING:
        walk_speed = mTimerWalker->run(); 
        break;
    case TURN_WALKING:
        mTurnWalker->run();
        break;
    // case STOPED:
    //     break;
    default:
        break;
    }
    if(walk_speed == 0){
        mState = STOPED;
    }
}

/**
 * 未定義状態の処理
 */
void SelectWalker::execUndefined() {
    mState = WAITING_FOR_START;
}

/**
 * 開始待ち状態の処理
 */
void SelectWalker::execWaitingForStart() {
    if (mStarter->isPushed()) {
        mState = LINE_TRACING;
        mLineTracer = new LineTracer(mWalker, mPidControl, walk_speed);
        printf("PUSH\n");
    }
}

/**
 * 色を判断する
 */
void SelectWalker::checkColor(){
    colorid_t tmp = mColorMonitor->getColorid();
    if(tmp == colorid || tmp == COLOR_NONE) { return; }

    colorid = tmp;
    changeMode();
}

/**
 * 走行状態を切り替える
 */
void SelectWalker::changeMode(){
    if(mState == UNDEFINED ||  mState == WAITING_FOR_START) {return; }

    switch (colorid)
    {
        case COLOR_RED:
            mState = TIMER_WALKING;
            walk_speed = 10;
            mTimerWalker = new TimerWalker(mWalker, mSimpleTimer, walk_speed, 15500);
            printf("TIMER_WALKING\n");
            break;
        case COLOR_GREEN:
            mState = TURN_WALKING;
            walk_speed = 10;
            mTurnWalker = new TurnWalker(mWalker, mSimpleTimer, walk_speed, 2000);
            printf("TURN_WALKING\n");
            break;
        case COLOR_BLUE:
            walk_speed -= 35;
        case COLOR_BLACK:
            mState = LINE_TRACING;
            mLineTracer = new LineTracer(mWalker, mPidControl, walk_speed);
            printf("LINE_TRACING\n");
            break;
        
        default:
            break;
    }
}
