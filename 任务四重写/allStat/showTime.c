#define uint unsigned int
#define uchar unsigned char
#define u32 long unsigned int
#include <STC15F2K60S2.H>
#include <dsp.h>
#include <stat.h>
#include <key.h>

#include <showTime.h>
#include <setTime.h>
#include <setClockOne.h>
#include <setClockTwo.h>
#include <inWatch.h>
#include <inDownWatch.h>

uchar nowSec = 0;
uchar nowMin = 0;
uchar nowHour = 0;

uint timeShowTimeCnt = 0;

bit clockOneBeepFlag = 0;
bit clockTwoBeepFlag = 0;

uint time_clockBeepCnt = 0;
uchar code clockOneBeep[10] = {0, 1, 1, 1};
uchar code clockTwoBeep[10] = {1, 0, 1, 0};
uchar clockBeepCnt = 0;

/*********************时钟状态跳转********************/
/*说明：此函数要求在显示时间的状态下，遇到有按键按下时候方可调用
*/
void jumpShowTime(){
    switch(input){
        case 10:
            initSetTime();
            nowStat = setTime;
            break;
        case 11:
            initSetClockOne();
            nowStat = setClockOne;
            break;   
        case 12:
            initSetClockTwo();
            nowStat = setClockTwo;
            break;
        case 13:
            clockOneBeepFlag = 0;
            clockTwoBeepFlag = 0;
            break;        
        case 14:
            initinWatch();
            nowStat = inWatch;
            break;
        case 15:
            initinDownWatch();
            nowStat = inDownWatch;                
            break;        
    }      
}



/*********************时钟运行********************/
/*说明：此函数要求在定时器中每一秒运行一次
*/
void runTime(){
    nowSec++;
    if(nowSec == 60){
        nowSec = 0;
        nowMin++;
        if(nowMin == 60){
            nowMin = 0;
            nowHour++;
            if(nowHour == 24){
                nowHour = 0;
            }
        }
    }

}

void timeShowTime(){
    timeShowTimeCnt++;
    if(timeShowTimeCnt == 1000){
        timeShowTimeCnt = 0;
        runTime();
    }
    
    if(clockOneBeepFlag == 1 || clockTwoBeepFlag == 1){
        time_clockBeepCnt++;
        if(time_clockBeepCnt == 200){
            time_clockBeepCnt = 0;
            if(clockOneBeepFlag == 1){
                P30 = clockOneBeep[clockBeepCnt];
            }else if(clockTwoBeepFlag == 1){
                P30 = clockTwoBeep[clockBeepCnt];
            }
            if(++clockBeepCnt == 4)clockBeepCnt = 0;
        }
    }else{
        P30 = 1;
    }            
}

void cleckShowTime(){
    if(nowSec == clockOneSec && nowMin == clockOneMin && nowHour == clockOneHour){
        clockOneBeepFlag = 1;
    }
    if(nowSec == clockTwoSec && nowMin == clockTwoMin && nowHour == clockTwoHour){
        clockTwoBeepFlag = 1;
    }    
}

void dspShowTime(uchar sec, uchar min, uchar hour){
	uchar i;
	for(i = 0; i < 2; i++){
		dis_buf[i] = sec %10;
		sec /= 10;	
	}
	for(i = 2; i < 4; i++){
		dis_buf[i] = min %10;
		min /= 10;	
	}
	for(i = 4; i < 6; i++){
		dis_buf[i] = hour %10;
		hour /= 10;	
	}
	dis_buf[6] = 16;
	dis_buf[7] = 16;
}
