#include "OneSheeld.h"
#include "ClockShield.h"




ClockShield::ClockShield()
{
	hours=0;
	minutes=0;
	day=0;
	month=0;
	year=0;

}

void ClockShield::begin()
{
	OneSheeld.sendPacket(CLOCK_ID,0,BEGIN_CLOCK,0);
	timeStart=millis();
	isClockInit=false;
	while(!isClockInit)
	{
		timeCheck=millis();
		if(timeCheck-timeStart>=ONE_SECOND)
		{
			break;
		}

		OneSheeld.processInput();
		
	}
}
byte ClockShield::getSeconds()
{
	return seconds;
}
byte ClockShield::getHours()
{
	return hours;
}

byte ClockShield::getMinutes()
{
	return minutes;
}

byte ClockShield::getDay()
{
	return day;
}

byte ClockShield::getMonth()
{
	return month;
}

short ClockShield::getYear()
{
	return year;
}

void ClockShield::processData()
{
	byte functionId=OneSheeld.getFunctionId();
	if(functionId==DATE_VALUE)
	{
		byte argumentNumber=OneSheeld.getArgumentNo();
		switch(argumentNumber)
		{
			case 0x01 	: 	seconds=OneSheeld.getArgumentData(0)[0];break;
			
			case 0x02 	: 	seconds=OneSheeld.getArgumentData(0)[0];
							minutes=OneSheeld.getArgumentData(1)[0];break;
			
			case 0x03	: 	seconds=OneSheeld.getArgumentData(0)[0];
						    minutes=OneSheeld.getArgumentData(1)[0];
						   	hours=OneSheeld.getArgumentData(2)[0];break;
			
			case 0x04 	: 	seconds=OneSheeld.getArgumentData(0)[0];
						    minutes=OneSheeld.getArgumentData(1)[0];
						   	hours=OneSheeld.getArgumentData(2)[0];
						   	day=OneSheeld.getArgumentData(3)[0];break;
			
			case 0x05 	:	seconds=OneSheeld.getArgumentData(0)[0];
						    minutes=OneSheeld.getArgumentData(1)[0];
						   	hours=OneSheeld.getArgumentData(2)[0];
						   	day=OneSheeld.getArgumentData(3)[0];
						   	month=OneSheeld.getArgumentData(4)[0];break;

			case 0x06	:	isClockInit=true;
							seconds=OneSheeld.getArgumentData(0)[0];
						    minutes=OneSheeld.getArgumentData(1)[0];
						   	hours=OneSheeld.getArgumentData(2)[0];
						   	day=OneSheeld.getArgumentData(3)[0];
						   	month=OneSheeld.getArgumentData(4)[0];
						   	year|=(short)OneSheeld.getArgumentData(5)[0];
						   	year|=(short)(OneSheeld.getArgumentData(5)[1]<<8);break;

		}
	}
}

ClockShield Clock;

