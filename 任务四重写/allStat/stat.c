#define uint unsigned int
#define uchar unsigned char
#define u32 long unsigned int
#include <STC15F2K60S2.H>
#include <dsp.h>
#include <stat.h>
#include <key.h>


enum stat nowStat = showTime;

#include <showTime.h>
#include <setTime.h>
#include <setClockOne.h>
#include <setClockTwo.h>
#include <inWatch.h>
#include <inDownWatch.h>



//Cleck事件检查
void cleckAll(){
    switch(nowStat){
        case showTime:
            cleckShowTime();
            break;
        case setTime:
            break;
        case setClockOne:
            break;
        case setClockTwo:
            break;
        case inWatch:
            break;
        case inDownWatch:
            break;
    }
}

//Jump跳转函数
void jumpAll(){
    switch(nowStat){
        case showTime:
            jumpShowTime();
            break;
        case setTime:
            jumpSetTime();
            break;
        case setClockOne:
            jumpSetClockOne();
            break;
        case setClockTwo:
            jumpSetClockTwo();
            break;
        case inWatch:
            jumpinWatch();
            break;
        case inDownWatch:
            jumpinDownWatch();
            break;
    }
}

//Time时间函数

void timeAll(){
    timeShowTime();
    switch(nowStat){
        case showTime:
            break;
        case setTime:
            break;
        case setClockOne:
            break;
        case setClockTwo:
            break;
        case inWatch:
            timeinWatch();
            break;
        case inDownWatch:
            timeinDownWatch();
            break;
    }
}

//dsp显示函数
void dspAll(){
    switch(nowStat){
        case showTime:
            dspShowTime(nowSec, nowMin, nowHour);
            break;
        case setTime:
            dspSetTime();
            break;
        case setClockOne:
            dspSetClockOne();
            break;
        case setClockTwo:
            dspSetClockTwo();
            break;
        case inWatch:
            dspinWatch();
            break;
        case inDownWatch:
            dspinDownWatch();
            break;
    }
}