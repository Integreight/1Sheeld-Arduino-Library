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
void LCDShield::begin(byte x,byte y)
{ 
	OneSheeld.sendPacket(LCD_ID,0,BEGIN,2,new FunctionArg(1,&x),new FunctionArg(1,&y));
}
//Setter
void LCDShield::clear()
{
	OneSheeld.sendPacket(LCD_ID,0,CLEAR,0);
}
//Setter
void LCDShield::home()
{
	OneSheeld.sendPacket(LCD_ID,0,HOME,0);
}
//Setter
void LCDShield::noBlink()
{
	OneSheeld.sendPacket(LCD_ID,0,NOBLINK,0);
}
//Setter
void LCDShield::blink()
{
	OneSheeld.sendPacket(LCD_ID,0,BLINK,0);
}
//Setter
void LCDShield::noCursor()
{
	OneSheeld.sendPacket(LCD_ID,0,NOCURSOR,0);
}
//Setter
void LCDShield::cursor()
{
	OneSheeld.sendPacket(LCD_ID,0,CURSOR,0);
}
//Setter
void LCDShield::scrollDisplayLeft()
{
	OneSheeld.sendPacket(LCD_ID,0,SCROLLLEFT,0);
}
//Setter
void LCDShield::scrollDisplayRight()
{
	OneSheeld.sendPacket(LCD_ID,0,SCROLLRIGHT,0);
}
//Setter
void LCDShield::leftToRight()
{
	OneSheeld.sendPacket(LCD_ID,0,LEFT_RIGHT,0);
}
//Setter
void LCDShield::rightToLeft()
{
	OneSheeld.sendPacket(LCD_ID,0,RIGHT_LEFT,0);
}
//Setter
void LCDShield::autoScroll()
{
	OneSheeld.sendPacket(LCD_ID,0,AUTOSCROLL,0);
}
//Setter
void LCDShield::noAutoScroll()
{
	OneSheeld.sendPacket(LCD_ID,0,NOAUTOSCROLL,0);
}
//Setter
void LCDShield::setCursor(byte x ,byte y)
{
	OneSheeld.sendPacket(LCD_ID,0,SETCURSOR,2,new FunctionArg(1,&x),new FunctionArg(1,&y));
}
//Sender
void LCDShield::write(byte x)
{
	OneSheeld.sendPacket(LCD_ID,0,WRITE,1,new FunctionArg(1,&x));
}
//Sender
void LCDShield::print(char *message)
{
	OneSheeld.sendPacket(LCD_ID,0,PRINT,1,new FunctionArg(strlen(message),(byte*) message));
}

//Instantiating Object
LCDShield LCD;