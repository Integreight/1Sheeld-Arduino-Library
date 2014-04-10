#include "OneSheeld.h"
#include "MicShield.h"




MicShield::MicShield()
{
	value=0x00;
	isCallBackAssigned=false;
}

byte MicShield::getValue()
{
	return value;
}

void MicShield::processData()
{
	byte functionId =OneSheeld.getFunctionId();
	if(functionId==MIC_VALUE)
	{
		value=0;
		value=OneSheeld.getArgumentData(0)[0];
		if(isCallBackAssigned)
			(*changeCallBack)();
	}
}

void MicShield::setOnChange(void (*userFunction)())
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

MicShield Mic;