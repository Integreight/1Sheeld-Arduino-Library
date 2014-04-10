
#include "OneSheeld.h"
#include "KeyboardShield.h"


 KeyboardShield::KeyboardShield()
{
	character=NULL;
	isCallBackAssigned=false;
}


char KeyboardShield::getCharacter()
{
	return character;
}

void KeyboardShield::processData()
{
	/*check the Function ID in the Frame*/
	byte functionId=OneSheeld.getFunctionId();
	if (functionId==GET_CHAR)
	{
		/*Get the Character*/
		character=OneSheeld.getArgumentData(0)[0];

		if(isCallBackAssigned)
		{
			(*buttonChangeCallBack)();
		}
	}
}

void KeyboardShield::setOnButtonChange(void (*userFunction)())
{
	buttonChangeCallBack=userFunction;
	isCallBackAssigned=true;
}

/*instantiate Object to user*/
KeyboardShield AsciiKeyboard;