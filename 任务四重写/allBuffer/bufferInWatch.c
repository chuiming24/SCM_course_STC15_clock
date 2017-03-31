#define uint unsigned int
#define uchar unsigned char
#define u32 long unsigned int
#include <bufferInWatch.h>
uchar setWatchNum_tempCnt = 0;
uchar setWatchNum_tempNum[8] = {0};


/*********************�����õ���ʱ��������д��һ������********************/
/*˵�����˺���Ҫ�������õ���ʱʱ����0-9ʱ����ã��Ὣ���ֱ��浽������������ת����һλ
*/
void setWatchNum(uchar input){
    setWatchNum_tempNum[setWatchNum_tempCnt] = input;
    setWatchNum_tempCnt++;
    if(setWatchNum_tempCnt == 8){
        setWatchNum_tempCnt = 0;
    }
}
/*********************������ת��********************/
/*˵�����˺������ڽ�������������ת��Ϊ�������
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
/*********************��յ���ʱ���û�����********************/
/*˵�����˺���������ջ�����
*/
void delWatchNum(){
    uchar i;
    for(i = 0; i < 8; i++){
        setWatchNum_tempNum[i] = 0;   
    }
}