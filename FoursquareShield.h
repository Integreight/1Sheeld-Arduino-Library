/*

  Project:       1Sheeld Library 
  File:          FoursquareShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef FoursquareShield_h
#define FoursquareShield_h


//Output Function ID
#define CHECK_IN 0x01

class FoursquareShieldClass
{
public:
	//Sender
	void checkIn(char* , char* );
private:

};

//Extern Object
extern FoursquareShieldClass Foursquare;
#endif