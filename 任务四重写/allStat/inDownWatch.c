#define uint unsigned int
#define uchar unsigned char
#define u32 long unsigned int
#include <STC15F2K60S2.H>
#include <dsp.h>
#include <stat.h>
#include <key.h>
#include <bufferInWatch.h>

#include <showTime.h>
#include <inDownWatch.h>

extern uchar time_blinkFlag;

u32 inDownWatchTime = 6000;
uchar inDownWatchOpen = 0;
bit setWatchNum_flag = 1;
uint time_inDownWatchCnt = 0;

void initinDownWatch(){
    
}
void jumpinDownWatch(){
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
            if(setWatchNum_flag == 1){
                setWatchNum(input);
            }
            break;        
        case 15:
            if(setWatchNum_flag == 1){
                setWatchNum_flag = 0;
                inDownWatchTime = tansWatchNum();
                
            }else if(setWatchNum_flag == 0){
                if(inDownWatchOpen == 1){
                    inDownWatchOpen = 0;
                }else{
                    inDownWatchOpen = 1;
                }
            }
            break;
        case 13:
            inDownWatchOpen = 0;
            inDownWatchTime = 0; 
            time_inDownWatchCnt = 0; 
            setWatchNum_flag = 1;
            inDownWatchTime = 0;
            setWatchNum_tempCnt = 0;
            delWatchNum();
            nowStat = showTime;
            P30 = 1;
            break;
    }     
}
void timeinDownWatch(){
    if(inDownWatchOpen == 1){
        time_inDownWatchCnt++;
        if(time_inDownWatchCnt == 100){
            time_inDownWatchCnt = 0;
            if(inDownWatchTime != 0){
                inDownWatchTime--;
            }else{
                P30 = 0;
            }
        }
    }      
}
//void cleckinDownWatch();
void dspinDownWatch(){
    if(setWatchNum_flag){
        uchar i;
        for(i = 0; i < 8; i++){        
            if(setWatchNum_tempCnt == i && time_blinkFlag == 0){
                dis_buf[setWatchNum_tempCnt] = 16;
            }else if(i == 1){
                dis_buf[i] = setWatchNum_tempNum[i]+17;
            }else{
                dis_buf[i] = setWatchNum_tempNum[i];
            }
            
	}
    }else{
        u32 a = inDownWatchTime; 
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
}
//void destroyinDownWatch();