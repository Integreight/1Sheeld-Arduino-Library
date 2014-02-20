#include "OneSheeld.h"
#include "FlashLightShield.h"



void FlashLightShield::setLow()
{
	setValue(SET_LOW);
}

void FlashLightShield::setHigh()
{
	setValue(SET_HIGH);
}

void FlashLightShield::setValue(byte x)
{
	OneSheeld.sendPacket(FLASH_ID,0,SET_VALUE,1,new FunctionArg(1,&x));
}

FlashLightShield FlashLight;