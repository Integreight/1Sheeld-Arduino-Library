#include "OneSheeld.h"
#include "SliderShield.h"
#include "HardwareSerial.h"



SliderShield::SliderShield()
{
	value=0x00;
}
byte SliderShield::getValue()
{
	return value;
}


void SliderShield::processData()
{
	value= OneSheeld.getArgumentData(0)[0];
}

SliderShield Slider;