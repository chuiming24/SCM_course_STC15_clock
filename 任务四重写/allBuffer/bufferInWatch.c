#define uint unsigned int
#define uchar unsigned char
#define u32 long unsigned int
#include <bufferInWatch.h>
uchar setWatchNum_tempCnt = 0;
uchar setWatchNum_tempNum[8] = {0};


/*********************在设置倒计时缓冲区中写入一个数字********************/
/*说明：此函数要求在设置倒计时时候按下0-9时候调用，会将数字保存到缓冲区，并跳转至下一位
*/
void setWatchNum(uchar input){
    setWatchNum_tempNum[setWatchNum_tempCnt] = input;
    setWatchNum_tempCnt++;
    if(setWatchNum_tempCnt == 8){
        setWatchNum_tempCnt = 0;
    }
}
/*********************缓冲区转换********************/
/*说明：此函数用于将缓冲区的数字转换为数字输出
*/
u32 tansWatchNum(){
    uchar i;
    u32 output = 0;
    output = output + setWatchNum_tempNum[7];
    for(i = 1; i < 8; i++){
        output *= 10;
        output += setWatchNum_tempNum[7-i];       
    }
    return output;
}
/*********************清空倒计时设置缓冲区********************/
/*说明：此函数用于清空缓冲区
*/
void delWatchNum(){
    uchar i;
    for(i = 0; i < 8; i++){
        setWatchNum_tempNum[i] = 0;   
    }
}