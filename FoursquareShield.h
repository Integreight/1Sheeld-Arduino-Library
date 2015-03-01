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

#include "ShieldParent.h"

//Output Function ID
#define FOURSQUARE_CHECK_IN 0x01

class FoursquareShieldClass : public ShieldParent
{
public:
	//Constructor
	FoursquareShieldClass() : ShieldParent(FOURSQUARE_ID){};
	//Sender
	void checkIn(const char* ,const char* );
	void checkIn(String , String );
private:

};

//Extern Object
extern FoursquareShieldClass Foursquare;
#endif