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

//Input function ID
#define COLOR_VALUE 0x01

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

private:
	//Reserve integer variables
	int redComponent;
	int blueComponent;
	int greenComponent;
	//Process Input data
	void processData();
	void (*changeCallBack)(long);
	
};
//Extern Object
extern ColorShield Color;
#endif