#ifndef GamePadShield_h
#define GamePadShield_h

#define GAMEPAD_VALUE 0x01

//wroking on the GamePad buttons Bitwise 
#define A 0
#define B 1
#define C 2 
#define D 3 
#define UP 4
#define DOWN 5
#define LEFT 6
#define RIGHT 7


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