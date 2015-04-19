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

#include "utility/ShieldParent.h"

//Output Function ID
#define EMAIL_SEND 0x01
#define EMAIL_ATTACH_PICTURE	0x02

class EmailShieldClass : public ShieldParent
{

public:
  //Constructor
  EmailShieldClass() : ShieldParent(EMAIL_ID){};
	//Sender 
	void send(const char* ,const char*,const char* );
	void send(String , String ,String );
	void attachLastPicture(const char* ,const char*,const char*,byte =0);
  void attachLastPicture(String , String , String , byte =0);

private:
  
};

//Extern Object
extern EmailShieldClass Email;
#endif