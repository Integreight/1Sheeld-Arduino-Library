#include "OneSheeld.h"
#include "OneSheeldPrint.h"




PrintClass::PrintClass(byte shid,byte fnidofsset=0)
{
	shieldId=shid;
	functionsIdOffset=fnidofsset;
}

void PrintClass::write(char data)
{
	OneSheeld.sendPacket(shieldId,0,WRITE+functionsIdOffset,1,new FunctionArg(1,(byte *)&data));
}

void PrintClass::print(char data)
{
	OneSheeld.sendPacket(shieldId,0,PRINT+functionsIdOffset,1,new FunctionArg(1,(byte *)&data));
}

void PrintClass::print(int data, byte base)
{
	char stringPointer[7]={'\0'};
	itoa(data,stringPointer,base);
	
	OneSheeld.sendPacket(shieldId,0,PRINT+functionsIdOffset,1,new FunctionArg(strlen(stringPointer),(byte *)stringPointer));
}

void PrintClass::print(unsigned int data, byte base)
{
	char stringPointer[6]={'\0'};
	itoa(data,stringPointer,base);
	
	OneSheeld.sendPacket(shieldId,0,PRINT+functionsIdOffset,1,new FunctionArg(strlen(stringPointer),(byte *)stringPointer));
}

void PrintClass::print(long data, byte base)
{
	char stringPointer[12]={'\0'};
	ltoa(data,stringPointer,base);
	
	OneSheeld.sendPacket(shieldId,0,PRINT+functionsIdOffset,1,new FunctionArg(strlen(stringPointer),(byte *)stringPointer));
}

void PrintClass::print(unsigned long data , byte base)
{
	char stringPointer[11]={'\0'};
	ultoa(data,stringPointer,base);
	
	OneSheeld.sendPacket(shieldId,0,PRINT+functionsIdOffset,1,new FunctionArg(strlen(stringPointer),(byte *)stringPointer));	
}

void PrintClass::print(char * stringData)
{
	OneSheeld.sendPacket(shieldId,0,PRINT+functionsIdOffset,1,new FunctionArg(strlen(stringData),(byte*)stringData));	
}

void PrintClass::print(double data , int precesion)
{
	char buffer[32]={'\0'};;
	dtostrf(data,1,precesion,buffer);
	
	OneSheeld.sendPacket(shieldId,0,PRINT+functionsIdOffset,1,new FunctionArg(strlen(buffer),(byte *) buffer));
}

void PrintClass::println(char data)
{
	char buffer[3];
	buffer[0]=data;
	buffer[1]='\r';
	buffer[2]='\n';
	
	print(buffer);
}

void PrintClass::println(int data ,byte base)
{
	char stringPointer[9]={'\0'};;
	itoa(data,stringPointer,base);
	strcat(stringPointer,"\r\n");
	
	print(stringPointer);
}

void PrintClass::println(unsigned int data , byte base)
{
	char stringPointer[8]={'\0'};
	itoa(data,stringPointer,base);
	strcat(stringPointer,"\r\n");
	
	print(stringPointer);
}
void PrintClass::println(long data ,byte base)
{
	char stringPointer[14]={'\0'};
	ltoa(data,stringPointer,base);
	strcat(stringPointer,"\r\n");
	
	print(stringPointer);
}

void PrintClass::println(unsigned long data , byte base)
{
	char stringPointer[13]={'\0'};
	ultoa(data,stringPointer,base);
	strcat(stringPointer,"\r\n");
	
	print(stringPointer);
}

void PrintClass::println(char * stringData)
{
	char stringNewLine[strlen(stringData)+2];
	strcat(stringNewLine,stringData);
	strcat(stringNewLine,"\r\n");

	print(stringNewLine);
}

void PrintClass::println(double data, int precesion)
{
	int i=0;
	char buffer[32]={'\0'};
	dtostrf(data,1,precesion,buffer);

	while(buffer[i]!='\0' && i<32)i++;

	if(i<3)return;
	buffer[i-2]='\r';
	buffer[i-1]='\n';

	print(buffer);

}