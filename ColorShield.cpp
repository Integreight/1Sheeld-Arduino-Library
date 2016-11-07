/*

  Project:       1Sheeld Library 
  File:          ColorShield.cpp
                 
  Version:       1.5

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.3

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "ColorShield.h"



Color::Color(unsigned long _rgb)
{
	rgb = _rgb;
	hsb = ColorShield::convertRgbToHsb(rgb);
}

ColorShield::ColorShield() : ShieldParent(COLOR_ID)
{
	isNewColor = false;
	colorCallBackInvoked =false;
	fullOperation=false;
}

void ColorShield::setPalette(byte range)
{
	OneSheeld.sendShieldFrame(COLOR_ID,0,COLOR_PALETTE_ID,1,new FunctionArg(1,&range));
}

void ColorShield::enableFullOperation()
{
	isNewColor=false;
	OneSheeld.sendShieldFrame(COLOR_ID,0,COLOR_FULL_OPERATION_ID,0);
}

void ColorShield::enableNormalOperation()
{
	isNewColor=false;
	OneSheeld.sendShieldFrame(COLOR_ID,0,COLOR_NORMAL_OPERATION_ID,0);
}

void ColorShield::setCalculationMode(byte mode)
{
	OneSheeld.sendShieldFrame(COLOR_ID,0,COLOR_CALCULATION_MODE_ID,1,new FunctionArg(1,&mode));
}

void ColorShield::setPatchSize(byte mode)
{
	OneSheeld.sendShieldFrame(COLOR_ID,0,COLOR_SET_PATH_SIZE_ID,1,new FunctionArg(1,&mode));
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

unsigned long ColorShield::convertRgbToHsb(unsigned long rgb) {
    double rd = (double)((rgb&0xFF0000)>>16)/255;
    double gd = (double)((rgb&0x00FF00)>>8)/255;
    double bd = (double)((rgb&0x0000FF))/255;
    double maximum = max(rd, max(gd, bd)), minimum = min(rd, min(gd, bd));
    double h = maximum;
    double s = maximum;
    double b = maximum;

    double d = maximum - minimum;
    s = maximum == 0 ? 0 : d / maximum;

    if (maximum == minimum) { 
        h = 0; // achromatic
    } else {
        if (maximum == rd) {
            h = (gd - bd) / d + (gd < bd ? 6 : 0);
        } else if (maximum == gd) {
            h = (bd - rd) / d + 2;
        } else if (maximum == bd) {
            h = (rd - gd) / d + 4;
        }
        h /= 6;
    }
    unsigned int hue=(h=round(h*360))>360?360:h;
    byte saturation=(s=round(s*100))>100?100:s;
    byte brightness=(b=round(b*100))>100?100:b;
    return ((unsigned long)hue<<16)|((unsigned long)saturation<<8)|((unsigned long)brightness);
}

void ColorShield::processData()
{
	byte functionId = getOneSheeldInstance().getFunctionId();

	if(functionId == COLOR_VALUE)
	{
		isNewColor = true;
		fullOperation=false;

		colorInstances[COLOR_CENTER_MIDDLE] = Color((unsigned long )(((unsigned long)getOneSheeldInstance().getArgumentData(0)[0])|
											 ((unsigned long)getOneSheeldInstance().getArgumentData(0)[1])<<8|
											 ((unsigned long)getOneSheeldInstance().getArgumentData(0)[2])<<16));
		
		if(colorCallBackInvoked && !isInACallback())
		{
			enteringACallback();
			(*colorCallBack)(colorInstances[COLOR_CENTER_MIDDLE]);
			exitingACallback();
		}
	}
	else if(functionId == ALL_COLORS_VALUE && getOneSheeldInstance().getArgumentNo()==9)
	{
		isNewColor = true;
		fullOperation = true;

		for(int i=0;i < 9;i++)
		{
			colorInstances[i]= Color((unsigned long )(((unsigned long)getOneSheeldInstance().getArgumentData(i)[0])|
											 ((unsigned long)getOneSheeldInstance().getArgumentData(i)[1])<<8|
											 ((unsigned long)getOneSheeldInstance().getArgumentData(i)[2])<<16));
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
