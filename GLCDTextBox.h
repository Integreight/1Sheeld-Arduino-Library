/*

  Project:       1Sheeld Library 
  File:          GLCDTextBox.h
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/

#ifndef GLCDTextBox_h
#define GLCDTextBox_h

#define GLCD_TEXTBOX_TYPE			0x05
#define GLCD_TEXTBOX_SET_FONT		0x03
#define GLCD_TEXTBOX_SET_SIZE		0x04

/* Fonts Literals. */
#define ARIAL			0x00
#define ARIAL_BOLD		0x01
#define ARIAL_ITALIC	0x02
#define COMIC_SANS		0x03
#define SREIF			0x04
/* Size Literals. */
#define SMALL			0x00
#define MEDIUM			0x01
#define LARGE			0x02
#define XLARGE			0x03

#include "ShapeClass.h"

class GLCDTextBox : public ShapeClass
{
public:
	GLCDTextBox(int , int ,char * );
	void setFont(byte );
	void setSize(byte );
private:
	void draw();
	char * dataString;
};

#endif