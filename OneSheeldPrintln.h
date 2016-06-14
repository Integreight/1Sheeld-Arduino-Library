/*

  Project:       1Sheeld Library 
  File:          OneSheeldPrintln.h
                 
  Version:       1.2

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.9

*/

#ifndef PrintlnClass_h
#define PrintlnClass_h

#include "OneSheeldPrint.h"

class PrintlnClass: public PrintClass
{
public:
	PrintlnClass(byte, byte, byte);
	//Printing in new line 
	void println();
	void println(char);
	void println(int);
	void println(unsigned int);
	void println(long);
	void println(unsigned long);
	void println(const char *);
	void println(String);
	//Unsupported by Intel Galileo board and Arduino Due
	#if  !defined(ARDUINO_LINUX) && !defined(SAM3X8)
	void println(double , int = 3);
    #endif
};

#endif