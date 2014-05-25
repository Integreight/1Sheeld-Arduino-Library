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
#define BUZZ_ON 	0x01
#define BUZZ_OFF 	0x00
#define SET_VALUE 	0x01

class BuzzerShieldClass
{
public:
	//Constructor
	BuzzerShieldClass();
	//Setters
	void buzzOn();
	void buzzOff();
private:
	//Boolean for buzz check 
	bool buzzing;
	//Setter  
	void setValue(byte x);

};

//Extern Object
extern BuzzerShieldClass Buzzer;
#endif