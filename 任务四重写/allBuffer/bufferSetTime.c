#define uint unsigned int
#define uchar unsigned char
#define u32 long unsigned int
#include <bufferSetTime.h>

uchar setTime_tempCnt = 5;
uchar setTIme_tempNumber[6] = {0};


/*********************在设置时间缓冲区中写入一个数字********************/
/*说明：此函数要求在设置时间或闹钟时候按下0-9时候调用，会将数字保存到缓冲区，并跳转至下一位
*/
void setTimeNum(uchar input){
    switch(setTime_tempCnt){
        case 0:
        case 2:
        case 4:
            setTIme_tempNumber[setTime_tempCnt] = input;
            if(setTime_tempCnt == 0){
                setTime_tempCnt = 6;
            }
            setTime_tempCnt--;
            break;
        case 1:
        case 3:
            if(input <= 6){
                setTIme_tempNumber[setTime_tempCnt] = input;
                setTime_tempCnt--;
            }    
            break;
        case 5:
            if(input <= 2){
                setTIme_tempNumber[setTime_tempCnt] = input;
                setTime_tempCnt--;
            }
            break;    
    }
}

/*********************清空时间设置缓冲区********************/
/*说明：此函数用于清空缓冲区
*/
void delTimeTemp(){
    uchar i;
    for(i = 0; i < 6; i++){
        setTIme_tempNumber[i] = 0;   
    }
    setTime_tempCnt = 5;
}