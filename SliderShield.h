/*

  Project:       1Sheeld Library 
  File:          SliderShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef SliderShield_h
#define SliderShield_h

//Input Function ID
#define SLIDER_VALUE 0x01

class SliderShield
{
public:
	//Constructor
	SliderShield();
	//Getter
	byte getValue();
	//setOnChange for Users Function
	void setOnValueChange(void (*userFunction)(byte));
private:
	//Reserve Variable 
	byte value;	
	//Boolean For setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data 
	void processData();
	void(*changeCallBack)(byte);

	friend class OneSheeldClass;



};

//Extern Object
extern SliderShield Slider;
#endif
