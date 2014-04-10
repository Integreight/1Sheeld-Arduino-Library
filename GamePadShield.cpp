#include "OneSheeld.h"
#include "GamePadShield.h"




GamePadShield::GamePadShield()
{
	value =0x00;
	isCallBackAssigned=false;
}
	//Single Button Pressed 
bool GamePadShield::isUpPressed()
{
	
	return !!(value & (1<<UP_BIT));
	
}

bool GamePadShield::isDownPressed()
{
	
	return !!(value & (1<<DOWN_BIT));
}

bool GamePadShield::isLeftPressed()
{
	
	return !!(value & (1<<LEFT_BIT));
}

bool GamePadShield::isRightPressed()
{
	
	return !!(value & (1<<RIGHT_BIT));
}

bool GamePadShield::isOrangePressed()
{
	
	return !!(value & (1<<ORANGE_BIT));
}

bool GamePadShield::isRedPressed()
{
	
	return !!(value & (1<<RED_BIT));
}

bool GamePadShield::isGreenPressed()
{
	
	return !!(value & (1<<GREEN_BIT));
}

bool GamePadShield::isBluePressed()
{
	
	return !!(value & (1<<BLUE_BIT));
}

void GamePadShield::processData()
{
	byte functionId =OneSheeld.getFunctionId();
	if(functionId==GAMEPAD_VALUE)
	{
		value=OneSheeld.getArgumentData(0)[0];

		if(isCallBackAssigned)
		{
			(*buttonChangeCallBack)();
		}
	}
}

void GamePadShield::setOnButtonChange(void (* userFunction)())
{
	buttonChangeCallBack=userFunction;
	isCallBackAssigned=true;
}
GamePadShield GamePad;