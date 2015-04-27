/*

  Project:       1Sheeld Library 
  File:          ColorShield.h
                 
  Version:       1.5

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.3

*/
#ifndef ColorShield_h
#define ColorShield_h

#include "ShieldParent.h"

//Output Function ID
#define COLOR_PALETTE_ID			0x01
#define COLOR_FULL_OPERATION_ID		0x02
#define COLOR_NORMAL_OPERATION_ID	0x03
#define COLOR_CALCULATION_MODE_ID	0x04
#define COLOR_SET_PATH_SIZE_ID		0x05
//Input Function ID
#define COLOR_VALUE			0x01
#define ALL_COLORS_VALUE 	0x02

//Literals
#define COLOR_UPPER_LEFT	0
#define COLOR_UPPER_MIDDLE	1
#define COLOR_UPPER_RIGHT	2
#define COLOR_CENTER_LEFT	3
#define COLOR_CENTER_MIDDLE	4
#define COLOR_CENTER_RIGHT	5
#define COLOR_LOWER_LEFT	6
#define COLOR_LOWER_MIDDLE	7
#define COLOR_LOWER_RIGHT	8

#define MOST_DOMINANT_COLOR	0x01
#define AVERAGE_COLOR		0x02

#define SMALL_SIZE			0x01
#define MEDIUM_SIZE			0x02
#define LARGE_SIZE			0x03

#define _1_BIT_GRAYSCALE_PALETTE	1
#define _2_BIT_GRAYSCALE_PALETTE	2
#define _4_BIT_GRAYSCALE_PALETTE	3
#define _8_BIT_GRAYSCALE_PALETTE	4
#define _3_BIT_RGB_PALETTE			5
#define _6_BIT_RGB_PALETTE			6
#define _9_BIT_RGB_PALETTE			7
#define _12_BIT_RGB_PALETTE			8
#define _15_BIT_RGB_PALETTE			9
#define _18_BIT_RGB_PALETTE			10
#define _24_BIT_RGB_PALETTE			11


struct Color{
	unsigned long rgb;
	unsigned long hsb;

	Color(unsigned long);
	Color()
	{
		rgb = 0;
		hsb = 0;
	}

	bool operator==(const Color& other) 
	{
	    return (rgb==other.rgb)||(hsb==other.hsb);
	}

	bool operator!=(const Color& other)
	{
		return !(*this == other);
	}

	bool operator==(const unsigned long other) 
	{
	    return rgb==other;
	}

	bool operator!=(const unsigned long other) 
	{
	    return !(*this == other);
	}

	byte getRed()
	{
		return rgb>>16;
	}

	byte getGreen()
	{
		return rgb>>8;
	}

	byte getBlue()
	{
		return rgb;
	}

	unsigned int getHue()
	{
		return hsb>>16;
	}

	byte getSaturation()
	{
		return hsb>>8;
	}
	
	byte getBrightness()
	{
		return hsb;
	}

};



class ColorShield : public ShieldParent
{
public:
	ColorShield();
	Color getLastColor(byte=COLOR_CENTER_MIDDLE);
	void setOnNewColor(void (*)(Color ));
	void setOnNewColor(void (*)(Color,Color,Color,Color,Color,Color,Color,Color,Color));
	bool isNewColorReceived();
	void setPalette(byte);
	void enableFullOperation();
	void enableNormalOperation();
	void setCalculationMode(byte);
	void setPatchSize(byte);
	bool isFullOperation();
	void finishedReading();
	static unsigned long convertRgbToHsb(unsigned long);
private:
	bool isNewColor;
	bool fullOperation;
	bool colorCallBackInvoked;
	bool colorsCallBackInvoked;
	Color colorInstances[9];
	void (*colorCallBack)(Color);
	void (*colorsCallBack)(Color,Color,Color,Color,Color,Color,Color,Color,Color);
	void processData();
};

extern ColorShield ColorDetector;
#endif