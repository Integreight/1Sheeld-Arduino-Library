#include "OneSheeld.h"
#include "SevSegShield.h"
#include "HardwareSerial.h"



SevSegShieldClass::SevSegShieldClass()
{
	
	
	
}

//Blink the Sevent Segment by the user  
/*
void SevSegShieldClass::blinkSeg()
{
	//OneSheeld.write(SEV_SEG_ID,BLINK_SEG,dataptr,1);
	OneSheeld.sendPacket(SEV_SEG_ID,0,BLINK_SEG,0);
}
*/

//setting the Seven Segment by sending the number from the user 
void SevSegShieldClass::setNumber(byte x)
{
	byte data2[10]={0x01,0x4f,0x12,0x06,0x4C,0x24,0x20,0x0f,0x00,0x0C};
	
	switch (x)
	{

		case 0 : OneSheeld.sendPacket(SEV_SEG_ID,0,SET_NUMBER,1,new FunctionArg(1,&data2[0]));break;
		case 1 : OneSheeld.sendPacket(SEV_SEG_ID,0,SET_NUMBER,1,new FunctionArg(1,&data2[1]));break;
		case 2 : OneSheeld.sendPacket(SEV_SEG_ID,0,SET_NUMBER,1,new FunctionArg(1,&data2[2]));break;
		case 3 : OneSheeld.sendPacket(SEV_SEG_ID,0,SET_NUMBER,1,new FunctionArg(1,&data2[3]));break;
		case 4 : OneSheeld.sendPacket(SEV_SEG_ID,0,SET_NUMBER,1,new FunctionArg(1,&data2[4]));break;
		case 5 : OneSheeld.sendPacket(SEV_SEG_ID,0,SET_NUMBER,1,new FunctionArg(1,&data2[5]));break;
		case 6 : OneSheeld.sendPacket(SEV_SEG_ID,0,SET_NUMBER,1,new FunctionArg(1,&data2[6]));break;
		case 7 : OneSheeld.sendPacket(SEV_SEG_ID,0,SET_NUMBER,1,new FunctionArg(1,&data2[7]));break;
		case 8 : OneSheeld.sendPacket(SEV_SEG_ID,0,SET_NUMBER,1,new FunctionArg(1,&data2[8]));break;
		case 9 : OneSheeld.sendPacket(SEV_SEG_ID,0,SET_NUMBER,1,new FunctionArg(1,&data2[9]));break;
		

		/*

		/*
		case 0 : OneSheeld.write(SEV_SEG_ID,SET_NUMBER,&data2[0],1);break;
		case 1 : OneSheeld.write(SEV_SEG_ID,SET_NUMBER,&data2[1],1);break;
		case 2 : OneSheeld.write(SEV_SEG_ID,SET_NUMBER,&data2[2],1);break;
		case 3 : OneSheeld.write(SEV_SEG_ID,SET_NUMBER,&data2[3],1);break;
		case 4 : OneSheeld.write(SEV_SEG_ID,SET_NUMBER,&data2[4],1);break;
		case 5 : OneSheeld.write(SEV_SEG_ID,SET_NUMBER,&data2[5],1);break;
		case 6 : OneSheeld.write(SEV_SEG_ID,SET_NUMBER,&data2[6],1);break;
		case 7 : OneSheeld.write(SEV_SEG_ID,SET_NUMBER,&data2[7],1);break;
		case 8 : OneSheeld.write(SEV_SEG_ID,SET_NUMBER,&data2[8],1);break;
		case 9 : OneSheeld.write(SEV_SEG_ID,SET_NUMBER,&data2[9],1);break;
		*/
	}

}


void SevSegShieldClass::setValue(byte shape)
{

	OneSheeld.sendPacket(SEV_SEG_ID,0,SET_VALUE,1,new FunctionArg(1,&shape));

}


SevSegShieldClass SevSeg;