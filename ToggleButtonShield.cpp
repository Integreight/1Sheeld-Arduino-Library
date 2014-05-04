#include "OneSheeld.h"
#include "ToggleButtonShield.h"



ToggleButtonShield::ToggleButtonShield()
{
	value=0x00;
	isCallBackAssigned=false;
}

byte ToggleButtonShield::getValue()
{
	return value;
}

void ToggleButtonShield::processData()
{
	byte functionId= OneSheeld.getFunctionId();
	if(functionId==TOGGLE_VALUE)
	{
		value=OneSheeld.getArgumentData(0)[0];
		if(isCallBackAssigned)
			(*changeCallBack)(value);
	}
}
void ToggleButtonShield::setOnChange(void (*userFunction)(byte toggleButtonValue))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

ToggleButtonShield ToggleButton;