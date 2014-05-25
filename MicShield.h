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

//Input Function ID 
#define MIC_VALUE 0x01

class MicShield
{
public:
	//Constructor
	MicShield();
	//Getter
	byte getValue();
	//setOnChange for Users Function
	void setOnValueChange(void (*)(byte));
private:
	//Reserve Variable
	byte value;
	//Boolean for the setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data  
	void processData();
	void (*changeCallBack)(byte);
	
	friend class OneSheeldClass;
};

//Extern Object
extern MicShield Mic;
#endif