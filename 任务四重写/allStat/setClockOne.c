#define uint unsigned int
#define uchar unsigned char
#define u32 long unsigned int
#include <STC15F2K60S2.H>
#include <dsp.h>
#include <stat.h>
#include <key.h>
#include <bufferSetTime.h>

#include <showTime.h>
#include <setTime.h>
#include <setClockOne.h>

extern uchar time_blinkFlag;

uchar clockOneSec;
uchar clockOneMin;
uchar clockOneHour;

/*********************设置闹钟初始化********************/
/*说明：此函数用于在进入设置时钟时候载入当前时钟
*/
void initBufferClockOne(){
    setTIme_tempNumber[0] = clockOneSec%10;
    setTIme_tempNumber[1] = clockOneSec/10%10;
    setTIme_tempNumber[2] = clockOneMin%10;
    setTIme_tempNumber[3] = clockOneMin/10%10;
    setTIme_tempNumber[4] = clockOneHour%10;
    setTIme_tempNumber[5] = clockOneHour/10%10;
}


void initSetClockOne(){
    initBufferClockOne();
}
void jumpSetClockOne(){
    switch(input){
        case 0:
        case 1:
        case 2:
        case 3:    
        case 4:
        case 5:    
        case 6:
        case 7:
        case 8:
        case 9:
            setTimeNum(input);
            break;
        case 11:
            clockOneSec = setTIme_tempNumber[0]+setTIme_tempNumber[1]*10;
            clockOneMin = setTIme_tempNumber[2]+setTIme_tempNumber[3]*10;
            clockOneHour = setTIme_tempNumber[4]+setTIme_tempNumber[5]*10;
            delTimeTemp();
            nowStat = showTime;
            break;
    }    
}
//void timeSetClockOne();
//void cleckSetClockOne();
void dspSetClockOne(){
    uchar i;
	for(i = 0; i < 6; i++){
        
        if(setTime_tempCnt == i && time_blinkFlag == 0){
            dis_buf[setTime_tempCnt] = 16;
        }else{
            dis_buf[i] = setTIme_tempNumber[i];
        }
        
	}
	dis_buf[6] = 16;
	dis_buf[7] = 10;
}
//void destroySetClockOne();
