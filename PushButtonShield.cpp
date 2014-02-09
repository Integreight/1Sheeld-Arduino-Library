#include "OneSheeld.h"
#include "PushButtonShield.h"




PushButtonShield::PushButtonShield()
{
	value=0x00;
}

byte PushButtonShield::getValue()
{
	return value;
}

void PushButtonShield::processData()
{
	value=OneSheeld.getArgumentData(0)[0];
}


PushButtonShield PushButton;