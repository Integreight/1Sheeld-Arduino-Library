/*

  Project:       1Sheeld Library 
  File:          PatternShield.h
                 
  Version:       3.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.8

*/

#ifndef PatternShield_h
#define PatternShield_h

#define PATTERN_VALUE 0x01



class PatternShield
{
public:
	PatternShield();
	char* getPattern();
	char patternLength();

private:
	char *patternData;
	char Length;
	void processData();
	friend class OneSheeldClass;


};

extern PatternShield Pattern;
#endif