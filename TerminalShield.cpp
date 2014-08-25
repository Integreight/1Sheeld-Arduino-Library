/*

  Project:       1Sheeld Library 
  File:          TerminalShield.cpp
                 
  Version:       3.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.8

*/

#include "OneSheeld.h"
#include "TerminalShield.h"

TerminalShield::TerminalShield():PrintlnClass(TERMINAL_ID,TERMINAL_WRITE,TERMINAL_PRINT)
{}

char TerminalShield::read()
{
	if(buffer.remain()<=0)return -1;
	return buffer.pop();
}

void TerminalShield::flush()
{
	while(read()!=-1);
}

int TerminalShield::available()
{
	return buffer.remain();
}

int TerminalShield::readBytes(char *arr, int length)
{
	int count = 0;
	 	while (count < length) {
	    int c = read();
	    if (c < 0) break;
	    *arr++ = (char)c;
	    count++;
 	}
  return count;
}

void TerminalShield::processData()
{
	byte functionID = OneSheeld.getFunctionId();
	byte dataLength = OneSheeld.getArgumentLength(0);
	if(functionID == TERMINAL_READ)
	{
			for (int j=0; j<dataLength; j++)
			{
				buffer.push(OneSheeld.getArgumentData(0)[j]);
			}
	}
}
TerminalShield Terminal;