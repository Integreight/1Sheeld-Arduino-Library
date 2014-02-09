#include "OneSheeld.h"
#include "ToggleButtonShield.h"



ToggleButtonShield::ToggleButtonShield()
{
	value=0x00;
}

byte ToggleButtonShield::getValue()
{
	return value;
}

void ToggleButtonShield::processData()
{
	value=OneSheeld.getArgumentData(0)[0];
}

ToggleButtonShield ToggleButton;