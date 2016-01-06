/*

  Project:      1Sheeld Library
  File:         GamePadShield.cpp

  Version:      1.0

  Compiler:     Arduino avr-gcc 4.3.2

  Author:       Integreight
                Mostafa Mahmoud
                
  Date:         2014.5

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "GamePadShield.h"

//Class Constructor
GamePadShield::GamePadShield() : ShieldParent(GAMEPAD_ID)
{
  mode = GAMEPAD_KEYS_MODE;
	keysStatus =0;
  x = 127;
  y = 127;
  power = 0;
  angle = 0;
  direction = CENTER;
	isCallBackAssigned=false;
}
// get gamepad current mode
byte GamePadShield::getMode(){
  return mode;
}
//Up ArrowChecker
bool GamePadShield::isUpPressed()
{
	return !!(keysStatus & (1<<UP_BIT));
}
//Down Arrow Checker
bool GamePadShield::isDownPressed()
{
	return !!(keysStatus & (1<<DOWN_BIT));
}
//Left Arrow Checker
bool GamePadShield::isLeftPressed()
{
	return  !!(keysStatus & (1<<LEFT_BIT));
}
//Right Arrow Checker
bool GamePadShield::isRightPressed()
{
	return !!(keysStatus & (1<<RIGHT_BIT));
}
//Orange Button Checker
bool GamePadShield::isOrangePressed()
{
	return !!(keysStatus & (1<<ORANGE_BIT));
}
//Red Button Checker
bool GamePadShield::isRedPressed()
{
	return !!(keysStatus & (1<<RED_BIT));
}
//Green Button Checker
bool GamePadShield::isGreenPressed()
{
	return !!(keysStatus & (1<<GREEN_BIT));
}
//Blue Button Checker
bool GamePadShield::isBluePressed()
{
	return !!(keysStatus & (1<<BLUE_BIT));
}
//Analog Stick X Coordinate
byte GamePadShield::getX(){
  return x;
}
//Analog Stick Y Coordinate
byte GamePadShield::getY(){
  return y;
}
//Analog Stick power
byte GamePadShield::getPower(){
  return power;
}
//Analog Stick angle
short GamePadShield::getAngle(){
  return angle;
}
//Analog Stick direction
Direction GamePadShield::getDirection(){
  return direction;
}

//GamePad Input Data Processing
void GamePadShield::processData()
{
	//Checking Function-ID
	byte functionId =getOneSheeldInstance().getFunctionId();
	if(functionId==GAMEPAD_KEYS_MODE)
	{
    mode = GAMEPAD_KEYS_MODE;
		keysStatus=getOneSheeldInstance().getArgumentData(0)[0];
    x = 127;
    y = 127;
    angle = 0;
    power = 0;
    direction = CENTER;
		//Users Function Invoked
		if(isCallBackAssigned && !isInACallback())
		{
			enteringACallback();
			(*buttonChangeCallBack)();
			exitingACallback();
		}
	}
  else if (functionId== GAMEPAD_ANALOG_MODE) {
    mode = GAMEPAD_ANALOG_MODE;
		keysStatus=getOneSheeldInstance().getArgumentData(0)[0];
    x = getOneSheeldInstance().getArgumentData(1)[0];
    y = getOneSheeldInstance().getArgumentData(2)[0];
    calcPower();
    calcAngle();
    clacDirection();
    //Users Function Invoked
    if(isCallBackAssigned && !isInACallback())
		{
			enteringACallback();
			(*buttonChangeCallBack)();
			exitingACallback();
		}
  }
}

byte GamePadShield::calcPower(){
  power = (byte)(100 * sqrt((x - 127)
                * (x - 127) + (y - 127)
                * (y - 127)) / 127);
  return power;
}

short GamePadShield::calcAngle(){
  angle = (short)(atan2(y - 127,x - 127) * 180 / PI);

  if(angle < 0)
    angle += 360;

  if (angle != 0)
    angle = 360 - angle;

  return angle;
}

Direction GamePadShield::clacDirection(){
  if (power == 0)
    direction = CENTER;
  else if (angle > 338 || angle <= 22)
    direction = RIGHT;
  else if (angle > 22 && angle <= 68)
    direction = UPPER_RIGHT;
  else if (angle > 68 && angle <= 112)
    direction = UP;
  else if (angle > 112 && angle <= 158)
      direction = UPPER_LEFT;
  else if (angle > 158 && angle <= 202)
      direction = LEFT;
  else if (angle > 202 && angle <= 248)
      direction = LOWER_LEFT;
  else if (angle > 248 && angle <= 292)
      direction = DOWN;
  else if (angle > 292 && angle <= 338)
      direction = LOWER_RIGHT;
  return direction;
}

//Users Function Setter
void GamePadShield::setOnButtonChange(void (* userFunction)())
{
	buttonChangeCallBack=userFunction;
	isCallBackAssigned=true;
}
