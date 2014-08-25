/*

  Project:       1Sheeld Library 
  File:          TerminalShield.h
                 
  Version:       3.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.8

*/

#ifndef TerminalShield_h
#define TerminalShield_h

#include "OneSheeldPrintln.h"
#include "CircularBuffer.h"
//Output Function ID's
#define TERMINAL_WRITE 0x01		
#define TERMINAL_PRINT 0x02
//Input Function ID
#define TERMINAL_READ  0x01


class TerminalShield : public PrintlnClass
{
public:
	TerminalShield();
	int available();
	char read();
	int readBytes(char *, int);
	void flush();
	
private:
	CircularBuffer<char,64> buffer;
	void processData();

	friend class OneSheeldClass;
};

extern TerminalShield Terminal;
#endif