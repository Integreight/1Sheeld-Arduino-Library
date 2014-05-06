#include "OneSheeld.h"
#include "BuzzerShield.h"


BuzzerShieldClass::BuzzerShieldClass()
{
	buzzing = false;
}

void BuzzerShieldClass::buzzOn()
{
	if(buzzing == false)
	{
		setValue(BUZZ_ON);
		buzzing=true;
	}
	
}

void BuzzerShieldClass::buzzOff()
{
	if(buzzing == true)
	{
		setValue(BUZZ_OFF);
		buzzing=false;
	}
	
}

void BuzzerShieldClass::setValue(byte x)
{
	OneSheeld.sendPacket(BUZZER_ID,0,SET_VALUE,1,new FunctionArg(1,&x));
}


BuzzerShieldClass Buzzer;