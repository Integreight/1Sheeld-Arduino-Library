#include "OneSheeld.h"
#include "TerminalShield.h"

TerminalShield::TerminalShield():PrintClass(TERMINAL_ID,0)
{
	// data = 0;
	// string = NULL;
	// signFlag=0;
	// newLineFlag=0;
}

// void TerminalShield::write(byte data)
// {
// 	char buff[2]={data};
// 	if(newLineFlag>0)
// 	{
// 		char newLine[2]={'\n','\0'};
// 		strcat(buff,newLine);
// 		newLineFlag=0;
// 	}
// 	OneSheeld.sendPacket(TERMINAL_ID,0,WRITE_TERMINAL,1,new FunctionArg (strlen(buff),(byte *)buff));
// }

// void TerminalShield::print(char data)
// {
// 	write(data);
// }

// void TerminalShield::print(char * string)
// {
// 	if(newLineFlag>0)
// 	{
// 		char newLine[2]={'\n','\0'};
// 		strcat(string,newLine);
// 		newLineFlag=0;
// 	}
// 	OneSheeld.sendPacket(TERMINAL_ID,0,PRINT_TERMINAL,1,new FunctionArg (strlen(string),(byte *)string));
// }

// void TerminalShield::print(int data ,byte base)
// {
// 	print((long)data,base);
// }

// void TerminalShield::print(unsigned int data ,byte base)
// {
// 	print((unsigned long)data,base);
// }

// void TerminalShield::print(long data,byte base)
// {
// 	if (base == 0) 
// 	{
// 		write(data);
// 	}
// 	else if (base==10)
// 	{
// 		if(data<0)
// 		{
// 			signFlag=1;
// 			data= -data;
// 			printNumber(data,10);
// 		}
// 		else
// 		{
// 			printNumber(data,10);
// 		}
// 	}
// 	else
// 	{
// 		printNumber(data,base);
// 	}
// }

// void TerminalShield::print(unsigned long data , byte base)
// {
// 	if(base==0) write(data);
// 	else printNumber(data,base);
// }


// void TerminalShield::println(char data)
// {
// 	newLineFlag=1;
// 	write(data);
// }

// void TerminalShield::println(int data ,byte base)
// {
// 	newLineFlag=1;
// 	print((long) data,base);
// }

// void TerminalShield::println(unsigned int data, byte base)
// {
// 	newLineFlag=1;
// 	print((unsigned long)data,base);
// }

// void TerminalShield::println(long data ,byte base)
// {
// 	newLineFlag=1;
// 	print((long)data,base);
// }

// void TerminalShield::println(unsigned long data, byte base)
// {
// 	newLineFlag=1;
// 	print((unsigned long)data,base);
// }

// void TerminalShield::println(char * string)
// {
// 	newLineFlag=1;
// 	print(string);
// }
// void TerminalShield::printNumber(unsigned long num , byte base)
// {
// 	char buff[8* sizeof(long)+1]; //buffer for largest number and another byte for the null 
// 	char * str=&buff[sizeof(buff)-1]; //point to the pre-last place in the buffer

// 	*str='\0';

// 	if (newLineFlag>0)
// 	{
// 		str=&buff[sizeof(buff)-2];
// 		*str='\n';
// 		newLineFlag=0;
// 	}

// 	if(base <2) base =10; //preventing crash if called by 1

// 	do 
// 	{
// 		unsigned long m =num ;
// 		num/=base;
// 		char c = m-base*num;
// 		*--str= c < 10 ? c + '0': c + 'A'-10; 
// 	}while(num);

// 	if(signFlag>0)
// 	{
// 		*--str='-';
// 		signFlag=0;
// 	}


// OneSheeld.sendPacket(TERMINAL_ID,0,PRINT_TERMINAL,1,new FunctionArg(strlen(str),(byte *)str));
// }

// void TerminalShield::print(double data)
// {
// 	char buffer[32];
// 	dtostrf(data,1,3,buffer);
// 	OneSheeld.sendPacket(TERMINAL_ID,0,PRINT_TERMINAL,1,new FunctionArg(strlen(buffer),(byte *) buffer));
// }

// char TerminalShield::getData()
// {
// 	return data;
// }

// char * TerminalShield::getString()
// {
// 	return string;
// }

void TerminalShield::processData()
{
	byte functionID = OneSheeld.getFunctionId();
	byte dataLength = OneSheeld.getArgumentLength(0);
	if(functionID == READ)
	{
		if(dataLength>1)
		{
			if (string!=0)
			{
				free(string);
			}	
			string = (char*)malloc(sizeof(char)*(dataLength+1));
			for (int j=0; j<dataLength; j++)
			{
				string[j]=OneSheeld.getArgumentData(0)[j];
			}
			string[dataLength]='\0';
		}
		else
		{
			data = OneSheeld.getArgumentData(0)[0];
		}
	}
}
TerminalShield Terminal;