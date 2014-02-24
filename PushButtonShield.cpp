#include "OneSheeld.h"
#include "PushButtonShield.h"




PushButtonShield::PushButtonShield()
{
	value=0x00;
	callBack=false;
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
		if(callBack)
			(*changeCallBack)(value);
	}
}

void PushButtonShield::setOnChange(void (*userFunction)(byte))
{
	changeCallBack=userFunction;
	callBack=true;
}


PushButtonShield PushButton;