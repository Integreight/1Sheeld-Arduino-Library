#ifndef GamePadShield_h
#define GamePadShield_h

#define GAMEPAD_VALUE 0x01

#define A_BIT 0
#define B_BIT 1
#define C_BIT 2 
#define D_BIT 3 
#define UP_BIT 4
#define DOWN_BIT 5
#define LEFT_BIT 6
#define RIGHT_BIT 7



class GamePadShield
{
public:
	GamePadShield();
	bool isUpPressed();
	bool isDownPressed();
	bool isLeftPressed();
	bool isRightPressed();
	bool isAPressed();
	bool isBPressed();
	bool isCPressed();
	bool isDPressed();
	void processData();
private:
	byte value;
};

extern GamePadShield GamePad;
#endif 