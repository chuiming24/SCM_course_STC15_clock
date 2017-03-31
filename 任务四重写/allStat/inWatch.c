#define uint unsigned int
#define uchar unsigned char
#define u32 long unsigned int
#include <STC15F2K60S2.H>
#include <dsp.h>
#include <stat.h>
#include <key.h>

#include <showTime.h>
#include <inWatch.h>

u32 inWatchTime = 0;
uchar inWatchOpen = 0;
uint time_inWatchCnt = 0;

void initinWatch(){
    inWatchTime = 0;
    inWatchOpen = 0;
}
void jumpinWatch(){
    switch(input){
        case 14:
            if(inWatchOpen == 1){
                inWatchOpen = 0;
            }else{
                inWatchOpen = 1;
            }
            break;
        case 13:
            inWatchOpen = 0;
            inWatchTime = 0; 
            time_inWatchCnt = 0;        
            nowStat = showTime;
            break;
    }     
}
void timeinWatch(){
    if(inWatchOpen == 1){
        time_inWatchCnt++;
        if(time_inWatchCnt == 100){
            time_inWatchCnt = 0;
            inWatchTime++;
        }
    }     
}
//void cleckinWatch();
void dspinWatch(){
    u32 a = inWatchTime;    
	uchar i = 7;
	for(i = 0; i < 8; i++){
        if(i == 1){
            dis_buf[i] = a %10 + 17;
        }else{
            dis_buf[i] = a %10;
        }		
		a /= 10;	
	}
}
//void destroyinWatch();
