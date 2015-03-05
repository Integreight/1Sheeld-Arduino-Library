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
	byte row;
	byte col;
	void setValue(byte val)
	{
		row=val&0x0F;
		col=(val&0xF0)>>4;
	}
	bool operator==(const PatternNode& other) 
	{
	    return (row==other.row)&&(col==other.col);
	}

	bool operator!=(const PatternNode& other)
	{
	  return !(*this == other);
	}

};

class PatternShield : public ShieldParent
{
public:
	//Constructor 
	PatternShield();
	PatternNode * getLastPattern();
	int getLastPatternLength();
	bool isNewPatternReceived();
	void setOnNewPattern(void (*)(PatternNode[] ,int ));

private:
	int length;
	bool isNewPattern;
	bool isCallBackAssigned;
	PatternNode nodes[MAX_PATTERN_SIZE]; 

	void processData();
	void (*changeCallBack)(PatternNode[], int ); 
	
};

//Extern Object
extern PatternShield Pattern;
#endif