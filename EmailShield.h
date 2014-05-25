/*

  Project:       1Sheeld Library 
  File:          EmailShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef EmailShield_h
#define EmailShield_h

//Output Function ID
#define SEND 0x01



class EmailShieldClass 
{

public:
	//Sender 
	void send(char* ,char*,char* );

private:

};

//Extern Object
extern EmailShieldClass Email;
#endif