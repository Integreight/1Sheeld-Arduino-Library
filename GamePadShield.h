#ifndef GamePadShield_h
#define GamePadShield_h

#define GAMEPAD_VALUE 0x01

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
	GamePadShield();
	bool isUpPressed();
	bool isDownPressed();
	bool isLeftPressed();
	bool isRightPressed();
	bool isOrangePressed();
	bool isRedPressed();
	bool isGreenPressed();
	bool isBluePressed();
	void setOnButtonChange(void (*)(bool , bool ,bool , bool ,bool , bool ,bool , bool ));
private:
	void processData();
	byte value;
	bool isCallBackAssigned;
	bool up ,down ,left ,right,orange ,red ,green, blue;
	void (*buttonChangeCallBack)(bool , bool ,bool , bool ,bool , bool ,bool , bool );
	friend class OneSheeldClass ;
};

extern GamePadShield GamePad;
#endif 