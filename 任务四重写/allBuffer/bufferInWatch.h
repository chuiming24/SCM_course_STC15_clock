#ifndef _BUFFERINWATCH_H_
#define _BUFFERINWATCH_H_


extern uchar setWatchNum_tempCnt;
extern uchar setWatchNum_tempNum[8];


void setWatchNum(uchar input);
u32 tansWatchNum();
void delWatchNum();


#endif