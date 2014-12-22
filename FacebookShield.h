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
#define FACEBOOK_UPDATE_STATUS 0x01  
#define FACEBOOK_POST_LAST_PIC 0x02
#define FACEBOOK_SELECT_SHIELD 0x03
#define FACEBOOK_UNSELECT_SHIELD 0x04

//Input Function ID
#define FACEBOOK_CHECK_SELECTED 0x01

class FacebookShieldClass 
{
public:
	//Senders
	void post(const char* );
	void post(String );
	void postLastPicture(const char *,byte =0);
	void postLastPicture(String , byte);
  //Selection
  void select();
  void unselect();
  //Set on when selected
  void setOnSelected(void(*)(void));

private:
  void processData();
  void (*selectedCallBack)(void);

  friend class OneSheeldClass;


};

//Extern Object
extern FacebookShieldClass Facebook;
#endif