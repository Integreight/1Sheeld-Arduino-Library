/*

  Project:       1Sheeld Library 
  File:          LEDShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef LedShield_h
#define LedShield_h

//Output Functions ID's
#define LED_SET_HIGH  0x01
#define LED_SELECT_SHIELD 0xFE
#define LED_UNSELECT_SHIELD 0xFD
//Parameters
#define LED_SET_LOW   0x00
#define LED_SET_VALUE 0x01
//Input Function ID
#define LED_CHECK_SELECTED  0xFF


class LedShield
{
public:
	//Setters
	void setLow();
	void setHigh();
  //Selection 
  void select();
  void unselect();
  //Set On when Selected
  void setOnSelected(void (*)(void));
private:
	void setValue(byte );
  void processData();
  void (*selectedCallBack)(void);

  friend class OneSheeldClass;

};

//Extern Object
extern LedShield LED;
#endif