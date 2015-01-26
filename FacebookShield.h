/*

  Project:       1Sheeld Library 
  File:          FacebookShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef FacebookShield_h
#define FacebookShield_h

#include "ShieldParent.h"

//Output Functions ID's
#define FACEBOOK_UPDATE_STATUS 0x01  
#define FACEBOOK_POST_LAST_PIC 0x02

class FacebookShieldClass : public ShieldParent
{
public:
  //Constructor
  FacebookShieldClass() : ShieldParent(FACEBOOK_ID){};
	//Senders
	void post(const char* );
	void post(String );
	void postLastPicture(const char *,byte =0);
	void postLastPicture(String , byte);
  
private:

};

//Extern Object
extern FacebookShieldClass Facebook;
#endif