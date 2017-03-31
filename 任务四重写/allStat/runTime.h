#ifndef _SHOWTIME_H_
#define _SHOWTIME_H_

extern uchar nowSec;
extern uchar nowMin;
extern uchar nowHour;

//void initShowTime();
void jumpShwoTime();
void timeShowTime();
//void cleckShowTime();
void dspShowTime(uchar sec, uchar min, uchar hour);
//void destroy();

#endif