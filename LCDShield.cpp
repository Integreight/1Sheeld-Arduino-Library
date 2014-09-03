/*

  Project:       1Sheeld Library 
  File:          LCDShield.cpp
                 
  Version:       1.2

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "OneSheeld.h"
#include "LCDShield.h"

LCDShield::LCDShield():PrintClass(LCD_ID,LCD_WRITE,LCD_PRINT)
{}
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
	OneSheeld.sendPacket(LCD_ID,0,LCD_CLEAR,0);
}
//Home Setter
void LCDShield::home()
{
	OneSheeld.sendPacket(LCD_ID,0,LCD_HOME,0);
}
//NoBlink Setter
void LCDShield::noBlink()
{
	OneSheeld.sendPacket(LCD_ID,0,LCD_NOBLINK,0);
}
//Blink Setter
void LCDShield::blink()
{
	OneSheeld.sendPacket(LCD_ID,0,LCD_BLINK,0);
}
//NoCursor Setter
void LCDShield::noCursor()
{
	OneSheeld.sendPacket(LCD_ID,0,LCD_NOCURSOR,0);
}
//Display Cursor Setter
void LCDShield::cursor()
{
	OneSheeld.sendPacket(LCD_ID,0,LCD_CURSOR,0);
}
//Scrolling Setter
void LCDShield::scrollDisplayLeft()
{
	OneSheeld.sendPacket(LCD_ID,0,LCD_SCROLLLEFT,0);
}
//Scrolling Setter
void LCDShield::scrollDisplayRight()
{
	OneSheeld.sendPacket(LCD_ID,0,LCD_SCROLLRIGHT,0);
}
//left-Right Setter
void LCDShield::leftToRight()
{
	OneSheeld.sendPacket(LCD_ID,0,LCD_LEFT_RIGHT,0);
}
//Right-left Setter
void LCDShield::rightToLeft()
{
	OneSheeld.sendPacket(LCD_ID,0,LCD_RIGHT_LEFT,0);
}
//AutoScroll Setter
void LCDShield::autoScroll()
{
	OneSheeld.sendPacket(LCD_ID,0,LCD_AUTOSCROLL,0);
}
//NoAutoScroll Setter
void LCDShield::noAutoScroll()
{
	OneSheeld.sendPacket(LCD_ID,0,LCD_NOAUTOSCROLL,0);
}
//Cursor Setter
void LCDShield::setCursor(byte x ,byte y)
{
	OneSheeld.sendPacket(LCD_ID,0,LCD_SETCURSOR,2,new FunctionArg(1,&x),new FunctionArg(1,&y));
}

//Instantiating Object
LCDShield LCD;