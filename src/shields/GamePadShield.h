/*

  Project:       1Sheeld Library 
  File:          GamePadShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef GamePadShield_h
#define GamePadShield_h

#include "ShieldParent.h"

//Input Function ID
#define GAMEPAD_VALUE 0x01

//GamePad Bit Reference 
#define ORANGE_BIT 0
#define RED_BIT 1
#define GREEN_BIT 2 
#define BLUE_BIT 3 
#define UP_BIT 4
#define DOWN_BIT 5
#define LEFT_BIT 6
#define RIGHT_BIT 7



class GamePadShield : public ShieldParent
{
public:
	//Constructor
	GamePadShield();
	//Checker Functions
	bool isUpPressed();
	bool isDownPressed();
	bool isLeftPressed();
	bool isRightPressed();
	bool isOrangePressed();
	bool isRedPressed();
	bool isGreenPressed();
	bool isBluePressed();
	
	//setOnChange for Users Function
	void setOnButtonChange(void (*)(unsigned char , unsigned char ,
									unsigned char , unsigned char ,
									unsigned char , unsigned char ,
									unsigned char , unsigned char ));
private:
	//Reserve Variables
	byte value;
	bool isCallBackAssigned;
	//Process Input Data  
	void processData();
	void (*buttonChangeCallBack)(unsigned char , unsigned char ,
								 unsigned char , unsigned char ,
								 unsigned char ,unsigned char  ,
								 unsigned char ,unsigned char );
};

//Extern Object
extern GamePadShield GamePad;
#endif 