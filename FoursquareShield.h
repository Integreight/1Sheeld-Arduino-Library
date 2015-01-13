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
#define FOURSQUARE_CHECK_IN 0x01
#define FOURSQUARE_SELECT_SHIELD	0xFE
#define FOURSQUARE_UNSELECT_SHIELD	0xFD  

//Input Function ID
#define FOURSQUARE_CHECK_SELECTED	0xFF

class FoursquareShieldClass
{
public:
	//Sender
	void checkIn(const char* ,const char* );
	void checkIn(String , String );
	//Selection
	void select();
	void unselect();
	//Set On when selected
	void setOnSelected(void(*)(void));
private:
	void processData();
	void (*selectedCallBack)(void);

	friend class OneSheeldClass;

};

//Extern Object
extern FoursquareShieldClass Foursquare;
#endif