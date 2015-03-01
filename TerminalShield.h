/*

  Project:       1Sheeld Library 
  File:          TerminalShield.h
                 
  Version:       1.2

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.9

*/

#ifndef TerminalShield_h
#define TerminalShield_h

#include "ShieldParent.h"

#include "OneSheeldPrintln.h"
#include "CircularBuffer.h"

//Output Function ID's
#define TERMINAL_WRITE 0x01		
#define TERMINAL_PRINT 0x02

//Input Function ID
#define TERMINAL_READ  0x01

class TerminalShield : public PrintlnClass, public ShieldParent
{
public:
	//Constructor
	TerminalShield();
	//Checker
	int available();
	//Getter
	char read();
	//Getter
	int readBytes(char *, int);
	//Setter
	void flush();

private:
	//Instatiate Object from class CircularBuffer
	CircularBuffer<char,64> buffer;
	//Process Input data
	void processData();
};
//Extern Object
extern TerminalShield Terminal;
#endif