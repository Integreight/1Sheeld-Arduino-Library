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
	up = !!(value & (1<<UP_BIT));
	return up ;
}

bool GamePadShield::isDownPressed()
{
	down = !!(value & (1<<DOWN_BIT));
	return down ;
}

bool GamePadShield::isLeftPressed()
{
	left = !!(value & (1<<LEFT_BIT));
	return left ;
}

bool GamePadShield::isRightPressed()
{
	right = !!(value & (1<<RIGHT_BIT));
	return right ;
}

bool GamePadShield::isOrangePressed()
{
	orange = !!(value & (1<<ORANGE_BIT));
	return orange ;
}

bool GamePadShield::isRedPressed()
{
	red = !!(value & (1<<RED_BIT));
	return red ;
}

bool GamePadShield::isGreenPressed()
{
	green = !!(value & (1<<GREEN_BIT));
	return green ;
}

bool GamePadShield::isBluePressed()
{
	blue = !!(value & (1<<BLUE_BIT));
	return blue ;
}

void GamePadShield::processData()
{
	byte functionId =OneSheeld.getFunctionId();
	if(functionId==GAMEPAD_VALUE)
	{
		value=OneSheeld.getArgumentData(0)[0];

		if(isCallBackAssigned)
		{
			(*buttonChangeCallBack)(up , down , left , right , orange , red , green , blue);
		}
	}
}

void GamePadShield::setOnButtonChange(void (* userFunction)(unsigned char up,unsigned char down,unsigned char left,unsigned char right,unsigned char orange ,unsigned char red,unsigned char green,unsigned char blue))
{
	buttonChangeCallBack=userFunction;
	isCallBackAssigned=true;
}
GamePadShield GamePad;