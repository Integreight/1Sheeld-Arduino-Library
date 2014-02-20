#include "OneSheeld.h"
#include "GamePadShield.h"




GamePadShield::GamePadShield()
{
	value =0x00;
}
	//Single Button Pressed 
bool GamePadShield::isUpPressed()
{
	
	return !!(value & (1<<UP));
	
}

bool GamePadShield::isDownPressed()
{
	
	return !!(value & (1<<DOWN));
}

bool GamePadShield::isLeftPressed()
{
	
	return !!(value & (1<<LEFT));
}

bool GamePadShield::isRightPressed()
{
	
	return !!(value & (1<<RIGHT));
}

bool GamePadShield::isAPressed()
{
	
	return !!(value & (1<<A));
}

bool GamePadShield::isBPressed()
{
	
	return !!(value & (1<<B));
}

bool GamePadShield::isCPressed()
{
	
	return !!(value & (1<<C));
}

bool GamePadShield::isDPressed()
{
	
	return !!(value & (1<<D));
}

void GamePadShield::processData()
{
	value=OneSheeld.getArgumentData(0)[0];
}

GamePadShield GamePad;