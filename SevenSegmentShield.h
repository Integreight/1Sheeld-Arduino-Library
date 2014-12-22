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
#define SEVENSEGMENT_SET_VALUE 0x01 
#define SEVENSEGMENT_SET_DOT	 0x02
#define SEVENSEGMENT_SELECT_SHIELD    0x03
#define SEVENSEGMENT_UNSELECT_SHIELD  0x04

//Input Function ID's
#define SEVENSEGMENT_CHECK_SELECTED 0x01  

class SevenSegmentShieldClass
{

public:
	//Setters 
	void setNumber(byte );
	void setValue(byte  );
	void setDot();
  //Selection
  void select();
  void unselect();
  //Set On Selected
  void setOnSelected(void (*)(void));

private:
  void processData();

  void(*selectedCallBack)();

  friend class OneSheeldClass;
};

//Extern Object
extern SevenSegmentShieldClass SevenSegment;
#endif
