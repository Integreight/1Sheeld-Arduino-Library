#include "OneSheeld.h"
#include "GamePadShield.h"




GamePadShield::GamePadShield()
{
	value1 =0x00;
}
	//Single Button Pressed 
bool GamePadShield::isUpPressed()
{
	
	return (value1 & (1<<UP));
	
}

bool GamePadShield::isDownPressed()
{
	
	return (value1 & (1<<DOWN));
}

bool GamePadShield::isLeftPressed()
{
	
	return (value1 & (1<<LEFT));
}

bool GamePadShield::isRightPressed()
{
	
	return (value1 & (1<<RIGHT));
}

bool GamePadShield::isAPressed()
{
	
	return (value1 & (1<<A));
}

bool GamePadShield::isBPressed()
{
	
	return (value1 & (1<<B));
}

bool GamePadShield::isCPressed()
{
	
	return (value1 & (1<<C));
}

bool GamePadShield::isDPressed()
{
	
	return (value1 & (1<<D));
}

void GamePadShield::processData()
{
	value1=OneSheeld.getArgumentData(0)[0];
}

GamePadShield GamePad;