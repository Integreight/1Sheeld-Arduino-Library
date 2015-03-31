#ifndef ColorShield_h
#define ColorShield_h

#include "ShieldParent.h"

//Output Function ID
#define COLOR_PALETTE_ID			0x01
#define COLOR_CALCULATION_MODE_ID	0x02
#define COLOR_FULL_OPERATION_ID		0x03
//Input Function ID
#define COLOR_VALUE			0x01
#define ALL_COLORS_VALUE 	0x02

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

	byte getRed()
	{
		return rgb;
	}

	byte getGreen()
	{
		return rgb>>8;
	}

	byte getBlue()
	{
		return rgb>>16;
	}

	unsigned int getHue()
	{
		return hsb;
	}

	byte getSaturation()
	{
		return hsb>>16;
	}
	
	byte getBrightness()
	{
		return hsb>>24;
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
	void setCalculationMode(byte);
	void enableFullOperation();
	void enableNormalOperation();
	bool isFullOperation();
	void finishedReading();
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