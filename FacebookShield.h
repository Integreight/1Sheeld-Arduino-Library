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

//Output Functions ID's
#define UPDATE_STATUS 0x01  
#define SEND_MESSAGE  0x02
#define POST_PICTURE  0x03
#define POST_LAST_PIC 0x04

class FacebookShieldClass 
{
public:
	//Senders
	void post(const char* );
	void sendMessage(char *,char* );
	void postPicture(char*,char*);
	void postLastPicture();
private:



};

//Extern Object
extern FacebookShieldClass Facebook;
#endif