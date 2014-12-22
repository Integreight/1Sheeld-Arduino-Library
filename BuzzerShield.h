/*

  Project:       1Sheeld Library 
  File:          BuzzerShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef BuzzerShield_h
#define BuzzerShield_h

//Ouput Functions ID's 
#define BUZZER_OFF 	0x00
#define BUZZER_ON 	0x01
#define BUZZER_SELECT_SHIELD	0x02
#define BUZZER_UNSELECT_SHIELD	0x03

//Input Fuinction ID
#define BUZZER_CHECK_SELECTED	0x01
//Parameter
#define BUZZER_SET 	0x01


class BuzzerShieldClass
{
public:
	//Constructor
	BuzzerShieldClass();
	//Setters
	void buzzOn();
	void buzzOff();
	//Selection
	void select();
	void unselect();
	//Set on when selected
	void setOnSelected(void(*)(void));

private:
	//Boolean for buzz check 
	bool buzzing;
	//Setter  
	void setValue(byte x);
	void processData();
	void (*selectedCallBack)(void);

	friend class OneSheeldClass;
};

//Extern Object
extern BuzzerShieldClass Buzzer;
#endif