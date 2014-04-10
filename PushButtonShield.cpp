#include "OneSheeld.h"
#include "PushButtonShield.h"




PushButtonShield::PushButtonShield()
{
	value=0x00;
	isCallBackAssigned=false;
}

byte PushButtonShield::getValue()
{
	return value;
}

void PushButtonShield::processData()
{
	byte functionId =OneSheeld.getFunctionId();
	if(functionId==PUSHBUTTON_VALUE)
	{
		value=OneSheeld.getArgumentData(0)[0];
		if(isCallBackAssigned)
			(*changeCallBack)();
	}
}

void PushButtonShield::setOnChange(void (*userFunction)())
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}


PushButtonShield PushButton;