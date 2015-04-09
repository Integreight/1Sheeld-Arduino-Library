/*

  Project:       1Sheeld Library 
  File:          ColorShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.3

*/
#include "OneSheeld.h"
#include "ColorShield.h"





ColorShield::ColorShield() : ShieldParent(COLOR_ID)
{
	isNewColor = false;
	colorCallBackInvoked =false;
	fullOperation=false;
}

void ColorShield::setPalette(byte range)
{
	OneSheeld.sendPacket(COLOR_ID,0,COLOR_PALETTE_ID,1,new FunctionArg(1,&range));
}

void ColorShield::setCalculationMode(byte mode)
{
	OneSheeld.sendPacket(COLOR_ID,0,COLOR_CALCULATION_MODE_ID,1,new FunctionArg(1,&mode));
}

void ColorShield::enableFullOperation()
{
	isNewColor=false;
	byte fullMode = 1;
	OneSheeld.sendPacket(COLOR_ID,0,COLOR_FULL_OPERATION_ID,1,new FunctionArg(1,&fullMode));
}

void ColorShield::enableNormalOperation()
{
	isNewColor=false;
	byte normalMode = 0;
	OneSheeld.sendPacket(COLOR_ID,0,COLOR_NORMAL_OPERATION_ID,1,new FunctionArg(1,&normalMode));
}

Color ColorShield::getLastColor(byte whichColor)
{
	if(whichColor>=9||!fullOperation)
	{
		whichColor=COLOR_CENTER_MIDDLE;
		isNewColor =false;
	}
	return colorInstances[whichColor];
}

bool ColorShield::isNewColorReceived()
{
	return isNewColor;
}

bool ColorShield::isFullOperation()
{
	return fullOperation;
}

void ColorShield::finishedReading()
{
	isNewColor=false;
}

void ColorShield::setOnNewColor(void (*userFunction)(Color))
{
	colorCallBack = userFunction;
	colorCallBackInvoked = true;
}


void ColorShield::setOnNewColor(void (*userFunction)(Color,Color,Color,Color,Color,Color,Color,Color,Color))
{
	colorsCallBack = userFunction;
	colorsCallBackInvoked = true;
}

void ColorShield::processData()
{
	byte functionId = getOneSheeldInstance().getFunctionId();

	if(functionId == COLOR_VALUE)
	{
		isNewColor = true;
		fullOperation=false;

		colorInstances[COLOR_CENTER_MIDDLE].rgb = (unsigned long )(((unsigned long)getOneSheeldInstance().getArgumentData(0)[0])|
											 ((unsigned long)getOneSheeldInstance().getArgumentData(0)[1])<<8|
											 ((unsigned long)getOneSheeldInstance().getArgumentData(0)[2])<<16);

		colorInstances[COLOR_CENTER_MIDDLE].hsb = (unsigned long)(((unsigned long)getOneSheeldInstance().getArgumentData(1)[3]<<24)|
											((unsigned long)getOneSheeldInstance().getArgumentData(1)[2]<<16)|
											((unsigned long)getOneSheeldInstance().getArgumentData(1)[1]<<8)|
											 (unsigned long)getOneSheeldInstance().getArgumentData(1)[0]);
		
		if(colorCallBackInvoked && !isInACallback())
		{
			enteringACallback();
			(*colorCallBack)(colorInstances[COLOR_CENTER_MIDDLE]);
			exitingACallback();
		}
	}
	else if(functionId == ALL_COLORS_VALUE && getOneSheeldInstance().getArgumentNo()==18)
	{
		isNewColor = true;
		fullOperation = true;

		for(int i=0;i < 9;i++)
		{
			colorInstances[i].rgb = (unsigned long )(((unsigned long)getOneSheeldInstance().getArgumentData(i*2)[0])|
											 ((unsigned long)getOneSheeldInstance().getArgumentData(i*2)[1])<<8|
											 ((unsigned long)getOneSheeldInstance().getArgumentData(i*2)[2])<<16);

			colorInstances[i].hsb = (unsigned long)(((unsigned long)getOneSheeldInstance().getArgumentData((i*2)+1)[3]<<24)|
												((unsigned long)getOneSheeldInstance().getArgumentData((i*2)+1)[2]<<16)|
												((unsigned long)getOneSheeldInstance().getArgumentData((i*2)+1)[1]<<8)|
												 (unsigned long)getOneSheeldInstance().getArgumentData((i*2)+1)[0]);
		}

		
		if(colorsCallBackInvoked && !isInACallback())
		{	
			enteringACallback();
			(*colorsCallBack)(colorInstances[COLOR_UPPER_LEFT],colorInstances[COLOR_UPPER_MIDDLE],colorInstances[COLOR_UPPER_RIGHT],
				colorInstances[COLOR_CENTER_LEFT],colorInstances[COLOR_CENTER_MIDDLE],colorInstances[COLOR_CENTER_RIGHT],
				colorInstances[COLOR_LOWER_LEFT],colorInstances[COLOR_LOWER_MIDDLE],colorInstances[COLOR_LOWER_RIGHT]);
			exitingACallback();
		}
	}
}
#ifdef COLOR_SHIELD
//Instantiating object 
ColorShield ColorDetector;
#endif