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
#include <setClockTwo.h>

extern uchar time_blinkFlag;

uchar clockTwoSec = 0;
uchar clockTwoMin = 0;
uchar clockTwoHour = 0;

void bufferInitClockTwo(){
    setTIme_tempNumber[0] = clockTwoSec%10;
    setTIme_tempNumber[1] = clockTwoSec/10%10;
    setTIme_tempNumber[2] = clockTwoMin%10;
    setTIme_tempNumber[3] = clockTwoMin/10%10;
    setTIme_tempNumber[4] = clockTwoHour%10;
    setTIme_tempNumber[5] = clockTwoHour/10%10;
}

void initSetClockTwo(){
    bufferInitClockTwo();
}
void jumpSetClockTwo(){
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
        case 12:
            clockTwoSec = setTIme_tempNumber[0]+setTIme_tempNumber[1]*10;
            clockTwoMin = setTIme_tempNumber[2]+setTIme_tempNumber[3]*10;
            clockTwoHour = setTIme_tempNumber[4]+setTIme_tempNumber[5]*10;
            delTimeTemp();
            nowStat = showTime;
            break;
    }    
}
//void timeSetClockTwo();
//void cleckSetClockTwo();
void dspSetClockTwo(){
	uchar i;
	for(i = 0; i < 6; i++){
        
        if(setTime_tempCnt == i && time_blinkFlag == 0){
            dis_buf[setTime_tempCnt] = 16;
        }else{
            dis_buf[i] = setTIme_tempNumber[i];
        }
        
	}

	dis_buf[6] = 16;
	dis_buf[7] = 11;
}
//void destroySetClockTwo();