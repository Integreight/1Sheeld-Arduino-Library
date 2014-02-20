#include "OneSheeld.h"
#include "LedShield.h"

void LedShield::setLow()
{
	setValue(SET_LOW);
}

void LedShield::setHigh()
{
	setValue(SET_HIGH);
}

void LedShield::setValue(byte data)
{
	OneSheeld.sendPacket(LED_ID,0,SET_VALUE,1,new FunctionArg(1,&data));
}


LedShield LED;