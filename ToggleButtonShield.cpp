#include "OneSheeld.h"
#include "ToggleButtonShield.h"



ToggleButtonShield::ToggleButtonShield()
{
	value=0x00;
	callBack=false;
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
		if(callBack)
			(*changeCallBack)(value);
	}
}
void ToggleButtonShield::setOnChange(void (*userFunction)(byte))
{
	changeCallBack=userFunction;
	callBack=true;
}

ToggleButtonShield ToggleButton;