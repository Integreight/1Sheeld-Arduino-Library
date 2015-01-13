/*

  Project:       1Sheeld Library 
  File:          GamePadShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef GamePadShield_h
#define GamePadShield_h

//Output Function ID
#define GAMEPAD_SELECT_SHIELD	0xFE
#define GAMEPAD_UNSELECT_SHIELD	0xFD  
//Input Function ID
#define GAMEPAD_VALUE 0x01
#define GAMEPAD_CHECK_SELECTED	0xFF
//GamePad Bit Reference 
#define ORANGE_BIT 0
#define RED_BIT 1
#define GREEN_BIT 2 
#define BLUE_BIT 3 
#define UP_BIT 4
#define DOWN_BIT 5
#define LEFT_BIT 6
#define RIGHT_BIT 7



class GamePadShield
{
public:
	//Constructor
	GamePadShield();
	//Checker Functions
	bool isUpPressed();
	bool isDownPressed();
	bool isLeftPressed();
	bool isRightPressed();
	bool isOrangePressed();
	bool isRedPressed();
	bool isGreenPressed();
	bool isBluePressed();
	//Selection
	void select();
	void unselect();
	//setOnChange for Users Function
	void setOnButtonChange(void (*)(unsigned char , unsigned char ,unsigned char , unsigned char ,unsigned char ,unsigned char ,unsigned char ,unsigned char ));
	void setOnSelected(void (*)(void));
private:
	//Reserve Variables
	byte value;
	bool isCallBackAssigned;
	bool up ,down ,left ,right,orange ,red ,green, blue;
	//Process Input Data  
	void processData();
	void (*buttonChangeCallBack)(unsigned char , unsigned char ,unsigned char , unsigned char ,unsigned char ,unsigned char ,unsigned char ,unsigned char );
	void (*selectedCallBack)(void);
	friend class OneSheeldClass ;
};

//Extern Object
extern GamePadShield GamePad;
#endif 