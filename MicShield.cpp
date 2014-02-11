#include "OneSheeld.h"
#include "MicShield.h"




MicShield::MicShield()
{
	value=0x00;
	callBack=false;
}

byte MicShield::getValue()
{
	return value;
}

void MicShield::processData()
{
	value=OneSheeld.getArgumentData(0)[0];
	if(callBack)
		(*changeCallBack)(value);
}

void MicShield::setOnChange(void (*userFunction)(byte))
{
	changeCallBack=userFunction;
	callBack=true;
}

MicShield Mic;