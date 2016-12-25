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
#define GRAPH_SAVE            0x02

//Input Function ID


//Literals
#define CSV        0x01
#define SCREENSHOT 0x02


class GraphShield : public ShieldParent
{
public:
  GraphShield();
  void add(const char *,float,byte =0);
  void plot();
  void save(byte);
private:
  byte keysCounter;
  char * key;
  char * namesArray[5];
  float  floatArray[5];
  byte   chartIDArray[5];
};

extern GraphShield Graph;
#endif