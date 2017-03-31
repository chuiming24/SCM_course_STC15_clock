#define uint unsigned int
#define uchar unsigned char
#define u32 long unsigned int
#include <STC15F2K60S2.H>
#include <dsp.h>
#include <key.h>

uchar inputFlag = 0;
uchar input = 0;



void Delay10ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 108;
	j = 145;
	do
	{
		while (--j);
	} while (--i);
}

/*********************按键扫描********************/
/*说明：10为调时，11为闹钟1，12为脑钟2，13为ESC，14为秒表，15为倒计时
*/
void scanKey(){

	uchar temp;

	P1 = 0x7f;
	temp = P1;
	temp = temp & 0x0f;
	if(temp != 0x0f){
		Delay10ms();
		temp = P1;
		temp = temp & 0x0f;
		if(temp != 0x0f){
		 	temp = P1;
			inputFlag = 1;
			switch(temp){
				case 0x77: input = 1; break;
				case 0x7b: input = 2; break;
				case 0x7d: input = 3; break;
				case 0x7e: input = 10; break;
				default : break;
			}
			while (temp != 0x0f){
					temp = P1;
					temp = temp & 0x0f;
			}
		}	
	}

	P1 = 0xbf;
	temp = P1;
	temp = temp & 0x0f;
	if(temp != 0x0f){
		Delay10ms();
		temp = P1;
		temp = temp & 0x0f;
		if(temp != 0x0f){
			temp = P1;
			inputFlag = 1;
			switch(temp){
				case 0xb7: input = 4; break;
				case 0xbb: input = 5; break;
				case 0xbd: input = 6; break;
				case 0xbe: input = 11; break;
				default: break;
			}
			while(temp != 0x0f){
				temp = P1;
				temp = temp & 0x0f;
			}
		}		
	}
   	
	P1 = 0xdf;
	temp = P1;
	temp = temp & 0x0f;
	if(temp != 0x0f){
		Delay10ms();
		temp = P1;
		temp = temp & 0x0f;
		if(temp != 0x0f){
			temp = P1;
			inputFlag = 1;
			switch (temp){
				case 0xd7: input = 7; break;
				case 0xdb: input = 8; break;
				case 0xdd: input = 9; break;
				case 0xde: input = 12; break;
				default: break;
			}
			while(temp != 0x0f){
				temp = P1;
				temp = temp & 0x0f;
			}	
		}		
	}

	P1 = 0xef;
	temp = P1;
	temp = temp & 0x0f;
	if( temp != 0x0f){
		Delay10ms();
		temp = P1;
		temp = temp & 0x0f;
		if(temp != 0x0f){
			temp = P1;
			inputFlag = 1;
			switch(temp){
				case 0xe7: input = 13; break;
				case 0xeb: input = 0; break;
				case 0xed: input = 14; break;
				case 0xee: input = 15; break;
				default: break;
			}
			while(temp != 0x0f){
				temp = P1;
				temp = temp & 0x0f;
			}
		}
	}
}