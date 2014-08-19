#include "OneSheeld.h"
#include "OneSheeldPrint.h"




PrintClass::PrintClass()
{

}

void PrintClass::write(byte shieldId , char data)
{
	OneSheeld.sendPacket(shieldId,0,WRITE,1,new FunctionArg(1,(byte *)&data));
}

void PrintClass::print(byte shieldId , char data)
{
	OneSheeld.sendPacket(shieldId,0,PRINT,1,new FunctionArg(1,(byte *)&data));
}

void PrintClass::print(byte shieldId , long data, byte base)
{
	char stringPointer[10];
	itoa(data,stringPointer,base);

	OneSheeld.sendPacket(shieldId,0,PRINT,1,new FunctionArg(strlen(stringPointer),(byte *)stringPointer));
}

void PrintClass::print(byte shieldId,unsigned long data , byte base)
{
	char stringPointer[10];
	itoa(data,stringPointer,base);

	OneSheeld.sendPacket(shieldId,0,PRINT,1,new FunctionArg(strlen(stringPointer),(byte *)stringPointer));	
}

void PrintClass::print(byte shieldId, char * stringData)
{
	OneSheeld.sendPacket(shieldId,0,PRINT,1,new FunctionArg(strlen(stringData),(byte*)stringData));	
}

void PrintClass::print(byte shieldId,double data , int precesion)
{
	char buffer[32];
	dtostrf(data,1,precesion,buffer);
	OneSheeld.sendPacket(TERMINAL_ID,0,PRINT_TERMINAL,1,new FunctionArg(strlen(buffer),(byte *) buffer));
}

void PrintClass::println(byte shieldId,char data)
{
	char buffer[2];
	buffer[0]=data;
	buffer[1]='\n';

	print(shieldId,buffer);
}

void PrintClass::println(byte shieldId,long data ,byte base)
{
	char stringPointer[12];
	itoa(data,stringPointer,base);
	strcat(stringPointer,"\r\n");

	print(shieldId,stringPointer);
}

void PrintClass::println(byte shieldId, unsigned long data , byte base)
{
	char stringPointer[12];
	itoa(data,stringPointer,base);
	strcat(stringPointer,"\r\n");

	print(shieldId,stringPointer);
}

void PrintClass::println(byte shieldId , char * stringData)
{
	char stringNewLine[strlen(stringData)+2];
	strcat(stringNewLine,stringData);
	strcat(stringNewLine,"\r\n");

	print(shieldId,stringNewLine);
}

void PrintClass::println(byte shieldId,double data, int precesion)
{
	int i=0;
	char buffer[32]={'\0'};
	dtostrf(data,32,precesion,buffer);

	while(buffer[i]!='\0' && i<32)
	{
		i++;
	}

	if(i<3)return;
	buffer[i-2]='\r';
	buffer[i-1]='\n';

	print(shieldId,buffer);

}