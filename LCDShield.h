/*

  Project:       1Sheeld Library 
  File:          LCDShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef LCDShield_h
#define LCDShield_h

//Output Functions ID's  
#define BEGIN 0x01
#define CLEAR 0x02
#define HOME  0x03
#define NOBLINK  0x04
#define BLINK	  0x05
#define NOCURSOR  0x06
#define CURSOR    0x07
#define SCROLLLEFT 0x08
#define SCROLLRIGHT 0x09
#define LEFT_RIGHT  0x0A
#define RIGHT_LEFT  0x0B
#define AUTOSCROLL	0x0C
#define NOAUTOSCROLL 0x0D 
#define SETCURSOR 	 0x0E
#define WRITE 		 0x0F
#define PRINT 		 0x11

class LCDShield
{
public:
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
	//Senders
	void write(byte);
	void print(char*);
private:

};

//Extern Object
extern LCDShield LCD;
#endif