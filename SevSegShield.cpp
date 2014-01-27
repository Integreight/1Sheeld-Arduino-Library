#include "OneSheeld.h"
#include "SevSegShield.h"
#include "HardwareSerial.h"



SevSegShieldClass::SevSegShieldClass()
{
	data =0xff;
	
	
}

//Blink the Sevent Segment by the user  
void SevSegShieldClass::blinkSeg()
{
	dataptr=&data;
	//OneSheeld.write(SEV_SEG_ID,BLINK_SEG,dataptr,1);
	OneSheeld.sendPacket(SEV_SEG_ID,BLINK_SEG,0,0);
}


//setting the Seven Segment by sending the number from the user 
void SevSegShieldClass::setSeg(int x)
{
	byte data2[10]={0x01,0x4f,0x12,0x06,0x4C,0x24,0x20,0x0f,0x00,0x0C};
	byte *ptr=data2;

	switch (x)
	{

		case 0 : OneSheeld.sendPacket(SEV_SEG_ID,SET_SEG,0,1,new FunctionArg(1,ptr));break;
		case 1 : OneSheeld.sendPacket(SEV_SEG_ID,SET_SEG,0,1,new FunctionArg(1,ptr+1));break;
		case 2 : OneSheeld.sendPacket(SEV_SEG_ID,SET_SEG,0,1,new FunctionArg(1,ptr+2));break;
		case 3 : OneSheeld.sendPacket(SEV_SEG_ID,SET_SEG,0,1,new FunctionArg(1,ptr+3));break;
		case 4 : OneSheeld.sendPacket(SEV_SEG_ID,SET_SEG,0,1,new FunctionArg(1,ptr+4));break;
		case 5 : OneSheeld.sendPacket(SEV_SEG_ID,SET_SEG,0,1,new FunctionArg(1,ptr+5));break;
		case 6 : OneSheeld.sendPacket(SEV_SEG_ID,SET_SEG,0,1,new FunctionArg(1,ptr+6));break;
		case 7 : OneSheeld.sendPacket(SEV_SEG_ID,SET_SEG,0,1,new FunctionArg(1,ptr+7));break;
		case 8 : OneSheeld.sendPacket(SEV_SEG_ID,SET_SEG,0,1,new FunctionArg(1,ptr+8));break;
		case 9 : OneSheeld.sendPacket(SEV_SEG_ID,SET_SEG,0,1,new FunctionArg(1,ptr+9));break;
		

		/*

		/*
		case 0 : OneSheeld.write(SEV_SEG_ID,SET_SEG,&data2[0],1);break;
		case 1 : OneSheeld.write(SEV_SEG_ID,SET_SEG,&data2[1],1);break;
		case 2 : OneSheeld.write(SEV_SEG_ID,SET_SEG,&data2[2],1);break;
		case 3 : OneSheeld.write(SEV_SEG_ID,SET_SEG,&data2[3],1);break;
		case 4 : OneSheeld.write(SEV_SEG_ID,SET_SEG,&data2[4],1);break;
		case 5 : OneSheeld.write(SEV_SEG_ID,SET_SEG,&data2[5],1);break;
		case 6 : OneSheeld.write(SEV_SEG_ID,SET_SEG,&data2[6],1);break;
		case 7 : OneSheeld.write(SEV_SEG_ID,SET_SEG,&data2[7],1);break;
		case 8 : OneSheeld.write(SEV_SEG_ID,SET_SEG,&data2[8],1);break;
		case 9 : OneSheeld.write(SEV_SEG_ID,SET_SEG,&data2[9],1);break;
		*/
	}

}


void SevSegShieldClass::setCustomChar(byte shape)
{
	byte *pointer=&shape;

	OneSheeld.sendPacket(SEV_SEG_ID,SET_CHAR,0,1,new FunctionArg(1,pointer));

}


SevSegShieldClass SevSeg;