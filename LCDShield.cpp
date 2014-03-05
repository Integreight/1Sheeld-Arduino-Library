#include "OneSheeld.h"
#include "LCDShield.h"


void LCDShield::begin(byte x,byte y)
{ 
	OneSheeld.sendPacket(LCD_ID,0,BEGIN,2,new FunctionArg(1,&x),new FunctionArg(1,&y));
}
void LCDShield::clear()
{
	OneSheeld.sendPacket(LCD_ID,0,CLEAR,0);
}

void LCDShield::home()
{
	OneSheeld.sendPacket(LCD_ID,0,HOME,0);
}

void LCDShield::noDisplay()
{
	OneSheeld.sendPacket(LCD_ID,0,NODISPLAY,0);
}

void LCDShield::display()
{
	OneSheeld.sendPacket(LCD_ID,0,DISPLAY,0);
}

void LCDShield::noBlink()
{
	OneSheeld.sendPacket(LCD_ID,0,NOBLINK,0);
}

void LCDShield::blink()
{
	OneSheeld.sendPacket(LCD_ID,0,BLINK,0);
}

void LCDShield::noCursor()
{
	OneSheeld.sendPacket(LCD_ID,0,NOCURSOR,0);
}

void LCDShield::cursor()
{
	OneSheeld.sendPacket(LCD_ID,0,CURSOR,0);
}

void LCDShield::scrollDisplayLeft()
{
	OneSheeld.sendPacket(LCD_ID,0,SCROLLLEFT,0);
}

void LCDShield::scrollDisplayRight()
{
	OneSheeld.sendPacket(LCD_ID,0,SCROLLRIGHT,0);
}

void LCDShield::leftToRight()
{
	OneSheeld.sendPacket(LCD_ID,0,LEFT_RIGHT,0);
}

void LCDShield::rightToLeft()
{
	OneSheeld.sendPacket(LCD_ID,0,RIGHT_LEFT,0);
}

void LCDShield::autoScroll()
{
	OneSheeld.sendPacket(LCD_ID,0,AUTOSCROLL,0);
}

void LCDShield::noAutoScroll()
{
	OneSheeld.sendPacket(LCD_ID,0,NOAUTOSCROLL,0);
}

void LCDShield::createChar(char * x)
{
	//takes the bytes from the user in an array 
	for (int i = 0; i < 8; ++i)
	{
		OneSheeld.sendPacket(LCD_ID,0,CREATECHAR,1,new FunctionArg(1,(byte*)x[i]));	
	}
	
}

void LCDShield::setCursor(byte x ,byte y)
{
	OneSheeld.sendPacket(LCD_ID,0,SETCURSOR,2,new FunctionArg(1,&x),new FunctionArg(1,&y));
}

void LCDShield::write(byte x)
{
	OneSheeld.sendPacket(LCD_ID,0,WRITE,1,new FunctionArg(1,&x));
}

void LCDShield::print(char *message)
{
OneSheeld.sendPacket(LCD_ID,0,PRINT,1,new FunctionArg(strlen(message),(byte*) message));
}
LCDShield LCD;