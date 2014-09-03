/*

  Project:       1Sheeld Library 
  File:          OneSheeldPrint.cpp
                 
  Version:       1.2

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.9

*/

#include "OneSheeld.h"
#include "OneSheeldPrint.h"





PrintClass::PrintClass(byte shid,byte writefnid, byte printfnid)
{
	shieldId=shid;
	print_fn_id=printfnid;
	write_fn_id=writefnid;
}

void PrintClass::write(char data)
{
	OneSheeld.sendPacket(shieldId,0,write_fn_id,1,new FunctionArg(1,(byte *)&data));
}

void PrintClass::print(char data)
{
	OneSheeld.sendPacket(shieldId,0,print_fn_id,1,new FunctionArg(1,(byte *)&data));
}

void PrintClass::print(int data, byte base)
{
	char stringPointer[7];
	snprintf(stringPointer,7,"%d",data);

	OneSheeld.sendPacket(shieldId,0,print_fn_id,1,new FunctionArg(strlen(stringPointer),(byte *)stringPointer));
}

void PrintClass::print(unsigned int data, byte base)
{
	char stringPointer[6];
	snprintf(stringPointer,6,"%d",data);
	
	OneSheeld.sendPacket(shieldId,0,print_fn_id,1,new FunctionArg(strlen(stringPointer),(byte *)stringPointer));
}

void PrintClass::print(long data, byte base)
{
	char stringPointer[12];
	snprintf(stringPointer,12,"%ld",data);
	
	OneSheeld.sendPacket(shieldId,0,print_fn_id,1,new FunctionArg(strlen(stringPointer),(byte *)stringPointer));
}

void PrintClass::print(unsigned long data , byte base)
{
	char stringPointer[11];
	snprintf(stringPointer,11,"%lu",data);
	
	OneSheeld.sendPacket(shieldId,0,print_fn_id,1,new FunctionArg(strlen(stringPointer),(byte *)stringPointer));	
}

void PrintClass::print(const char * stringData)
{
	OneSheeld.sendPacket(shieldId,0,print_fn_id,1,new FunctionArg(strlen(stringData),(byte*)stringData));	
}
	#if  !defined(ARDUINO_LINUX) && !defined(SAM3X8)
		#if (PLATFORM_ID != 0x06)
void PrintClass::print(double data , int precesion)
{
	char buffer[32]={'\0'};
	dtostrf(data,1,precesion,buffer);
	
	OneSheeld.sendPacket(shieldId,0,print_fn_id,1,new FunctionArg(strlen(buffer),(byte *) buffer));
}
	#endif
#endif