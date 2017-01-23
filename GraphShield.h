/*

  Project:       1Sheeld Library 
  File:          GraphShield.h
                 
  Version:       1.12.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2016.12

*/
#ifndef GraphShield_h
#define GraphShield_h

#include "ShieldParent.h"

//Output Function ID
#define GRAPH_PLOT            0x01
#define GRAPH_CLEAR           0x02
#define GRAPH_AUTO_SCROLL     0x03
#define GRAPH_SAVE_CSV        0x04
#define GRAPH_SAVE_SCREENSHOT 0x05

//Input Function ID

//Literals
#define CHART_0     0x00
#define CHART_1     0x01
#define CHART_2     0x02
#define CHART_3     0x03
#define CHART_4     0x04


class GraphShield : public ShieldParent
{
public:
  GraphShield();
  void clear(byte);
  void add(const char *,float,byte =0);
  void plot();
  void saveCsv(const char *,byte);
  void saveScreenShot(byte=0);
  void autoScroll(byte);
private:
  byte keysCounter;
  char * key;
  char * namesArray[5];
  float  floatArray[5];
  byte   chartIDArray[5];
};

extern GraphShield Graph;
#endif