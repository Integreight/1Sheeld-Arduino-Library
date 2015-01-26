/*

  Project:       1Sheeld Library 
  File:          LCDShield.h
                 
  Version:       1.2

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef LCDShield_h
#define LCDShield_h

#include "ShieldParent.h"
#include "OneSheeldPrint.h"

//Output Functions ID's
#define LCD_BEGIN		 0x01  
#define LCD_CLEAR 		 0x02
#define LCD_HOME  		 0x03
#define LCD_NOBLINK  	 0x04
#define LCD_BLINK	  	 0x05
#define LCD_NOCURSOR  	 0x06
#define LCD_CURSOR    	 0x07
#define LCD_SCROLLLEFT 	 0x08
#define LCD_SCROLLRIGHT  0x09
#define LCD_LEFT_RIGHT   0x0A
#define LCD_RIGHT_LEFT   0x0B
#define LCD_AUTOSCROLL	 0x0C
#define LCD_NOAUTOSCROLL 0x0D 
#define LCD_SETCURSOR 	 0x0E
#define LCD_WRITE 		 0x0F
#define LCD_PRINT 		 0x11


class LCDShield : public PrintClass , public ShieldParent
{
public:
	LCDShield();
	//Setters 
	void begin();
	void clear();
	void home();
	void noBlink();
	void blink();
	void noCursor();
	void cursor();
	void scrollDisplayLeft();
	void scrollDisplayRight();
	void leftToRight();
	void rightToLeft();
	void autoScroll();
	void noAutoScroll();
	void setCursor(byte,byte);

private:

};

//Extern Object
extern LCDShield LCD;
#endif