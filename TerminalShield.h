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

#include "OneSheeldPrintln.h"
#include "CircularBuffer.h"

//Output Function ID's
#define TERMINAL_WRITE 0x01		
#define TERMINAL_PRINT 0x02
#define TERMINAL_SELECT_SHIELD	0xFE
#define TERMINAL_UNSELECT_SHIELD	0xFD
//Input Function ID
#define TERMINAL_READ  0x01
#define TERMINAL_CHECK_SELECTED	0xFF


class TerminalShield : public PrintlnClass
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
	//Selections
	void select();
	void unselect();
	//check if selected
	void setOnSelected(void (*)(void));
	
private:
	//Instatiate Object from class CircularBuffer
	CircularBuffer<char,64> buffer;
	//Process Input data
	void processData();
	void (*selectedCallBack)(void);

	friend class OneSheeldClass;
};
//Extern Object
extern TerminalShield Terminal;
#endif