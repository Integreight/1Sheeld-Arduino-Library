#include "OneSheeld.h"
#include "ProximityShield.h"





ProximityShield::ProximityShield()
{
	value=0x00;
	callBack=false;
}

byte ProximityShield::getProx()
{
	return value;
}

void ProximityShield::processData()
{
	value=OneSheeld.getArgumentData(0)[0];
	if (callBack)
	(*changeCallBack)(value);
}

void ProximityShield::setOnChange(void (*userFunction)(byte))
{
	changeCallBack=userFunction;
	callBack=true;
}
ProximityShield Prox;