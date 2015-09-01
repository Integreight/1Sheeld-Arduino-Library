/*

  Project:       1Sheeld Library 
  File:          LCDShield.cpp
                 
  Version:       1.2

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "LCDShield.h"

LCDShield::LCDShield():PrintClass(LCD_ID,LCD_WRITE,LCD_PRINT),ShieldParent(LCD_ID)
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
	OneSheeld.sendShieldFrame(LCD_ID,0,LCD_CLEAR,0);
}
//Home Setter
void LCDShield::home()
{
	OneSheeld.sendShieldFrame(LCD_ID,0,LCD_HOME,0);
}
//NoBlink Setter
void LCDShield::noBlink()
{
	OneSheeld.sendShieldFrame(LCD_ID,0,LCD_NOBLINK,0);
}
//Blink Setter
void LCDShield::blink()
{
	OneSheeld.sendShieldFrame(LCD_ID,0,LCD_BLINK,0);
}
//NoCursor Setter
void LCDShield::noCursor()
{
	OneSheeld.sendShieldFrame(LCD_ID,0,LCD_NOCURSOR,0);
}
//Display Cursor Setter
void LCDShield::cursor()
{
	OneSheeld.sendShieldFrame(LCD_ID,0,LCD_CURSOR,0);
}
//Scrolling Setter
void LCDShield::scrollDisplayLeft()
{
	OneSheeld.sendShieldFrame(LCD_ID,0,LCD_SCROLLLEFT,0);
}
//Scrolling Setter
void LCDShield::scrollDisplayRight()
{
	OneSheeld.sendShieldFrame(LCD_ID,0,LCD_SCROLLRIGHT,0);
}
//left-Right Setter
void LCDShield::leftToRight()
{
	OneSheeld.sendShieldFrame(LCD_ID,0,LCD_LEFT_RIGHT,0);
}
//Right-left Setter
void LCDShield::rightToLeft()
{
	OneSheeld.sendShieldFrame(LCD_ID,0,LCD_RIGHT_LEFT,0);
}
//AutoScroll Setter
void LCDShield::autoScroll()
{
	OneSheeld.sendShieldFrame(LCD_ID,0,LCD_AUTOSCROLL,0);
}
//NoAutoScroll Setter
void LCDShield::noAutoScroll()
{
	OneSheeld.sendShieldFrame(LCD_ID,0,LCD_NOAUTOSCROLL,0);
}
//Cursor Setter
void LCDShield::setCursor(byte x ,byte y)
{
	OneSheeld.sendShieldFrame(LCD_ID,0,LCD_SETCURSOR,2,new FunctionArg(1,&x),new FunctionArg(1,&y));
}

