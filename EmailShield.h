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
#define EMAIL_SEND 0x01
#define EMAIL_ATTACH_PICTURE	0x02
#define EMAIL_SELECT_SHIELD 0xFE
#define EMAIL_UNSELECT_SHIELD 0xFD

//Input Function ID
#define EMAIL_CHECK_SELECTED  0xFF



class EmailShieldClass 
{

public:
	//Sender 
	void send(const char* ,const char*,const char* );
	void send(String , String ,String );
	void attachLastPicture(const char* ,const char*,const char*,byte =0);
  void attachLastPicture(String , String , String , byte =0);
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
extern EmailShieldClass Email;
#endif