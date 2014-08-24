#ifndef TerminalShield_h
#define TerminalShield_h

#include "OneSheeldPrintln.h"
#include "CircularBuffer.h"
//Output Function ID's
#define WRITE_TERMINAL 0x01		
#define PRINT_TERMINAL 0x02
#define DEC   10
//Input Function ID
#define READ  0x01


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