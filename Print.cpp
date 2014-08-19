#include "OneSheeld.h"
#include "Print.h"




Print::Print()
{

}

void Print::write(byte shieldId , char data)
{
	OneSheeld.sendPacket(shieldId,0,WRITE,1,new FunctionArg(1,&data));
}

void Print::print(byte shieldId , char data)
{
	OneSheeld.sendPacket(shieldId,0,PRINT,1,new FunctionArg(1,&data));
}

void Print::print(byte shieldId , long data, byte base)
{
	char * stringPointer;
	itoa(data,stringPointer,base);

	OneSheeld.sendPacket(shieldId,0,PRINT,1,new FunctionArg(strlen(stringPointer),(byte *)stringPointer));
}

void Print::print(byte shieldId,unsigned long data , byte base)
{
	char * stringPointer;
	itoa(data,stringPointer,base);

	OneSheeld.sendPacket(shieldId,0,PRINT,1,new FunctionArg(strlen(stringPointer),(byte *)stringPointer));	
}

void Print::print(byte shieldId, char * stringData)
{
	OneSheeld.sendPacket(shieldId,0,PRINT,1,new FunctionArg(strlen(stringData),(byte*)stringData));	
}

void Print::print(byte shieldId,double data , int precesion)
{
	char buffer[32];
	dtostrf(data,1,precesion,buffer);
	OneSheeld.sendPacket(TERMINAL_ID,0,PRINT_TERMINAL,1,new FunctionArg(strlen(buffer),(byte *) buffer));
}

void Print::println(byte shieldId,char data)
{
	char buffer[2];
	buffer[0]=data;
	buffer[1]='\n';

	print(buffer);
}

void Print::println(byte shieldId,long data ,byte base)
{
	char * stringPointer;
	char * stringNewLine;
	itoa(data,stringPointer,base);
	stringNewLine=strcat(stringPointer,"\n");

	print(stringNewLine);
}

void Print::println(byte shieldId, unsigned long data , byte base)
{
	char * stringPointer;
	char * stringNewLine;
	itoa(data,stringPointer,base);
	stringNewLine=strcat(stringPointer,"\n");

	print(stringNewLine);
}

void Print::println(byte shieldId , char * stringData)
{
	char * stringNewLine;
	stringNewLine=strcat(stringData,"\n");

	print(stringNewLine);
}

void Print::println(byte shieldId,double data, int precesion)
{
	int i,j=0;
	char buffer[32]={'\0'};
	dtostrf(data,32,precesion,buffer);

	while(buffer[i]!='\0')
	{
		i++;
	}
	buffer[i-1]='\n';

	print(buffer);

}
PrintClass Print;