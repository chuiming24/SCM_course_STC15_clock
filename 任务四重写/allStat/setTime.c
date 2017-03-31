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

extern uchar time_blinkFlag;


/*********************设置时钟初始化********************/
/*说明：此函数用于在进入设置时钟时候载入当前时钟
*/
void initBufferSetTime(){
    setTIme_tempNumber[0] = nowSec%10;
    setTIme_tempNumber[1] = nowSec/10%10;
    setTIme_tempNumber[2] = nowMin%10;
    setTIme_tempNumber[3] = nowMin/10%10;
    setTIme_tempNumber[4] = nowHour%10;
    setTIme_tempNumber[5] = nowHour/10%10;
}



void initSetTime(){
    initBufferSetTime();
}


void jumpSetTime(){
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
        case 10:
            nowSec = setTIme_tempNumber[0]+setTIme_tempNumber[1]*10;
            nowMin = setTIme_tempNumber[2]+setTIme_tempNumber[3]*10;
            nowHour = setTIme_tempNumber[4]+setTIme_tempNumber[5]*10;
            delTimeTemp();
            nowStat = showTime;
            break;
    }    
}

//void cleckSetTime();
void dspSetTime(){
	uchar i;
	for(i = 0; i < 6; i++){
        
        if(setTime_tempCnt == i && time_blinkFlag == 0){
            dis_buf[setTime_tempCnt] = 16;
        }else{
            dis_buf[i] = setTIme_tempNumber[i];
        }
        
	}

	dis_buf[6] = 16;
	dis_buf[7] = 16;
}
