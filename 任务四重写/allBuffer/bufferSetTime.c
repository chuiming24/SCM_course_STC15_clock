#define uint unsigned int
#define uchar unsigned char
#define u32 long unsigned int
#include <bufferSetTime.h>

uchar setTime_tempCnt = 5;
uchar setTIme_tempNumber[6] = {0};


/*********************������ʱ�仺������д��һ������********************/
/*˵�����˺���Ҫ��������ʱ�������ʱ����0-9ʱ����ã��Ὣ���ֱ��浽������������ת����һλ
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

/*********************���ʱ�����û�����********************/
/*˵�����˺���������ջ�����
*/
void delTimeTemp(){
    uchar i;
    for(i = 0; i < 6; i++){
        setTIme_tempNumber[i] = 0;   
    }
    setTime_tempCnt = 5;
}