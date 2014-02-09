#include "OneSheeld.h"
#include "BuzzerShield.h"




BuzzerShieldClass::BuzzerShieldClass()
{}

void BuzzerShieldClass::buzzOn()
{
	setValue(BUZZ_ON);
}

void BuzzerShieldClass::buzzOff()
{
	setValue(BUZZ_OFF);
}

void BuzzerShieldClass::setValue(byte x)
{
	OneSheeld.sendPacket(BUZZER_ID,0,SET_VALUE,1,new FunctionArg(1,&x));
}


BuzzerShieldClass Buzzer;