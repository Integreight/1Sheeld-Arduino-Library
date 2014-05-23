#ifndef ToggleButtonShield_h
#define ToggleButtonShield_h

#define TOGGLE_VALUE 0x01



class ToggleButtonShield
{
public:
	ToggleButtonShield();
	bool isPressed();
	void setOnButtonStatusChange(void (*userFunction)(bool));
private:
	void processData();
	byte value;
	bool isCallBackAssigned;
	void (*changeCallBack)(bool);
	friend class OneSheeldClass;
};

extern ToggleButtonShield ToggleButton;
#endif