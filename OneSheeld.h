/*
  OneSheeld.h - OneSheeld library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/

#ifndef OneSheeld_h
#define OneSheeld_h

// start and end of the packet sent 
#define STX 0x02
#define ETX 0x03
// for general data sending 
#define GENERAL_DATA 0x29
#define NOT_FUNCTION 0x00

class OneSheeldClass 
{
public:
OneSheeldClass();
void begin(long baudRate);
void write(char shieldID,char functionCommand, char* data);
void write(char* data);

private:


};
// instantiate object for users
extern OneSheeldClass OneSheeld;
#endif