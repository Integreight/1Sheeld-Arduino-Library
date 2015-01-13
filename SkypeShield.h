/*

  Project:       1Sheeld Library 
  File:          SkypeShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef SkypeShield_h
#define SkypeShield_h

//Output Function ID's
#define SKYPE_CALL 		0x01
#define SKYPE_VIDEO_CALL  0x02
#define SKYPE_SELECT_SHIELD 0xFE
#define SKYPE_UNSELECT_SHIELD 0xFD

//Input Function ID
#define SKYPE_CHECK_SELECTED  0xFF

class SkypeShieldClass 
{

public:
	//Setters 
	void call(const char *);
	void call(String );
	void videoCall(const char *);	
	void videoCall(String );
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
extern SkypeShieldClass Skype;
#endif