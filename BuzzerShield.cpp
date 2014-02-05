#include "OneSheeld.h"
#include "BuzzerShield.h"




BuzzerShieldClass::BuzzerShieldClass()
{}

void BuzzerShieldClass::buzzOn()
{
	OneSheeld.sendPacket(BUZZER_ID,0,BUZZ_ON,0);
}

void BuzzerShieldClass::buzzOff()
{
	OneSheeld.sendPacket(BUZZER_ID,0,BUZZ_OFF,0);
}

void BuzzerShieldClass::setValue(byte x)
{
	OneSheeld.sendPacket(BUZZER_ID,0,SET_VALUE,1,new FunctionArg(1,&x));
}


BuzzerShieldClass Buzzer;