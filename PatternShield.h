/*

  Project:       1Sheeld Library 
  File:          PatternShield.h
                 
  Version:       1.4

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.1

*/
#ifndef	PatternShield_h
#define PatternShield_h

#include "ShieldParent.h"

// Input Function ID
#define PATTERN_VALUE	0x01
#define MAX_PATTERN_SIZE 9


struct PatternNode{
	byte value;
	PatternNode(byte val):value(val){}
	PatternNode(){}
	byte getRow(){return value&0x0F;}
	byte getColumn(){return (value&0xF0)>>4;}
};

class PatternShield : public ShieldParent
{
public:
	//Constructor 
	PatternShield();
	PatternNode * getLastPattern();
	int getLastPatternSize();
	bool isNewPatternReceived();
	void setOnNewPattern(void (*)(PatternNode* ,int ));

private:
	int size;
	bool isNewPattern;
	bool isCallBackAssigned;
	PatternNode nodes[MAX_PATTERN_SIZE]; 

	void processData();
	void (*changeCallBack)(PatternNode *, int ); 
	
};

//Extern Object
extern PatternShield Pattern;
#endif