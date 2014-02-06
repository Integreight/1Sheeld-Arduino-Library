#include "OneSheeld.h"
#include "LedShield.h"




LedShield::LedShield()
{}

void LedShield::setLow()
{
	setValue(0x00);
}

void LedShield::setHigh()
{
	setValue(0x01);
}

void LedShield::setValue(byte data)
{
	OneSheeld.sendPacket(LED_ID,0,SET_VALUE,1,new FunctionArg(1,&data));
}


LedShield LED;