#include "OneSheeld.h"
#include "ColorShield.h"





ColorShield::ColorShield() : ShieldParent(COLOR_ID)
{
	isNewColor = false;
	colorCallBackInvoked =false;
}

void ColorShield::setPalette(byte range)
{
	OneSheeld.sendPacket(COLOR_ID,0,COLOR_RANGE_ID,1,new FunctionArg(1,&range));
}

Color & ColorShield::getLastColor()
{
	isNewColor =false;
	return colorInstance;
}

bool ColorShield::isNewColorReceived()
{
	return isNewColor;
}

void ColorShield::setOnNewColor(void (*userFunction)(Color))
{
	colorCallBack = userFunction;
	colorCallBackInvoked = true;
}

void ColorShield::processData()
{
	byte functionId = getOneSheeldInstance().getFunctionId();

	if(functionId == COLOR_VALUE)
	{
		isNewColor = true;

		colorInstance.rgb = (unsigned long )(((unsigned long)getOneSheeldInstance().getArgumentData(0)[0])|
											 ((unsigned long)getOneSheeldInstance().getArgumentData(0)[1])<<8|
											 ((unsigned long)getOneSheeldInstance().getArgumentData(0)[2])<<16);

		colorInstance.hsb = (unsigned long)(((unsigned long)getOneSheeldInstance().getArgumentData(1)[3]<<24)|
											((unsigned long)getOneSheeldInstance().getArgumentData(1)[2]<<16)|
											((unsigned long)getOneSheeldInstance().getArgumentData(1)[1]<<8)|
											 (unsigned long)getOneSheeldInstance().getArgumentData(1)[0]);
		
		if(colorCallBackInvoked)
		{
			(*colorCallBack)(colorInstance);
		}
	}
}
#ifdef COLOR_SHIELD
//Instantiating object 
ColorShield ColorDetector;
#endif