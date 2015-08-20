/*

  Project:       1Sheeld Library 
  File:          ClockShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "ClockShield.h"



//Class Constructor
ClockShield::ClockShield() : ShieldParent(CLOCK_ID)
{
	hours=0;
	minutes=0;
	day=0;
	month=0;
	year=0;
}

//Blocking function 
void ClockShield::queryDateAndTime()
{
	OneSheeld.sendShieldFrame(CLOCK_ID,0,CLOCK_BEGIN,0);
}
//Seconds getter 
byte ClockShield::getSeconds()
{
	return seconds;
}

//Minutes getter 
byte ClockShield::getMinutes()
{
	return minutes;
}
//Hours getter 
byte ClockShield::getHours()
{
	return hours;
}
//Day getter 
byte ClockShield::getDay()
{
	return day;
}
//Month getter 
byte ClockShield::getMonth()
{
	return month;
}
//Year getter 
short ClockShield::getYear()
{
	return year;
}
//Clock Input Data Processing 
void ClockShield::processData()
{
	//Checking Function-ID
	byte functionId=getOneSheeldInstance().getFunctionId();
	if(functionId==CLOCK_DATE_VALUE)
	{
		byte argumentNumber=getOneSheeldInstance().getArgumentNo();
		switch(argumentNumber)
		{
			case 0x01 	: 	seconds=getOneSheeldInstance().getArgumentData(0)[0];break;
			
			case 0x02 	: 	seconds=getOneSheeldInstance().getArgumentData(0)[0];
							minutes=getOneSheeldInstance().getArgumentData(1)[0];break;
			
			case 0x03	: 	seconds=getOneSheeldInstance().getArgumentData(0)[0];
						    minutes=getOneSheeldInstance().getArgumentData(1)[0];
						   	hours=getOneSheeldInstance().getArgumentData(2)[0];break;
			
			case 0x04 	: 	seconds=getOneSheeldInstance().getArgumentData(0)[0];
						    minutes=getOneSheeldInstance().getArgumentData(1)[0];
						   	hours=getOneSheeldInstance().getArgumentData(2)[0];
						   	day=getOneSheeldInstance().getArgumentData(3)[0];break;
			
			case 0x05 	:	seconds=getOneSheeldInstance().getArgumentData(0)[0];
						    minutes=getOneSheeldInstance().getArgumentData(1)[0];
						   	hours=getOneSheeldInstance().getArgumentData(2)[0];
						   	day=getOneSheeldInstance().getArgumentData(3)[0];
						   	month=getOneSheeldInstance().getArgumentData(4)[0];break;

			case 0x06	:	seconds=getOneSheeldInstance().getArgumentData(0)[0];
						    minutes=getOneSheeldInstance().getArgumentData(1)[0];
						   	hours=getOneSheeldInstance().getArgumentData(2)[0];
						   	day=getOneSheeldInstance().getArgumentData(3)[0];
						   	month=getOneSheeldInstance().getArgumentData(4)[0];
						   	year|=(short)getOneSheeldInstance().getArgumentData(5)[0];
						   	year|=(short)(getOneSheeldInstance().getArgumentData(5)[1]<<8);break;

		}
	}
}

