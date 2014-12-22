/*

  Project:       1Sheeld Library 
  File:          TerminalShield.cpp
                 
  Version:       1.2

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.9

*/

#include "OneSheeld.h"
#include "TerminalShield.h"

//Constructor
TerminalShield::TerminalShield():PrintlnClass(TERMINAL_ID,TERMINAL_WRITE,TERMINAL_PRINT)
{}

//Read from Android
char TerminalShield::read()
{
	if(buffer.remain()<=0)return -1;
	return buffer.pop();
}
//Flush buffer contents
void TerminalShield::flush()
{
	while(read()!=-1);
}
//Check Data avialable in Buffer
int TerminalShield::available()
{
	return buffer.remain();
}
//Read bytes from Buffer
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

void TerminalShield::select()
{
	OneSheeld.sendPacket(TERMINAL_ID,0,TERMINAL_SELECT_SHIELD,0);
}

void TerminalShield::unselect()
{
	OneSheeld.sendPacket(TERMINAL_ID,0,TERMINAL_UNSELECT_SHIELD,0);
}
//Terminal Incomming Data processing
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
	else if(functionID == TERMINAL_CHECK_SELECTED)
	{
		(*selectedCallBack)();
	}
}

void TerminalShield::setOnSelected(void (*userFunction)(void))
{
	selectedCallBack= userFunction;
}
//instantiating Object 
TerminalShield Terminal;