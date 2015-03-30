#ifndef ColorShield_h
#define ColorShield_h

//Output Function ID
#define COLOR_RANGE_ID	0x01
//Input Function ID
#define COLOR_VALUE	0x01

#include "ShieldParent.h"


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
	 int getHue()
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
	Color & getLastColor();
	void setOnNewColor(void (*)(Color ));
	bool isNewColorReceived();
	void setPalette(byte);
private:
	bool isNewColor;
	bool colorCallBackInvoked;
	Color colorInstance;
	void (*colorCallBack)(Color);
	void processData();
};

extern ColorShield ColorDetector;
#endif