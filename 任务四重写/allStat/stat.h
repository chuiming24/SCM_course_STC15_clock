#ifndef _STAT_H_
#define _STAT_H_

enum stat{
    showTime, setTime, setClockOne, setClockTwo, inWatch, inDownWatch
};

extern enum stat nowStat;

void cleckAll();
void jumpAll();
void timeAll();
void dspAll();

#endif