/*

  Project:       1Sheeld Library 
  File:          GLCDAnalogGauge.h
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/

#ifndef GLCDAnalogGauge_h
#define GLCDAnalogGauge_h

#define GLCD_ANALOG_GAUGE_TYPE			0x07
#define GLCD_ANALOG_GAUGE_RANGE			0x03
#define GLCD_ANALOG_GAUGE_VALUE			0x04
#define GLCD_ANALOG_GAUGE_RADIUS		0x05

#include "ShapeClass.h"

class GLCDAnalogGauge : public ShapeClass
{
public:
	GLCDAnalogGauge(int , int , int );
	void setRange(int , int);
	void setValue(int );
	void setRadius(int);
private:
	void draw();
	int radius;  
};

#endif