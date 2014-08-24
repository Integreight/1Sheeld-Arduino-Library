#include "OneSheeld.h"
#include "OneSheeldPrintln.h"


PrintlnClass::PrintlnClass(byte shid,byte writefnid, byte printfnid):PrintClass(shid,writefnid,printfnid)
{
}

void PrintlnClass::println(char data)
{
	char buffer[4];
	buffer[0]=data;
	buffer[1]='\r';
	buffer[2]='\n';
	buffer[3]='\0';
	
	print(buffer);
}

void PrintlnClass::println(int data ,byte base)
{
	char stringPointer[9]={'\0'};
	itoa(data,stringPointer,base);
	strcat(stringPointer,"\r\n");
	
	print(stringPointer);
}

void PrintlnClass::println(unsigned int data , byte base)
{
	char stringPointer[8]={'\0'};
	itoa(data,stringPointer,base);
	strcat(stringPointer,"\r\n");
	
	print(stringPointer);
}
void PrintlnClass::println(long data ,byte base)
{
	char stringPointer[14]={'\0'};
	ltoa(data,stringPointer,base);
	strcat(stringPointer,"\r\n");
	
	print(stringPointer);
}

void PrintlnClass::println(unsigned long data , byte base)
{
	char stringPointer[13]={'\0'};
	ultoa(data,stringPointer,base);
	strcat(stringPointer,"\r\n");
	
	print(stringPointer);
}

void PrintlnClass::println(char * stringData)
{
	char stringNewLine[strlen(stringData)+2];
	stringNewLine[0]='\0';
	strcat(stringNewLine,stringData);
	strcat(stringNewLine,"\r\n");

	print(stringNewLine);
}

void PrintlnClass::println(double data, int precesion)
{
	int i=0;
	char buffer[32]={'\0'};
	dtostrf(data,1,precesion,buffer);

	while(buffer[i]!='\0' && i<32)i++;

	if(i+2>32)return;
	buffer[i]='\r';
	buffer[i+1]='\n';
	buffer[i+2]='\0';

	print(buffer);

}

