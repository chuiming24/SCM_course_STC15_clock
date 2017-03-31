#define uint unsigned int
#define uchar unsigned char
#define u32 long unsigned int
#include <STC15F2K60S2.H>
#include <dsp.h>
#include <stat.h>
#include <key.h>

uchar time_inputScanFlag = 0;
uchar time_inputScanCnt = 0;
uchar time_blinkFlag = 0;
uint time_blinkCnt = 0;

#include <gpio.h> 
void Timer0Init(void)		//1����@12.000MHz
{
	AUXR &= 0x7F;		//��ʱ��ʱ��12Tģʽ
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0x18;		//���ö�ʱ��ֵ
	TH0 = 0xFC;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
}

void main(){
    gpio();
    Timer0Init();
    ET0 = 1;
    EA = 1;
    while(1){
        cleckAll();
        if(time_inputScanFlag == 1){
            time_inputScanFlag = 0;
            scanKey();
        }
        if(inputFlag == 1){
            inputFlag = 0;
            jumpAll();
        }        
        dspAll();
    }
}


void timer0() interrupt 1{
	TL0 = 0x18;		//���ö�ʱ��ֵ
	TH0 = 0xFC;		//���ö�ʱ��ֵ
	display();
        
    time_inputScanCnt++;
    if(time_inputScanCnt == 10){
        time_inputScanCnt = 0;
        time_inputScanFlag = 1;
    }
    
    time_blinkCnt++;
    if(time_blinkCnt == 300){
        time_blinkCnt = 0;
        if(time_blinkFlag == 1){
            time_blinkFlag = 0;
        }else{
            time_blinkFlag = 1;
        }
    }
    
    timeAll();
}