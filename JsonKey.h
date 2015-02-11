/*

  Project:       1Sheeld Library 
  File:          JsonKey.h
                 
  Version:       1.4

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.1

*/
#ifndef JsonKey_h
#define JsonKey_h

#include "Arduino.h"

class JsonKey{
public:
  
  JsonKey(int );
  JsonKey(const char * );
  JsonKey(const JsonKey & old);
  bool isString();
  bool isNumber();
  
  const char * getString();
  int getNumber();

  ~JsonKey();
private:
  bool isText;
  int number;
  char * text;
};


#endif