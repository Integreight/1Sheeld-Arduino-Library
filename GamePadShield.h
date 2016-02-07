/*

  Project:       1Sheeld Library
  File:          GamePadShield.h

  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
								 Mostafa Mahmoud

  Date:          2014.5

*/

#ifndef GamePadShield_h
#define GamePadShield_h

#include "ShieldParent.h"
#include <math.h>
//Input Function ID
#define GAMEPAD_KEYS_MODE 0x01
#define GAMEPAD_ANALOG_MODE 0x02

#define PI 3.1415926535897932384626433832795

//GamePad Bit Reference
#define ORANGE_BIT 0
#define RED_BIT 1
#define GREEN_BIT 2
#define BLUE_BIT 3
#define UP_BIT 4
#define DOWN_BIT 5
#define LEFT_BIT 6
#define RIGHT_BIT 7


enum Direction { CENTER, RIGHT, UPPER_RIGHT, UP, UPPER_LEFT, LEFT, LOWER_LEFT, DOWN, LOWER_RIGHT};

class GamePadShield : public ShieldParent
{
public:
	//Constructor
	GamePadShield();
	//getter and checker Functions
	byte getMode();
	bool isUpPressed();
	bool isDownPressed();
	bool isLeftPressed();
	bool isRightPressed();
	bool isOrangePressed();
	bool isRedPressed();
	bool isGreenPressed();
	bool isBluePressed();
  byte getX();
  byte getY();
	byte getPower();
	short getAngle();
	Direction getDirection();

	//setOnChange for Users Function
	void setOnButtonChange(void (*)());

private:
	//Reserve Variables
	byte mode;
	byte keysStatus;
  byte x;
  byte y;
	byte power;
	short angle;
	Direction direction;
	bool isCallBackAssigned;

	//calc angle power and direction functions
	byte calcPower();
	short calcAngle();
	Direction calcDirection();
	//Process Input Data
	void processData();
	//Callback function
	void (*buttonChangeCallBack)();
};

//Extern Object
extern GamePadShield GamePad;
#endif
