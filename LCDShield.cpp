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

LCDShield::LCDShield()
{
	signFlag=0;
}
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
void LCDShield::write(byte data)
{
	OneSheeld.sendPacket(LCD_ID,0,WRITE,1,new FunctionArg (1,&data));
}

void LCDShield::print(char data)
{
	write(data);
}

void LCDShield::print(char * string)
{
	OneSheeld.sendPacket(LCD_ID,0,PRINT,1,new FunctionArg (strlen(string),(byte *)string));
}

void LCDShield::print(int data ,byte base)
{
	print((long)data,base);
}

void LCDShield::print(unsigned int data ,byte base)
{
	print((unsigned long)data,base);
}

void LCDShield::print(long data,byte base)
{
	//Serial.print("processed");
	if (base == 0) 
	{
		write(data);
	}
	else if (base==10)
	{
		if(data<0)
		{
			signFlag=1;
			data= -data;
			printNumber(data,10);
		}
		else
		{
			printNumber(data,10);
		}
	}
	else
	{
		printNumber(data,base);
	}
}

void LCDShield::print(unsigned long data , byte base)
{
	if(base==0) write(data);
	else printNumber(data,base);
}

void LCDShield::print(double data)
{
	char buffer[32];
	dtostrf(data,1,3,buffer);
	OneSheeld.sendPacket(LCD_ID,0,PRINT,1,new FunctionArg(strlen(buffer),(byte *) buffer));
}

void LCDShield::printNumber(unsigned long num , byte base)
{
	char buff[8* sizeof(long)+1]; //buffer for largest number and another byte for the null 
	char * str=&buff[sizeof(buff)-1]; //point to the pre-last place in the buffer

	*str='\0';

	if(base <2) base =10; //preventing crash if called by 1

	do 
	{
		unsigned long m =num ;
		num/=base;
		char c = m-base*num;
		*--str= c < 10 ? c + '0': c + 'A'-10; 
	}while(num);

	if(signFlag>0)
	{
		*--str='-';
		signFlag=0;
	}

OneSheeld.sendPacket(LCD_ID,0,PRINT,1,new FunctionArg(strlen(str),(byte *)str));
}


//Instantiating Object
LCDShield LCD;