#include "OneSheeld.h"
#include "GamePadShield.h"




GamePadShield::GamePadShield()
{
	value =0x00;
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

bool GamePadShield::isAPressed()
{
	
	return !!(value & (1<<A_BIT));
}

bool GamePadShield::isBPressed()
{
	
	return !!(value & (1<<B_BIT));
}

bool GamePadShield::isCPressed()
{
	
	return !!(value & (1<<C_BIT));
}

bool GamePadShield::isDPressed()
{
	
	return !!(value & (1<<D_BIT));
}

void GamePadShield::processData()
{
	byte functionId =OneSheeld.getFunctionId();
	if(functionId==GAMEPAD_VALUE)
	{
		value=OneSheeld.getArgumentData(0)[0];
	}
}

GamePadShield GamePad;