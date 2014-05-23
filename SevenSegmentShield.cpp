#include "OneSheeld.h"
#include "SevenSegmentShield.h"

//setting the Seven Segment by sending the number from the user 
void SevenSegmentShieldClass::setNumber(byte x)
{
	byte data2[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	
	switch (x)
	{

		case 0 : setCharacter(data2[0]);break;
		case 1 : setCharacter(data2[1]);break;
		case 2 : setCharacter(data2[2]);break;
		case 3 : setCharacter(data2[3]);break;
		case 4 : setCharacter(data2[4]);break;
		case 5 : setCharacter(data2[5]);break;
		case 6 : setCharacter(data2[6]);break;
		case 7 : setCharacter(data2[7]);break;
		case 8 : setCharacter(data2[8]);break;
		case 9 : setCharacter(data2[9]);break;
	}

}


void SevenSegmentShieldClass::setCharacter(byte shape)
{

	OneSheeld.sendPacket(SEV_SEG_ID,0,SET_VALUE,1,new FunctionArg(1,&shape));

}

void SevenSegmentShieldClass::setDot()
{

	OneSheeld.sendPacket(SEV_SEG_ID,0,SET_DOT,0);

}



SevenSegmentShieldClass SevenSegment;