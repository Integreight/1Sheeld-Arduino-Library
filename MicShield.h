/*

  Project:       1Sheeld Library 
  File:          MicShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef MicShield_h
#define MicShield_h

//Output Function ID
#define MIC_SELECT_SHIELD	0x01
#define MIC_UNSELECT_SHIELD	0x02

//Input Function ID 
#define MIC_VALUE 0x01
#define MIC_CHECK_SELECTED	0x02


class MicShield
{
public:
	//Constructor
	MicShield();
	//Getter
	byte getValue();
	//Selection
	void select();
	void unselect();
	//setOnChange for Users Function
	void setOnValueChange(void (*)(byte));
	//Set when Selected
	void setOnSelected(void (*)(void));
private:
	//Reserve Variable
	byte value;
	//Boolean for the setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data  
	void processData();
	void (*changeCallBack)(byte);
	void (*selectedCallBack)(void);
	
	friend class OneSheeldClass;
};

//Extern Object
extern MicShield Mic;
#endif