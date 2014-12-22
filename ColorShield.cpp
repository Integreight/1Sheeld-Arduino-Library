/*

  Project:       1Sheeld Library 
  File:          ColorShield.cpp
                 
  Version:       1.3

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "OneSheeld.h"
#include "ColorShield.h"


//Constructor
ColorShield::ColorShield()
{
	redComponent=-1;
	blueComponent=-1;
	greenComponent=-1;
	colorValue=-1;
	isCallBackAssigned=false;
}

//Get color value
long ColorShield::getColor()
{
	
	if(redComponent==-1 || blueComponent==-1 || greenComponent==-1)
	{
		return colorValue;
	}
	colorValue =((long)redComponent<<16)|((long)greenComponent<<8)|((long)blueComponent);

	return colorValue;
}

//Get red component value
int ColorShield::getRedComponent()
{
	return redComponent;
}

//Get blue component value
int ColorShield::getBlueComponent()
{
	return blueComponent;
}

//Get green component value
int ColorShield::getGreenComponent()
{
	return greenComponent;
}

void ColorShield::select()
{
	OneSheeld.sendPacket(COLOR_ID,0,COLOR_SELECT_SHIELD,0);
}

void ColorShield::unselect()
{
	OneSheeld.sendPacket(COLOR_ID,0,COLOR_UNSELECT_SHIELD,0);
}

//Color input data processing
void ColorShield::processData()
{
	byte functionId = OneSheeld.getFunctionId();
	//Check  the function ID 
	if(functionId == COLOR_VALUE)
	{
		redComponent  = OneSheeld.getArgumentData(0)[0];

		greenComponent = OneSheeld.getArgumentData(1)[0];

		blueComponent = OneSheeld.getArgumentData(2)[0];

		//User Function Invoked
			if(isCallBackAssigned)
			{
				(*changeCallBack)(colorValue);
			}
	}
	else if(functionId == COLOR_CHECK_SELECTED)
	{
		(*selectedCallBack)();
	} 
}

//Users Function Setter 
void ColorShield::setOnColorChange(void (* usersFunction)(long colorValue))	
{
	changeCallBack=usersFunction;
	isCallBackAssigned=true;
}

void ColorShield::setOnSelected(void (* usersFunction)(void))	
{
	selectedCallBack=usersFunction;
}
//Instantiate Object
ColorShield Color;