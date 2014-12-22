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


//Output Function ID
#define SLIDER_SELECT_SHIELD	0x01
#define SLIDER_UNSELECT_SHIELD	0x02
//Input Function ID
#define SLIDER_VALUE 0x01
#define SLIDER_CHECK_SELECTED	0x02

class SliderShield
{
public:
	//Constructor
	SliderShield();
	//Getter
	byte getValue();
	//Selection
	void select();
	void unselect();
	//setOnChange for Users Function
	void setOnValueChange(void (*userFunction)(byte));
	void setOnSelected(void(*)(void));
private:
	//Reserve Variable 
	byte value;	
	//Boolean For setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data 
	void processData();
	void(*changeCallBack)(byte);
	void (*selectedCallBack)(void);
	friend class OneSheeldClass;



};

//Extern Object
extern SliderShield Slider;
#endif
