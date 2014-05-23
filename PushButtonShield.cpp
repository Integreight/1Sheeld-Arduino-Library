#include "OneSheeld.h"
#include "PushButtonShield.h"




PushButtonShield::PushButtonShield()
{
	value=0x00;
	isCallBackAssigned=false;
}

bool PushButtonShield::isPressed()
{
	return !!value;
}

void PushButtonShield::processData()
{
	byte functionId =OneSheeld.getFunctionId();
	if(functionId==PUSHBUTTON_VALUE)
	{
		value=OneSheeld.getArgumentData(0)[0];
		if(isCallBackAssigned)
			(*changeCallBack)(!!value);
	}
}

void PushButtonShield::setOnButtonStatusChange(void (*userFunction)(bool pushButtonValue))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}


PushButtonShield PushButton;