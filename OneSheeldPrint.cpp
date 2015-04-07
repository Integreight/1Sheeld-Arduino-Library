/*

  Project:       1Sheeld Library 
  File:          OneSheeldPrint.cpp
                 
  Version:       1.2

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.9

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "OneSheeldPrint.h"




//Constructor 
PrintClass::PrintClass(byte shid,byte writefnid, byte printfnid)
{
	shieldId=shid;
	print_fn_id=printfnid;
	write_fn_id=writefnid;
}
//Write character 
void PrintClass::write(char data)
{
	OneSheeld.sendPacket(shieldId,0,write_fn_id,1,new FunctionArg(1,(byte *)&data));
}
//Print character
void PrintClass::print(char data)
{
	OneSheeld.sendPacket(shieldId,0,print_fn_id,1,new FunctionArg(1,(byte *)&data));
}
//Print integers
void PrintClass::print(int data, byte base)
{
	char stringPointer[7];
	snprintf(stringPointer,7,"%d",data);

	OneSheeld.sendPacket(shieldId,0,print_fn_id,1,new FunctionArg(strlen(stringPointer),(byte *)stringPointer));
}
//Print unsigned integers 
void PrintClass::print(unsigned int data, byte base)
{
	char stringPointer[6];
	snprintf(stringPointer,6,"%d",data);
	
	OneSheeld.sendPacket(shieldId,0,print_fn_id,1,new FunctionArg(strlen(stringPointer),(byte *)stringPointer));
}
//Print long integers
void PrintClass::print(long data, byte base)
{
	char stringPointer[12];
	snprintf(stringPointer,12,"%ld",data);
	
	OneSheeld.sendPacket(shieldId,0,print_fn_id,1,new FunctionArg(strlen(stringPointer),(byte *)stringPointer));
}
//Print unsigned long integers
void PrintClass::print(unsigned long data , byte base)
{
	char stringPointer[11];
	snprintf(stringPointer,11,"%lu",data);
	
	OneSheeld.sendPacket(shieldId,0,print_fn_id,1,new FunctionArg(strlen(stringPointer),(byte *)stringPointer));	
}
//Print string
void PrintClass::print(const char * stringData)
{
	//Check length of string 
	int stringDataLength = strlen(stringData);
	if(!stringDataLength) return;
	OneSheeld.sendPacket(shieldId,0,print_fn_id,1,new FunctionArg(stringDataLength,(byte*)stringData));	
}

void PrintClass::print(String stringData)
{
	int stringDataLength = stringData.length();

	char cTypeStringData[stringDataLength+1];

	for(int i=0 ;i<stringDataLength ;i++)
	{
		cTypeStringData[i]=stringData[i];
	}
	cTypeStringData[stringDataLength]='\0';

	print(cTypeStringData);
}

//Print double 
//Unsupported by Intel Galileo board and Arduino Due
#if  !defined(ARDUINO_LINUX) && !defined(SAM3X8)
void PrintClass::print(double data , int precesion)
{
	char buffer[32]={'\0'};
	dtostrf(data,1,precesion,buffer);
	
	OneSheeld.sendPacket(shieldId,0,print_fn_id,1,new FunctionArg(strlen(buffer),(byte *) buffer));
}
#endif