/*

  Project:       1Sheeld Library 
  File:          ChartShield.h
                 
  Version:       1.12.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2016.12

*/
#ifndef ChartShield_h
#define ChartShield_h

#include "ShieldParent.h"

//Output Function ID
#define CHART_PLOT            0x01
#define CHART_CLEAR           0x02
#define CHART_AUTO_SCROLL     0x03
#define CHART_SAVE_CSV        0x04
#define CHART_SAVE_SCREENSHOT 0x05

//Input Function ID

//Literals
#define CHART_0     0x00
#define CHART_1     0x01
#define CHART_2     0x02
#define CHART_3     0x03
#define CHART_4     0x04


class ChartShield : public ShieldParent
{
public:
  ChartShield();
  void clear(byte);
  void add(const char *,float,byte =0);
  void plot();
  void saveCsv(const char *,byte);
  void saveScreenshot(byte=0);
  void autoScroll(byte);
private:
  byte keysCounter;
  char * key;
  char * namesArray[5];
  float  floatArray[5];
  byte   chartIDArray[5];
};

extern ChartShield Chart;
#endif