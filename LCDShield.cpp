/*

  Project:       1Sheeld Library 
  File:          LCDShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "OneSheeld.h"
#include "LCDShield.h"

//Setter
void LCDShield::begin()
{ 
	clear();
	noAutoScroll();
	setCursor(0,0);
	noCursor();
	noBlink();
}
//Clear Setter
void LCDShield::clear()
{
	OneSheeld.sendPacket(LCD_ID,0,CLEAR,0);
}
//Home Setter
void LCDShield::home()
{
	OneSheeld.sendPacket(LCD_ID,0,HOME,0);
}
//NoBlink Setter
void LCDShield::noBlink()
{
	OneSheeld.sendPacket(LCD_ID,0,NOBLINK,0);
}
//Blink Setter
void LCDShield::blink()
{
	OneSheeld.sendPacket(LCD_ID,0,BLINK,0);
}
//NoCursor Setter
void LCDShield::noCursor()
{
	OneSheeld.sendPacket(LCD_ID,0,NOCURSOR,0);
}
//Display Cursor Setter
void LCDShield::cursor()
{
	OneSheeld.sendPacket(LCD_ID,0,CURSOR,0);
}
//Scrolling Setter
void LCDShield::scrollDisplayLeft()
{
	OneSheeld.sendPacket(LCD_ID,0,SCROLLLEFT,0);
}
//Scrolling Setter
void LCDShield::scrollDisplayRight()
{
	OneSheeld.sendPacket(LCD_ID,0,SCROLLRIGHT,0);
}
//left-Right Setter
void LCDShield::leftToRight()
{
	OneSheeld.sendPacket(LCD_ID,0,LEFT_RIGHT,0);
}
//Right-left Setter
void LCDShield::rightToLeft()
{
	OneSheeld.sendPacket(LCD_ID,0,RIGHT_LEFT,0);
}
//AutoScroll Setter
void LCDShield::autoScroll()
{
	OneSheeld.sendPacket(LCD_ID,0,AUTOSCROLL,0);
}
//NoAutoScroll Setter
void LCDShield::noAutoScroll()
{
	OneSheeld.sendPacket(LCD_ID,0,NOAUTOSCROLL,0);
}
//Cursor Setter
void LCDShield::setCursor(byte x ,byte y)
{
	OneSheeld.sendPacket(LCD_ID,0,SETCURSOR,2,new FunctionArg(1,&x),new FunctionArg(1,&y));
}
//Character Sender
void LCDShield::write(byte x)
{
	OneSheeld.sendPacket(LCD_ID,0,WRITE,1,new FunctionArg(1,&x));
}
//Text Sender
void LCDShield::print(char *message)
{
	OneSheeld.sendPacket(LCD_ID,0,PRINT,1,new FunctionArg(strlen(message),(byte*) message));
}

//Instantiating Object
LCDShield LCD;