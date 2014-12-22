/*

  Project:       1Sheeld Library 
  File:          ColorShield.h
                 
  Version:       1.3

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef ColorShield_h
#define ColorShield_h

//Output Function ID
#define COLOR_SELECT_SHIELD	0x01
#define COLOR_UNSELECT_SHIELD	0x02
//Input function ID
#define COLOR_VALUE 0x01
#define COLOR_CHECK_SELECTED	0x02

class ColorShield
{

friend class OneSheeldClass;

public:
	//Constructor 
	ColorShield();
	//Getter
	long getColor();
	//Getter
	int getRedComponent();
	//Getter
	int getBlueComponent();
	//Getter	
	int getGreenComponent();
	//setOnChange for Users Function
	void setOnColorChange(void (*)(long));
	//Selection
	void select();
	void unselect();
	//Set on when selected
	void setOnSelected(void(*)(void));

private:
	//Reserve integer variables
	int redComponent;
	int blueComponent;
	int greenComponent;
	//Reserve a long integer variable
	long colorValue;
	//Boolean for setOnChange function
	bool isCallBackAssigned;

	//Process Input data
	void processData();
	void (*changeCallBack)(long);
	void (*selectedCallBack)(void);
	
};
//Extern Object
extern ColorShield Color;
#endif