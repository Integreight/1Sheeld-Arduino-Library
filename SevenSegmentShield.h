/*

  Project:       1Sheeld Library 
  File:          SevenSegmentShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef SevenSegmentShield_h
#define SevenSegmentShield_h 

//Output Function ID's
#define SET_VALUE 0x01 
#define SET_DOT	0x02

class SevenSegmentShieldClass
{

public:
	//Setters 
	void setNumber(byte );
	void setValue(byte  );
	void setDot();


private:

};

//Extern Object
extern SevenSegmentShieldClass SevenSegment;
#endif
